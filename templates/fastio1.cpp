#include <sys/mman.h>
#include <sys/stat.h>
#if defined(__GNUC__) || defined(__clang__) // Modified to fit C++14
#define LIKELY(x) (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif
namespace IO
{
    using i64 = long long;
    using u8 = unsigned char;
    using u16 = unsigned short;
    using u32 = unsigned;
    using u64 = unsigned long long;
    constexpr std::size_t buf_def_size = 262144;
    constexpr std::size_t buf_flush_threshold = 32;
    constexpr std::size_t string_copy_threshold = 512;
    constexpr u64 E16 = 1e16, E12 = 1e12, E8 = 1e8, E4 = 1e4;
    struct _io_t
    {
        u8 t_i[1 << 15];
        int t_o[10000];
        _io_t()
        {
            std::fill(t_i, t_i + (1 << 15), u8(-1));
            for (int i = 0; i < 10; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    t_i[0x3030 + 256 * j + i] = j + 10 * i;
                }
            }
            for (int e0 = (48 << 0), j = 0; e0 < (58 << 0); e0 += (1 << 0))
            {
                for (int e1 = (48 << 8); e1 < (58 << 8); e1 += (1 << 8))
                {
                    for (int e2 = (48 << 16); e2 < (58 << 16); e2 += (1 << 16))
                    {
                        for (int e3 = (48 << 24); e3 < (58 << 24); e3 += (1 << 24))
                        {
                            t_o[j++] = e0 ^ e1 ^ e2 ^ e3;
                        }
                    }
                }
            }
        }
        void get(char *s, u32 p) const { *((int *)s) = t_o[p]; }
    };
    static const _io_t _iot = {}; // Modified to fit C++14
    struct Qinf
    {
        explicit Qinf(FILE *fi) : f(fi)
        {
            auto fd = fileno(f);
            fstat(fd, &Fl);
            bg = (char *)mmap(0, Fl.st_size + 4, PROT_READ, MAP_PRIVATE, fd, 0);
            p = bg, ed = bg + Fl.st_size;
            madvise(bg, Fl.st_size + 4, MADV_SEQUENTIAL);
        }
        ~Qinf() { munmap(bg, Fl.st_size + 4); }
        template <typename T>
        typename std::enable_if<std::is_unsigned<T>::value, Qinf &>::type operator>>(T &x) // Modified to fit C++14
        {
            skip_space();
            x = *p++ - '0';
            for (;;)
            {
                T y = _iot.t_i[*reinterpret_cast<u16 *>(p)];
                if (y > 99)
                {
                    break;
                }
                x = x * 100 + y, p += 2;
            }
            if (*p > ' ')
            {
                x = x * 10 + (*p++ & 15);
            }
            return *this;
        }
        template <typename T>
        typename std::enable_if<std::is_signed<T>::value, Qinf &>::type operator>>(T &x) // Modified to fit C++14
        {
            skip_space();
            int sign;
            p += (sign = (*p == '-'));
            x = *p++ - '0';
            for (;;)
            {
                u32 y = _iot.t_i[*reinterpret_cast<u16 *>(p)];
                if (y > 99)
                {
                    break;
                }
                x = x * 100 + y, p += 2;
            }
            if (*p > ' ')
            {
                x = x * 10 + (*p++ & 15);
            }
            x = (sign ? -x : x);
            return *this;
        }
        std::string read_token() // Modified to fit C++14
        {
            skip_space();
            const char *bg0 = p;
            while (*p > ' ')
            {
                ++p;
            }
            return std::string(bg0, p - bg0);
        }
        // Appended to fit C++14
        struct TIE
        {
            void sync_with_stdio(bool) {}
        };
        TIE *tie(int) { return new TIE; }

    private:
        void skip_space()
        {
            while (*p <= ' ')
            {
                ++p;
            }
        }
        FILE *f;
        char *bg, *ed, *p;
        struct stat Fl;
    };
    struct Qoutf
    {
        explicit Qoutf(FILE *fi, std::size_t sz = buf_def_size) : f(fi), bg(new char[sz]), ed(bg + sz - buf_flush_threshold), p(bg) {}
        ~Qoutf()
        {
            flush();
            delete[] bg;
        }
        void flush() { fwrite_unlocked(bg, 1, p - bg, f), p = bg; }
        Qoutf &operator<<(u32 x)
        {
            wt_u32(x);
            return *this;
        }
        Qoutf &operator<<(u64 x)
        {
            wt_u64(x);
            return *this;
        }
        Qoutf &operator<<(int x)
        {
            x < 0 ? (*p++ = '-', wt_u32(-x)) : wt_u32(x);
            return *this;
        }
        Qoutf &operator<<(i64 x)
        {
            x < 0 ? (*p++ = '-', wt_u64(-x)) : wt_u64(x);
            return *this;
        }
        Qoutf &operator<<(char ch)
        {
            *p++ = ch;
            return *this;
        }
        Qoutf &operator<<(const std::string &s) // Modified to fit C++14
        {
            if (s.size() >= string_copy_threshold)
            {
                flush(), fwrite_unlocked(s.data(), 1, s.size(), f);
            }
            else
            {
                if (UNLIKELY((p + s.size()) > ed)) // Modified to fit C++14
                {
                    flush();
                }
                memcpy(p, s.data(), s.size()), p += s.size();
            }
            return *this;
        }
        void setf(int) {}
        void precision(int) {}

    private:
        void wt_u32(u32 x)
        {
            if (x >= E8)
            {
                put2(x / E8), x %= E8, putb(x / E4), putb(x % E4);
            }
            else if (x >= E4)
            {
                put4(x / E4), putb(x % E4);
            }
            else
            {
                put4(x);
            }
            chk();
        }
        void wt_u64(u64 x)
        {
            if (x >= E8)
            {
                u64 q0 = x / E8, r0 = x % E8;
                if (x >= E16)
                {
                    u64 q1 = q0 / E8, r1 = q0 % E8;
                    put4(q1), putb(r1 / E4), putb(r1 % E4);
                }
                else if (x >= E12)
                {
                    put4(q0 / E4), putb(q0 % E4);
                }
                else
                {
                    put4(q0);
                }
                putb(r0 / E4), putb(r0 % E4);
            }
            else
            {
                if (x >= E4)
                {
                    put4(x / E4), putb(x % E4);
                }
                else
                {
                    put4(x);
                }
            }
            chk();
        }
        void putb(u32 x) { _iot.get(p, x), p += 4; }
        void put4(u32 x)
        {
            if (x > 99)
            {
                if (x > 999)
                {
                    putb(x);
                }
                else
                {
                    _iot.get(p, x * 10), p += 3;
                }
            }
            else
            {
                put2(x);
            }
        }
        void put2(u32 x)
        {
            if (x > 9)
            {
                _iot.get(p, x * 100), p += 2;
            }
            else
            {
                *p++ = x + '0';
            }
        }
        void chk()
        {
            if (UNLIKELY(p > ed)) // Modified to fit C++14
            {
                flush();
            }
        }
        FILE *f;
        char *bg, *ed, *p;
    };
}
// IO::Qinf qin(fopen("name.in", "r"));
// IO::Qoutf qout(fopen("name.out", "w"));
IO::Qinf qin(stdin);
IO::Qoutf qout(stdout);
#define cin qin
#define cout qout