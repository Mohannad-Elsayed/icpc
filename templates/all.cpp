#ifndef LIBRARIES
#ifdef EVAL
#define ONLINE_JUDGE
#endif
#pragma GCC diagnostic ignored "-Wsign-compare"
#if __GNUC__ >= 6 && defined(ONLINE_JUDGE)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx512vl")
#endif
#define LIBRARIES
#include __FILE__
#undef LIBRARIES
#define INCLUDE_UTILITY
#ifdef INCLUDE_NUMERIC
#define INCLUDE_MODINT
#endif
#ifdef INCLUDE_HASH
#define INCLUDE_RANDOM
#endif
#ifdef HEURISTICS
#define INCLUDE_TIMER
#endif
#include <bits/stdc++.h>
namespace atcoder {}

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using ull = unsigned long long;
using fl = float;
using db = double;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using vi = std::vector<int>;
using vll = std::vector<long long>;
using vvi = std::vector<std::vector<int>>;
using vvll = std::vector<std::vector<long long>>;
using vvvi = std::vector<std::vector<std::vector<int>>>;
using vvvll = std::vector<std::vector<std::vector<long long>>>;
using vvvvi = std::vector<std::vector<std::vector<std::vector<int>>>>;
using vvvvll = std::vector<std::vector<std::vector<std::vector<long long>>>>;
using vb = std::basic_string<bool>;
using vvb = std::vector<std::basic_string<bool>>;
using vvvb = std::vector<std::vector<std::basic_string<bool>>>;
using vstr = std::vector<std::string>;
using vvstr = std::vector<std::vector<std::string>>;
using vvvstr = std::vector<std::vector<std::vector<std::string>>>;
using vpii = std::vector<std::pair<int, int>>;
using vpll = std::vector<std::pair<long long, long long>>;
using vvpii = std::vector<std::vector<std::pair<int, int>>>;
using vvpll = std::vector<std::vector<std::pair<long long, long long>>>;
using vvvpii = std::vector<std::vector<std::vector<std::pair<int, int>>>>;
using vvvpll = std::vector<std::vector<std::vector<std::pair<long long, long long>>>>;
using seti = std::set<int>;
using setll = std::set<long long>;
using vseti = std::vector<std::set<int>>;
using vsetll = std::vector<std::set<long long>>;
using vvseti = std::vector<std::vector<std::set<int>>>;
using vvsetll = std::vector<std::vector<std::set<long long>>>;
using setpii = std::set<std::pair<int, int>>;
using setpll = std::set<std::pair<long long, long long>>;
using vsetpii = std::vector<std::set<std::pair<int, int>>>;
using vsetpll = std::vector<std::set<std::pair<long long, long long>>>;
using mapii = std::map<int, int>;
using mapll = std::map<long long, long long>;
using vmapii = std::vector<std::map<int, int>>;
using vmapll = std::vector<std::map<long long, long long>>;
using vvmapii = std::vector<std::vector<std::map<int, int>>>;
using vvmapll = std::vector<std::vector<std::map<long long, long long>>>;
template<class T> using vec = std::vector<T>;
template<class T> using vec2 = std::vector<std::vector<T>>;
template<class T> using vec3 = std::vector<std::vector<std::vector<T>>>;
template<class T> using vec4 = std::vector<std::vector<std::vector<std::vector<T>>>>;
template<class T> using maxheap = std::priority_queue<T, std::vector<T>, std::less<T>>;
template<class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define ALL(V)       std::begin(V), std::end(V)
#define RALL(V)      std::rbegin(V), std::rend(V)
#define ALLMID(V, n) std::begin(V), std::next(std::begin(V), n), std::end(V)
#define MIN(T)       (std::numeric_limits<T>::lowest())
#define MAX(T)       (std::numeric_limits<T>::max())
#define EXPR(...)    (([&]() __VA_ARGS__)())
// clang-format off
#define RET_WITH(...) ({ __VA_ARGS__; return; })
#define RETV_WITH(val, ...) ({ __VA_ARGS__; return val; })
#define BRK_WITH(...) ({ __VA_ARGS__; break; })
#define CTN_WITH(...) ({ __VA_ARGS__; continue; })
#define EXT_WITH(...) ({ __VA_ARGS__; std::exit(0); })
#define ARGS(...) __VA_ARGS__
#define LAMBDA(args, ...) [&](auto&&... LAMBDA_args){ auto [args] = std::forward_as_tuple(LAMBDA_args...); return (__VA_ARGS__); }
// clang-format on

#if __cplusplus >= 202001U
#define REP_VAR_NAME(n)                   REP_VAR_NAME_(n)
#define REP_VAR_NAME_(n)                  variable_for_loop_##n
#define REP_OVERLOAD4(a, b, c, d, e, ...) e

#define REP1(N)              for ([[maybe_unused]] const auto REP_VAR_NAME(__LINE__) : std::views::iota(std::decay_t<decltype(N)>{}, N))
#define REP2(i, N)           for ([[maybe_unused]] const auto i : std::views::iota(std::decay_t<decltype(N)>{}, N))
#define REP3(i, A, B)        for ([[maybe_unused]] const auto i : std::views::iota(static_cast<std::common_type_t<decltype(A), decltype(B)>>(A), static_cast<std::common_type_t<decltype(A), decltype(B)>>(B)))
#define REP4(i, A, B, C)     for ([[maybe_unused]] std::common_type_t<decltype(A), decltype(B)> i = (A); std::less<decltype(i)>{}(i, (B)); i += (C))
#define REP1_REV(N)          for ([[maybe_unused]] const auto REP_VAR_NAME(__LINE__) : std::views::iota(std::decay_t<decltype(N)>{}, N) | std::views::reverse)
#define REP2_REV(i, N)       for ([[maybe_unused]] const auto i : std::views::iota(std::decay_t<decltype(N)>{}, N) | std::views::reverse)
#define REP3_REV(i, A, B)    for ([[maybe_unused]] const auto i : std::views::iota(static_cast<std::common_type_t<decltype(A), decltype(B)>>(A), static_cast<std::common_type_t<decltype(A), decltype(B)>>(B)) | std::views::reverse)
#define REP4_REV(i, A, B, C) for ([[maybe_unused]] std::common_type_t<decltype(A), decltype(B)> i = (B) -1; std::less<decltype(i)>{}((A) -1, i); i -= (C))
#define rep(...)             REP_OVERLOAD4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define rrep(...)            REP_OVERLOAD4(__VA_ARGS__, REP4_REV, REP3_REV, REP2_REV, REP1_REV)(__VA_ARGS__)
#if __GNUC__ >= 12
#define repin(T, i, N) for ([[maybe_unused]] const auto i : std::views::istream<std::decay_t<T>>(std::cin) | std::views::take(N))
#endif
#else
#define rep(i, N)       for ([[maybe_unused]] auto i = std::decay_t<decltype(N)>{ 0 }; i != (N); ++i)
#define rrep(i, N)      for ([[maybe_unused]] auto i = (N) -1; i != -1; --i)
#define range(i, A, B)  for ([[maybe_unused]] auto i = (A); i != (B); ++i)
#define rrange(i, A, B) for ([[maybe_unused]] auto i = (B) -1; i != (A) -1; --i)
#endif

constexpr int inf32 = 1 << 29;
constexpr unsigned int infu32 = 1u << 30;
constexpr long long inf64 = 1ll << 61;
constexpr unsigned long long infu64 = 1ull << 62;
constexpr int alphabet = 26;

#if defined(INCLUDE_UTILITY) || defined(INCLUDE_ALL)
template<class T> void input(T& v) {
    for (auto& x : v) std::cin >> x;
}
template<class T> void output(const T& v, char c = ' ') {
    for (const auto& x : v) std::cout << x << c;
    std::cout << '\n';
}
template<class T, class U> void input(std::pair<T, U>& p) {
    std::cin >> p.first >> p.second;
}
template<class T, class U> void output(const std::pair<T, U>& p) {
    std::cout << p.first << ' ' << p.second << '\n';
}
void flush() {
    std::cout << std::flush;
}

void Yes() {
    puts("Yes");
}
void No() {
    puts("No");
}
void Answer(bool f) {
    puts(f ? "Yes" : "No");
}

class fprec {
    int d;
public:
    fprec(int d_) : d(d_) {}
    template<class T> friend auto& operator<<(T& os, fprec fp) {
        os << std::fixed << std::setprecision(fp.d);
        return os;
    }
};

template<class T> constexpr T umod(const T& V, const T& N) {
    if (V < 0) return (N + V % N) % N;
    return V % N;
}
template<class T> constexpr T powi(const T& x, unsigned long long e) {
    T res = 1, pow = x;
    while (e != 0) {
        if (e & 1) res *= pow;
        pow *= pow;
        e >>= 1;
    }
    return res;
}
template<class T> constexpr T powmod(const T& x, unsigned long long e, const T& mod) {
    T res = 1, pow = x;
    while (e != 0) {
        if (e & 1) res = (res * pow) % mod;
        pow = (pow * pow) % mod;
        e >>= 1;
    }
    return res;
}
template<class T, class U> constexpr bool chmax(T& a, const U& b) noexcept {
    if (a < b) return a = b, true;
    else return false;
}
template<class T, class U> constexpr bool chmin(T& a, const U& b) noexcept {
    if (a > b) return a = b, true;
    else return false;
}
template<class T> constexpr T divceil(const T& a, const T& b) noexcept {
    return (a + b - 1) / b;
}
#if __GNUC__ >= 12
template<class T, size_t n, size_t idx> constexpr auto make_vec_impl(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec_impl<T, n, idx + 1>(d, init));
    else return init;
}
template<class T, size_t n> constexpr auto make_vec(const size_t (&d)[n], const T& init = T()) noexcept {
    return make_vec_impl<T, n, 0>(d, init);
}
#endif
template<class T> void make_unique(T& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
template<class T> constexpr T reversed(const T& x) {
    T res = x;
    std::reverse(std::begin(res), std::end(res));
    return res;
}
template<std::ranges::range T, class U> constexpr int find_loc(const T& x, const U& t) {
    int cnt = 0;
    for (const auto& y : x) {
        if (t == y) return cnt;
        ++cnt;
    }
    return -1;
}
template<std::ranges::range T> constexpr auto unique_element(const T& x) {
    using U = std::decay_t<decltype(std::ranges::cbegin(x))>;
    std::map<U, size_t, decltype([](const U& a, const U& b) { return *a < *b; })> m;
    for (U itr = std::ranges::cbegin(x), sen = std::ranges::cend(x); itr != sen; ++itr) ++m[itr];
    for (const auto& [k, v] : m)
        if (v == 1) return k;
    return std::ranges::cend(x);
}

template<class T> constexpr bool inr(const T& l, const T& x, const T& r) {
    return l <= x && x < r;
}
#if __GNUC__ >= 12
template<size_t N> struct ParseInput {
    constexpr ParseInput(const char (&s)[N]) {
        for (size_t i = 0; i < N; i++) buf[i] = s[i];
    }
    char buf[N];
    constexpr size_t length() const { return N - 1; }
    constexpr char operator[](size_t n) const { return buf[n]; }
};
template<ParseInput s> consteval auto parse128() {
    constexpr bool valid = [&]() constexpr {
        for (size_t i = 0; i != s.length(); ++i) {
            if (s[i] == 'u' || s[i] == 'U') return i == s.length() - 1;
            if (!(s[i] >= '0' && s[i] <= '9')) return false;
        }
        return true;
    }();
    static_assert(valid, "parse128 / Contains invalid character.");
    constexpr bool us = (s[s.length() - 1] == 'u' || s[s.length() - 1] == 'U');
    constexpr int len = s.length() - us;
    static_assert(len <= 39, "parse128 / The value is too large.");
    constexpr bool larger127 = [&]() constexpr {
        if (len < 39) return false;
        const char* li = "170141183460469231731687303715884105727";
        for (int i = 0; i != len; ++i) {
            if (s[i] < li[i]) return false;
            if (s[i] > li[i]) return true;
        }
        return true;
    }();
    constexpr bool larger128 = [&]() constexpr {
        if (!larger127) return false;
        const char* li = "340282366920938463463374607431768211456";
        for (int i = 0; i != len; ++i) {
            if (s[i] < li[i]) return false;
            if (s[i] > li[i]) return true;
        }
        return true;
    }();
    static_assert(!larger128, "parse128 / The value is too large.");
    if constexpr (us || larger127) {
        __uint128_t res = 0;
        for (int i = 0; i != len; ++i) {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    } else {
        __int128_t res = 0;
        for (int i = 0; i != len; ++i) {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    }
}
#endif

#if __GNUC__ >= 12
class bitwise_search {
    size_t n;
public:
    constexpr bitwise_search(size_t sz) : n(sz) {}
    class end_iterator {};
    class iterator {
        friend class bitwise_search;
        size_t n, bit = 0;
        constexpr iterator(size_t sz) : n(sz) {}
    public:
        constexpr void operator++() { ++bit; }
        constexpr std::basic_string<bool> operator*() const {
            std::basic_string<bool> res(n, false);
            for (size_t copy = bit, i = 0; copy != 0; copy >>= 1, ++i) res[i] = copy & 1;
            return res;
        }
        constexpr bool operator!=(end_iterator) const { return bit != (1ull << n); }
    };
    constexpr iterator begin() { return iterator(n); }
    constexpr end_iterator end() { return end_iterator(); }
};
class permutation_search {
    size_t n;
public:
    constexpr permutation_search(size_t sz) : n(sz) {}
    class end_iterator {};
    class iterator {
        friend class permutation_search;
        std::vector<size_t> p;
        bool f = true;
        constexpr iterator(size_t sz) : p(sz) { std::iota(p.begin(), p.end(), 0); }
    public:
        constexpr void operator++() { f = std::next_permutation(p.begin(), p.end()); }
        constexpr std::vector<size_t> operator*() const { return p; }
        constexpr bool operator!=(end_iterator) const { return f; }
    };
    constexpr iterator begin() { return iterator(n); }
    constexpr end_iterator end() { return end_iterator(); }
};
class combination_search {
    size_t n, b;
public:
    constexpr combination_search(size_t sz, size_t bound) : n(sz), b(bound) {}
    class end_iterator {};
    class iterator {
        friend class combination_search;
        std::vector<size_t> p;
        size_t b;
        bool f = true;
        constexpr iterator(size_t sz, size_t bound) : p(sz), b(bound) { std::fill(p.end() - (sz - b), p.end(), 1); }
    public:
        constexpr void operator++() { f = std::next_permutation(p.begin(), p.end()); }
        constexpr std::vector<size_t> operator*() const {
            std::vector<size_t> res;
            res.reserve(b);
            for (size_t i = 0, sz = p.size(); i < sz; ++i)
                if (!p[i]) res.push_back(i);
            return res;
        }
        constexpr bool operator!=(end_iterator) const { return f; }
    };
    constexpr iterator begin() { return iterator(n, b); }
    constexpr end_iterator end() { return end_iterator(); }
};
#endif
#endif

#if defined(INCLUDE_CONSTEXPRCOUNTER) || defined(INCLUDE_ALL)
template<auto Id> struct ConstexprCounter {
    using tag = ConstexprCounter;
    struct generator {
        friend consteval auto is_defined(tag) { return true; }
    };
#pragma GCC diagnostic ignored "-Wnon-template-friend"
    friend consteval auto is_defined(tag);
#pragma GCC diagnostic warning "-Wnon-template-friend"
    template<typename Tag = tag, auto = is_defined(Tag{})> static consteval auto exists(auto) { return true; }
    static consteval auto exists(...) { return generator(), false; }
};
template<auto Id = int{}, typename = decltype([] {})> consteval auto UniqueID() {
    if constexpr (!ConstexprCounter<Id>::exists(Id)) return Id;
    else return UniqueID<Id + 1>();
}
#endif

#if defined(INCLUDE_ALLOCATOR) || defined(INCLUDE_ALL)
template<class T> class UniqueAllocator {
public:
    using value_type = T;
    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using is_always_equal = std::false_type;

private:
    std::vector<std::unique_ptr<T[]>> memory = []() {
        std::vector<std::unique_ptr<T[]>> res;
        res.emplace_back(new T[16]);
        return res;
    }();
    std::vector<T*> erased;
    ptrdiff_t cur = 0, max_length = 16;

public:
    constexpr UniqueAllocator() noexcept {}
    constexpr UniqueAllocator(const UniqueAllocator&) noexcept {}
    template<class U> constexpr UniqueAllocator(const UniqueAllocator<U>&) noexcept {}
    constexpr UniqueAllocator& operator=(const UniqueAllocator&) = default;
    constexpr UniqueAllocator& operator=(UniqueAllocator&&) = default;
    friend constexpr bool operator==(const UniqueAllocator&, const UniqueAllocator&) { return false; }
    friend constexpr bool operator!=(const UniqueAllocator&, const UniqueAllocator&) { return true; }
    [[nodiscard]] constexpr T* allocate([[maybe_unused]] size_type n) {
#ifndef ONLINE_JUDGE
        assert(n == 1);
#endif
        if (!erased.empty()) {
            T* res = erased.back();
            erased.pop_back();
            return res;
        }
        if (cur == max_length) {
            cur = 0, max_length = 16ll * (1ll << memory.size());
            memory.emplace_back(new T[max_length]);
        }
        return memory.back().get() + (cur++);
    }
    constexpr void deallocate(T* p, [[maybe_unused]] size_type n) {
#ifndef ONLINE_JUDGE
        assert(n == 1);
#endif
        erased.push_back(p);
    }
};
#endif

#if defined(INCLUDE_FASTIO)
#include <unistd.h>
#include <immintrin.h>
// Thanks for https://zenn.dev/mizar/articles/fc87d667153080
class FastIstream : public std::ios_base {
    constexpr static int buffersize = (1 << 18) - 1;
    char buffer[buffersize + 1];
    char* cur = buffer;
    char* eof = buffer;
    inline void reload(ptrdiff_t w) {
        if (eof - w < cur) [[unlikely]] {
            if (eof == buffer + buffersize) [[likely]] {
                ptrdiff_t rem = eof - cur;
                std::memcpy(buffer, cur, rem);
                *(eof = buffer + rem + read(0, buffer + rem, buffersize - rem)) = '\0';
                cur = buffer;
            } else if (eof <= cur) {
                *(eof = buffer + read(0, buffer, buffersize)) = '\0';
                cur = buffer;
            }
        }
    }
public:
    FastIstream& operator>>(bool& n) {
        reload(2);
        n = *cur == '1';
        cur += 2;
        return *this;
    }
    FastIstream& operator>>(short& n) {
        reload(8);
        short neg = (*cur == '-') * -2 + 1;
        cur += neg == -1;
        uint64_t tmp = *(uint64_t*) cur ^ 0x3030303030303030u;
        int clz = std::countl_zero((tmp & 0x1010101010101010u) & (-(tmp & 0x1010101010101010u))) + 5;
        cur += (72 - clz) >> 3;
        tmp = ((tmp << clz) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
        tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
        n = (short) ((tmp * 0x271000000001ull) >> 32) * neg;
        return *this;
    }
    FastIstream& operator>>(unsigned short& n) {
        reload(8);
        uint64_t tmp = *(uint64_t*) cur ^ 0x3030303030303030u;
        int clz = std::countl_zero((tmp & 0x1010101010101010u) & (-(tmp & 0x1010101010101010u))) + 5;
        cur += (72 - clz) >> 3;
        tmp = ((tmp << clz) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
        tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
        n = (unsigned short) ((tmp * 0x271000000001ull) >> 32);
        return *this;
    }
    FastIstream& operator>>(unsigned int& n) {
        reload(16);
        uint64_t tmp = *(uint64_t*) cur ^ 0x3030303030303030u, tmp2 = tmp & 0x1010101010101010u;
        if (tmp2) {
            int clz = std::countl_zero(tmp2 & -tmp2) + 5;
            cur += (72 - clz) >> 3;
            tmp = ((tmp << clz) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
            tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
            n = (unsigned) ((tmp * 0x271000000001ull) >> 32);
        } else {
            cur += 8;
            tmp = (tmp * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
            tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
            n = (unsigned) ((tmp * 0x271000000001ull) >> 32);
            if (char c = *(cur++); c >= '0') {
                n = 10 * n + (c - '0');
                if ((c = *(cur++)) >= '0') n = 10 * n + (c - '0'), ++cur;
            }
        }
        return *this;
    }
    FastIstream& operator>>(int& n) {
        reload(16);
        int neg = (*cur == '-') * -2 + 1;
        cur += neg == -1;
        uint64_t tmp = *(uint64_t*) cur ^ 0x3030303030303030u, tmp2 = tmp & 0x1010101010101010u;
        if (tmp2) {
            int clz = std::countl_zero(tmp2 & -tmp2) + 5;
            cur += (72 - clz) >> 3;
            tmp = ((tmp << clz) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
            tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
            n = (int) ((tmp * 0x271000000001ull) >> 32);
        } else {
            cur += 8;
            tmp = (tmp * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull;
            tmp = (tmp * 0x640001ull) >> 16 & 0x0000ffff0000ffffull;
            n = (int) ((tmp * 0x271000000001ull) >> 32);
            if (char c = *(cur++); c >= '0') {
                n = 10 * n + (c - '0');
                if ((c = *(cur++)) >= '0') n = 10 * n + (c - '0'), ++cur;
            }
        }
        n *= neg;
        return *this;
    }
    FastIstream& operator>>(unsigned long long& n) {
        reload(32);
#ifndef __AVX512VL__
        n = 0;
        while (*cur >= '0') n = 10 * n + (*(cur++) - '0');
        ++cur;
#else
        unsigned long long tmp[3], tmp2[3];
        std::memcpy(tmp, cur, 24);
        int width;
        if ((tmp2[0] = (tmp[0] ^= 0x3030303030303030) & 0x1010101010101010)) [[unlikely]] {
            width = std::countr_zero(tmp2[0]) - 4;
            n = ((((((tmp[0] << (64 - width)) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull) * 0x640001ull) >> 16 & 0x0000ffff0000ffffull) * 0x271000000001ull) >> 32;
            cur += (width >> 3) + 1;
        } else {
            __m256i tmp3;
            if ((tmp2[1] = (tmp[1] ^= 0x3030303030303030) & 0x1010101010101010)) [[unlikely]] {
                width = 60 + std::countr_zero(tmp2[1]);
                if (width == 64) [[unlikely]]
                    tmp3 = _mm256_setr_epi64x(0, 0, 0, tmp[0]);
                else tmp3 = _mm256_setr_epi64x(0, 0, tmp[0] << (128 - width), tmp[1] << (128 - width) | tmp[0] >> (width - 64));
            } else {
                width = 124 + std::countr_zero((tmp[2] ^= 0x3030303030303030) & 0x1010101010101010);
                if (width == 128) [[unlikely]]
                    tmp3 = _mm256_setr_epi64x(0, 0, tmp[0], tmp[1]);
                else tmp3 = _mm256_setr_epi64x(0, tmp[0] << (192 - width), tmp[1] << (192 - width) | tmp[0] >> (width - 128), tmp[2] << (192 - width) | tmp[1] >> (width - 128));
            }
            cur += (width >> 3) + 1;
            alignas(32) unsigned long long res[4];
            _mm256_store_epi64(res, _mm256_srli_epi64(_mm256_mullo_epi64(_mm256_srli_epi32(_mm256_mullo_epi32(_mm256_srli_epi16(_mm256_mullo_epi16(_mm256_and_si256(tmp3, _mm256_set1_epi8(0x0f)), _mm256_set1_epi16(0xa01)), 8), _mm256_set1_epi32(0x640001)), 16), _mm256_set1_epi64x(0x271000000001)), 32));
            n = res[1] * 10000000000000000 + res[2] * 100000000 + res[3];
        }
#endif
        return *this;
    }
    FastIstream& operator>>(long long& n) {
        reload(32);
        long long neg = (*cur == '-') * -2 + 1;
        cur += neg == -1;
#ifndef __AVX512VL__
        n = 0;
        while (*cur >= '0') n = 10 * n + (*(cur++) - '0');
        ++cur;
        n *= neg;
#else
        unsigned long long tmp[3], tmp2[3];
        std::memcpy(tmp, cur, 24);
        int width;
        if ((tmp2[0] = (tmp[0] ^= 0x3030303030303030) & 0x1010101010101010)) [[unlikely]] {
            width = std::countr_zero(tmp2[0]) - 4;
            n = neg * (((((((tmp[0] << (64 - width)) * 0xa01ull) >> 8 & 0x00ff00ff00ff00ffull) * 0x640001ull) >> 16 & 0x0000ffff0000ffffull) * 0x271000000001ull) >> 32);
            cur += (width >> 3) + 1;
        } else {
            __m256i tmp3;
            if ((tmp2[1] = (tmp[1] ^= 0x3030303030303030) & 0x1010101010101010)) [[unlikely]] {
                width = 60 + std::countr_zero(tmp2[1]);
                if (width == 64) [[unlikely]]
                    tmp3 = _mm256_setr_epi64x(0, 0, 0, tmp[0]);
                else tmp3 = _mm256_setr_epi64x(0, 0, tmp[0] << (128 - width), tmp[1] << (128 - width) | tmp[0] >> (width - 64));
            } else {
                width = 124 + std::countr_zero((tmp[2] ^= 0x3030303030303030) & 0x1010101010101010);
                if (width == 128) [[unlikely]]
                    tmp3 = _mm256_setr_epi64x(0, 0, tmp[0], tmp[1]);
                else tmp3 = _mm256_setr_epi64x(0, tmp[0] << (192 - width), tmp[1] << (192 - width) | tmp[0] >> (width - 128), tmp[2] << (192 - width) | tmp[1] >> (width - 128));
            }
            cur += (width >> 3) + 1;
            alignas(32) long long res[4];
            _mm256_store_epi64(res, _mm256_srli_epi64(_mm256_mullo_epi64(_mm256_srli_epi32(_mm256_mullo_epi32(_mm256_srli_epi16(_mm256_mullo_epi16(_mm256_and_si256(tmp3, _mm256_set1_epi8(0x0f)), _mm256_set1_epi16(0xa01)), 8), _mm256_set1_epi32(0x640001)), 16), _mm256_set1_epi64x(0x271000000001)), 32));
            n = neg * (res[1] * 10000000000000000 + res[2] * 100000000 + res[3]);
        }
#endif
        return *this;
    }
    FastIstream& operator>>(long& n) {
        long long x;
        operator>>(x);
        n = x;
        return *this;
    }
    FastIstream& operator>>(unsigned long& n) {
        unsigned long long x;
        operator>>(x);
        n = x;
        return *this;
    }
    friend FastIstream& operator>>(FastIstream& is, char& c) {
        is.reload(2);
        c = *is.cur;
        is.cur += 2;
        return is;
    }
    friend FastIstream& operator>>(FastIstream& is, unsigned char& c) {
        is.reload(2);
        c = *is.cur;
        is.cur += 2;
        return is;
    }
    friend FastIstream& operator>>(FastIstream& is, signed char& c) {
        is.reload(2);
        c = *is.cur;
        is.cur += 2;
        return is;
    }
    friend FastIstream& operator>>(FastIstream& is, char* s) {
        while (true) {
            while (*is.cur > ' ' && is.cur != is.eof) *(s++) = *is.cur, ++is.cur;
            if (is.cur == is.eof) is.reload(is.buffersize);
            else break;
        }
        ++is.cur;
        *s = '\0';
        return is;
    }
    friend FastIstream& operator>>(FastIstream& is, std::string& s) {
        s.clear();
        while (true) {
            char* st = is.cur;
            while (*is.cur > ' ' && is.cur != is.eof) ++is.cur;
            s += std::string_view(st, is.cur - st);
            if (is.cur == is.eof) is.reload(is.buffersize);
            else break;
        }
        ++is.cur;
        return is;
    }
    FastIstream& operator>>(float& f) {
        std::string s;
        (*this) >> s;
        std::from_chars(s.c_str(), s.c_str() + s.length(), f);
        return *this;
    }
    FastIstream& operator>>(double& f) {
        std::string s;
        (*this) >> s;
        std::from_chars(s.c_str(), s.c_str() + s.length(), f);
        return *this;
    }
    FastIstream& operator>>(long double& f) {
        std::string s;
        (*this) >> s;
        std::from_chars(s.c_str(), s.c_str() + s.length(), f);
        return *this;
    }
    template<std::ranges::range T> friend FastIstream& operator>>(FastIstream& is, T& x) {
        for (auto& v : x) is >> v;
        return is;
    }
    char getc() {
        reload(1);
        return *(cur++);
    }
    void seek(int n) {
        reload(n);
        cur += n;
    }
} fin;
class FastOstream : public std::ios_base {
    constexpr static int buffersize = 1 << 18;
    char buffer[buffersize];
    char* cur = buffer;
    inline void reload(ptrdiff_t w) {
        if (buffer + buffersize - w < cur) [[unlikely]] {
            [[maybe_unused]] int r = write(1, buffer, cur - buffer);
            cur = buffer;
        }
    }
    constexpr static std::array<unsigned, 10000> strtable = []() {
        std::array<unsigned, 10000> res;
        for (unsigned i = 0; i < 10000; ++i) {
            unsigned tmp[4];
            unsigned n = i;
            tmp[3] = (n % 10 + '0') << 24, n /= 10;
            tmp[2] = (n % 10 + '0') << 16, n /= 10;
            tmp[1] = (n % 10 + '0') << 8, n /= 10;
            tmp[0] = n % 10 + '0';
            res[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
        }
        return res;
    }();
    constexpr static std::array<unsigned, 10000> strtable2 = []() {
        std::array<unsigned, 10000> res;
        for (unsigned i = 0; i < 10000; ++i) {
            unsigned tmp[4];
            unsigned n = i;
            if (i < 10) n *= 1000;
            else if (i < 100) n *= 100;
            else if (i < 1000) n *= 10;
            tmp[3] = (n % 10 + '0') << 24, n /= 10;
            tmp[2] = (n % 10 + '0') << 16, n /= 10;
            tmp[1] = (n % 10 + '0') << 8, n /= 10;
            tmp[0] = n % 10 + '0';
            res[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
        }
        return res;
    }();
    template<class T> void putfloat(T f) {
        bool fixed = flags() & std::ios_base::fixed;
        bool scientific = flags() & std::ios_base::scientific;
        bool uppercase = flags() & std::ios_base::uppercase;
        if (fixed && scientific && (flags() & std::ios_base::showbase)) {
            std::memcpy(cur, (uppercase ? "0X" : "0x"), 2);
            cur += 2;
        }
        std::chars_format fmt = (fixed ? (scientific ? std::chars_format::hex : std::chars_format::fixed) : (scientific ? std::chars_format::scientific : std::chars_format::general));
        auto conv = [&]() {
            return std::to_chars(cur, buffer + buffersize, f, fmt, precision());
        };
        auto [ptr, ec] = conv();
        char* p;
        if (ec == std::errc::value_too_large) {
            reload(buffersize);
            p = cur;
            cur = conv().ptr;
        } else p = cur, cur = ptr;
        if (uppercase) {
            while (p != cur) {
                if (*p > '9') *p -= ('a' - 'A');
                ++p;
            }
        }
    }
public:
    FastOstream() {
        precision(6);
        setf(std::ios_base::showbase);
    }
    ~FastOstream() { reload(buffersize); }
    FastOstream& flush() {
        reload(buffersize);
        return *this;
    }
    char widen(char c) const { return c; }
    FastOstream& put(char c) {
        reload(1);
        *(cur++) = c;
        return *this;
    }
    FastOstream& operator<<(std::basic_ostream<FastOstream, void>& (*pf)(std::basic_ostream<FastOstream, void>&) );
    FastOstream& operator<<(std::basic_ios<FastOstream, void>& (*pf)(std::basic_ios<FastOstream, void>&) );
    FastOstream& operator<<(std::ios_base& (*pf)(std::ios_base&) ) {
        pf(*this);
        return *this;
    }
    FastOstream& operator<<(bool n) {
        if (ios_base::flags() & std::ios_base::boolalpha) {
            if (n) {
                reload(4);
                std::memcpy(cur, "true", 4);
                cur += 4;
            } else {
                reload(5);
                std::memcpy(cur, "false", 5);
                cur += 5;
            }
        } else {
            reload(1);
            *(cur++) = '0' + n;
        }
        return *this;
    }
    FastOstream& operator<<(unsigned short n) {
        reload(5);
        if (n >= 10000) {
            *(cur++) = '0' + n / 10000, n %= 10000;
            *reinterpret_cast<unsigned*>(cur) = strtable[n];
            cur += 4;
        } else if (n >= 1000) {
            *reinterpret_cast<unsigned*>(cur) = strtable[n];
            cur += 4;
        } else if (n >= 100) {
            *reinterpret_cast<unsigned*>(cur) = strtable[n * 10];
            cur += 3;
        } else if (n >= 10) {
            *(cur++) = '0' + n / 10;
            *(cur++) = '0' + n % 10;
        } else *(cur++) = '0' + n;
        return *this;
    }
    FastOstream& operator<<(short n) {
        reload(6);
        if (n < 0) *(cur++) = '-', n = -n;
        if (n >= 10000) {
            *(cur++) = '0' + n / 10000, n %= 10000;
            *reinterpret_cast<unsigned*>(cur) = strtable[n];
            cur += 4;
        } else if (n >= 1000) {
            *reinterpret_cast<unsigned*>(cur) = strtable[n];
            cur += 4;
        } else if (n >= 100) {
            *reinterpret_cast<unsigned*>(cur) = strtable[n * 10];
            cur += 3;
        } else if (n >= 10) {
            *reinterpret_cast<unsigned*>(cur) = strtable[n * 100];
            cur += 2;
        } else *(cur++) = '0' + n;
        return *this;
    }
    FastOstream& operator<<(unsigned n) {
        reload(10);
        unsigned long long buf = 0;
        char d = 0;
        if (n >= 100000000) {
            d = 8;
            buf = static_cast<unsigned long long>(strtable[n % 10000]) << 32 | strtable[(n / 10000) % 10000];
            n /= 100000000;
        } else if (n >= 10000) {
            d = 4;
            buf = strtable[n % 10000];
            n /= 10000;
        }
        *reinterpret_cast<unsigned*>(cur) = strtable2[n];
        cur += (n >= 10) + (n >= 100) + (n >= 1000) + 1;
        *reinterpret_cast<unsigned long long*>(cur) = buf;
        cur += d;
        return *this;
    }
    FastOstream& operator<<(int n) {
        reload(11);
        if (n < 0) *(cur++) = '-', n = -n;
        unsigned long long buf = 0;
        char d = 0;
        if (n >= 100000000) {
            d = 8;
            buf = static_cast<unsigned long long>(strtable[n % 10000]) << 32 | strtable[(n / 10000) % 10000];
            n /= 100000000;
        } else if (n >= 10000) {
            d = 4;
            buf = strtable[n % 10000];
            n /= 10000;
        }
        *reinterpret_cast<unsigned*>(cur) = strtable2[n];
        cur += (n >= 10) + (n >= 100) + (n >= 1000) + 1;
        *reinterpret_cast<unsigned long long*>(cur) = buf;
        cur += d;
        return *this;
    }
    FastOstream& operator<<(unsigned long long n) {
        reload(20);
        static unsigned buf[4];
        int d = 0;
        if (n >= 10000000000000000) {
            d = 16;
            buf[3] = strtable[n % 10000], n /= 10000;
            buf[2] = strtable[n % 10000], n /= 10000;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 1000000000000) {
            d = 12;
            buf[2] = strtable[n % 10000], n /= 10000;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 100000000) {
            d = 8;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 10000) {
            d = 4;
            buf[0] = strtable[n % 10000], n /= 10000;
        }
        *(unsigned*) cur = strtable2[n];
        cur += (n >= 10) + (n >= 100) + (n >= 1000) + 1;
        std::memcpy(cur, buf, d);
        cur += d;
        return *this;
    }
    FastOstream& operator<<(long long n) {
        reload(21);
        if (n < 0) *(cur++) = '-', n = -n;
        static unsigned buf[4];
        char d = 0;
        if (n >= 10000000000000000) {
            d = 16;
            buf[3] = strtable[n % 10000], n /= 10000;
            buf[2] = strtable[n % 10000], n /= 10000;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 1000000000000) {
            d = 12;
            buf[2] = strtable[n % 10000], n /= 10000;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 100000000) {
            d = 8;
            buf[1] = strtable[n % 10000], n /= 10000;
            buf[0] = strtable[n % 10000], n /= 10000;
        } else if (n >= 10000) {
            d = 4;
            buf[0] = strtable[n % 10000], n /= 10000;
        }
        *(unsigned*) cur = strtable2[n];
        cur += (n >= 10) + (n >= 100) + (n >= 1000) + 1;
        std::memcpy(cur, buf, d);
        cur += d;
        return *this;
    }
    FastOstream& operator<<(long n) { return operator<<(static_cast<long long>(n)); }
    FastOstream& operator<<(unsigned long n) { return operator<<(static_cast<unsigned long long>(n)); }
    FastOstream& operator<<(float f) {
        reload(16);
        putfloat(f);
        return *this;
    }
    FastOstream& operator<<(double f) {
        reload(32);
        putfloat(f);
        return *this;
    }
    FastOstream& operator<<(long double f) {
        reload(64);
        putfloat(f);
        return *this;
    }
    FastOstream& operator<<(const void* p) {
        reload(18);
        if (flags() & std::ios_base::showbase) {
            *cur = '0';
            *(cur + 1) = flags() & std::ios_base::uppercase ? 'X' : 'x';
            cur += 2;
        }
        cur = std::to_chars(cur, buffer + buffersize, reinterpret_cast<unsigned long long>(p), 16).ptr;
        return *this;
    }
    FastOstream& operator<<(std::nullptr_t) {
        reload(7);
        std::memcpy(cur, "nullptr", 7);
        cur += 7;
        return *this;
    }
    friend FastOstream& operator<<(FastOstream& os, char c) {
        os.reload(1);
        *(os.cur++) = c;
        return os;
    }
    friend FastOstream& operator<<(FastOstream& os, signed char c) {
        os.reload(1);
        *(os.cur++) = c;
        return os;
    }
    friend FastOstream& operator<<(FastOstream& os, unsigned char c) {
        os.reload(1);
        *(os.cur++) = c;
        return os;
    }
    friend FastOstream& operator<<(FastOstream& os, const char* s) {
        size_t n = std::strlen(s);
        if (n >= os.buffersize) {
            os.reload(buffersize);
            write(1, s, n);
        } else {
            os.reload(n);
            std::memcpy(os.cur, s, n);
            os.cur += n;
        }
        return os;
    }
    friend FastOstream& operator<<(FastOstream& os, const std::string& s) {
        size_t n = s.length();
        if (n >= os.buffersize) {
            os.reload(buffersize);
            write(1, s.data(), n);
        } else {
            os.reload(n);
            std::memcpy(os.cur, s.data(), n);
            os.cur += n;
        }
        return os;
    }
    friend FastOstream& operator<<(FastOstream& os, std::string_view s) {
        size_t n = s.length();
        if (n >= os.buffersize) {
            os.reload(buffersize);
            write(1, s.data(), n);
        } else {
            os.reload(n);
            std::memcpy(os.cur, s.data(), n);
            os.cur += n;
        }
        return os;
    }
    template<std::ranges::range T> friend FastOstream& operator<<(FastOstream& os, const T& v) {
        size_t n = std::distance(std::ranges::begin(v), std::ranges::end(v)), cnt = 0;
        for (const auto& x : v) {
            os << x;
            if (++cnt != n) os << ' ';
        }
        return os;
    }
#if __GNUC__ >= 6
    friend FastOstream& operator<<(FastOstream& os, std::_Setprecision prec) {
        os.precision(prec._M_n);
        return os;
    }
#endif
} fout;
namespace std {
template<> class basic_ios<FastOstream, void> {
protected:
    FastOstream& ref;
public:
    basic_ios(FastOstream& r) : ref(r) {}
    char widen(char c) { return ref.widen(c); }
};
template<> class basic_ostream<FastOstream, void> : public basic_ios<FastOstream, void> {
public:
    basic_ostream(FastOstream& r) : basic_ios(r) {}
    basic_ostream& put(char c) {
        basic_ios::ref.put(c);
        return *this;
    }
    basic_ostream& flush() {
        basic_ios::ref.flush();
        return *this;
    }
};
}  // namespace std
FastOstream& FastOstream::operator<<(std::basic_ostream<FastOstream, void>& (*pf)(std::basic_ostream<FastOstream, void>&) ) {
    std::basic_ostream<FastOstream, void> tmp(*this);
    pf(tmp);
    return *this;
}
FastOstream& FastOstream::operator<<(std::basic_ios<FastOstream, void>& (*pf)(std::basic_ios<FastOstream, void>&) ) {
    std::basic_ios<FastOstream, void> tmp(*this);
    pf(tmp);
    return *this;
}
#endif

#if defined(INCLUDE_YESNOBUF) || defined(INCLUDE_ALL)
template<size_t Q> class YesNoBuf {
    char buf[4 * Q];
    char* cur = buf;
public:
    inline ~YesNoBuf() noexcept { [[maybe_unused]] auto n = write(1, buf, cur - buf); }
    inline void operator()(bool b) {
        int n = (b ? 4 : 3);
        std::memcpy(cur, (b ? "Yes\n" : "No\n"), n);
        cur += n;
    }
};
#endif

#if defined(INCLUDE_COMPRESS) || defined(INCLUDE_ALL)
template<class Compare, class Iterator> constexpr std::vector<size_t> Compress(Iterator first, Iterator last, Compare comp = Compare()) {
    if (first == last) [[unlikely]] {
        return std::vector<size_t>{};
    }
    std::vector<std::pair<std::decay_t<decltype(*first)>, size_t>> v;
    size_t i = 0, sz = std::distance(first, last);
    v.reserve(sz);
    for (Iterator itr = first; i != sz; ++itr, ++i) v.emplace_back(*itr, i);
    std::sort(v.begin(), v.end(), [comp](const auto& a, const auto& b) { return comp(a.first, b.first); });
    std::vector<size_t> res(sz);
    res[v[0].second] = 0;
    for (size_t i = 1, k = 0; i != sz; ++i) {
        k += bool(comp(v[i - 1].first, v[i].first));
        res[v[i].second] = k;
    }
    return res;
}
template<class Iterator> constexpr std::vector<size_t> Compress(Iterator first, Iterator last) {
    return Compress<std::less<std::decay_t<decltype(*first)>>, Iterator>(first, last);
}
#endif

#if defined(INCLUDE_RLE) || defined(INCLUDE_ALL)
template<class Iterator> constexpr auto RLE(Iterator first, Iterator last) {
    std::vector<std::pair<std::decay_t<decltype(*first)>, size_t>> res;
    if (first == last) return res;
    res.emplace_back(*(first++), 1);
    for (auto itr = first; itr != last; ++itr) {
        if (*itr == res.back().first) ++res.back().second;
        else res.emplace_back(*itr, 1);
    }
    return res;
}
#endif

#if defined(INCLUDE_INVNUM) || defined(INCLUDE_ALL)
template<class Iterator> std::vector<size_t> Invnum(Iterator first, Iterator last) {
    size_t i = 0, sz = std::distance(first, last);
    std::vector<size_t> res(sz), bit(sz);
    for (Iterator itr = first; i != sz; ++itr, ++i) {
        for (size_t j = *itr; j; j &= j - 1) res[i] += bit[j - 1];
        for (size_t j = *itr + 1; j <= sz; j += (j & (0 - j))) ++bit[j - 1];
    }
    return res;
}
template<class Iterator> size_t Invnum_sum(Iterator first, Iterator last) {
    size_t i = 0, sz = std::distance(first, last), res = 0;
    std::vector<size_t> bit(sz);
    for (Iterator itr = first; i != sz; ++itr, ++i) {
        for (size_t j = *itr; j; j &= j - 1) res += bit[j - 1];
        for (size_t j = *itr + 1; j <= sz; j += (j & (0 - j))) ++bit[j - 1];
    }
    return res;
}
#endif

#if defined(INCLUDE_SLIDEMIN) || defined(INCLUDE_ALL)
template<class T, class Operator = std::less<T>> class SlideMin {
    std::deque<std::pair<T, size_t>> deq;
    size_t cnt1 = 0, cnt2 = 0;
    Operator op;
public:
    SlideMin() : op(Operator()) {}
    SlideMin(Operator op_) : op(op_) {}
    void push(const T& x) {
        while (!deq.empty() && op(x, deq.back().first)) deq.pop_back();
        deq.emplace_back(x, ++cnt1);
    }
    void pop() {
        if (deq.front().second == (++cnt2)) deq.pop_front();
    }
    const T& get() const { return deq.front().first; }
};
#endif

#if defined(INCLUDE_STRCOMP) || defined(INCLUDE_ALL)
template<std::ranges::range R> auto HuffmanCoding(const R& x) {
    using T = std::ranges::range_value_t<R>;
    std::unordered_map<T, size_t> cnt;
    for (const auto& y : x) ++cnt[y];
    struct node {
        std::optional<T> data;
        size_t left, right;
    };
    std::vector<node> buf;
    std::vector<size_t> sz;
    buf.reserve(2 * cnt.size());
    sz.reserve(2 * cnt.size());
    for (auto& [k, v] : cnt) {
        buf.push_back(node{ k, 0, 0 });
        sz.push_back(v);
    }
    auto cmp = [&](size_t a, size_t b) {
        return sz[a] >= sz[b];
    };
    std::priority_queue<size_t, std::vector<size_t>, decltype(cmp)> q(cmp);
    for (size_t i = 0; i != cnt.size(); ++i) q.push(i);
    while (q.size() >= 2) {
        size_t fir = q.top();
        q.pop();
        size_t sec = q.top();
        q.pop();
        buf.push_back(node{ std::nullopt, fir, sec });
        sz.push_back(sz[fir] + sz[sec]);
        q.push(buf.size() - 1);
    }
    return buf;
}
template<std::ranges::range R> std::string HuffmanEncode(const R& x, const auto& c) {
    using T = std::ranges::range_value_t<R>;
    std::string path;
    std::unordered_map<T, std::string> m;
    auto dfs = [&](auto self, const auto& n) -> void {
        if (!n.data) {
            path.push_back('0');
            self(self, c[n.left]);
            path.back() = '1';
            self(self, c[n.right]);
            path.pop_back();
        } else m.emplace(*n.data, path);
    };
    dfs(dfs, c.back());
    std::string res;
    for (const auto& y : x) res += m[y];
    return res;
}
template<std::ranges::range R> constexpr R HuffmanDecode(const std::string& x, const auto& c) {
    R res;
    size_t sz = c.size();
    size_t i = sz - 1;
    for (char y : x) {
        if (y == '0') i = c[i].left;
        else i = c[i].right;
        if (c[i].data) {
            res.push_back(*c[i].data);
            i = sz - 1;
        }
    }
    return res;
}
constexpr std::string Base64Encode(const std::string& x) {
    std::string res;
    int p = 0;
    for (size_t i = 0; i < x.length(); i += 6) {
        std::string tmp = x.substr(i, 6);
        if (tmp.length() < 6) p = 6 - tmp.length(), tmp += std::string(p, '0');
        int c = std::stoi(tmp, nullptr, 2);
        res.push_back(c < 26 ? 'A' + c : c < 52 ? 'a' + (c - 26) : c < 62 ? '0' + (c - 52) : c == 62 ? '+' : '/');
    }
    while (res.length() % 4 != 0) res.push_back('=');
    res = (char) ('0' + p) + res;
    return res;
}
constexpr std::string Base64Decode(std::string x) {
    std::string res;
    int p = x[0] - '0';
    while (x.back() == '=' || x.back() == '\n') x.pop_back();
    for (size_t i = 1; i != x.length(); ++i) {
        char c = x[i];
        if (c == '\n') continue;
        int n = c == '+' ? 62 : c == '/' ? 63 : c >= 'a' ? c - 'a' + 26 : c >= 'A' ? c - 'A' : c - '0' + 52;
        std::string tmp;
        while (n != 0) {
            tmp.push_back('0' + (n & 1));
            n >>= 1;
        }
        std::reverse(tmp.begin(), tmp.end());
        if (tmp.length() < 6) res += std::string(6 - tmp.length(), '0');
        res += tmp;
    }
    while (p--) res.pop_back();
    return res;
}
constexpr std::string Base85Encode(const std::string& x) {
    std::string res;
    int p = 0;
    for (size_t i = 0; i < x.length(); i += 32) {
        std::string tmp = x.substr(i, 32);
        p = (tmp.length() == 32 ? 0 : 32 - tmp.length());
        if (p != 0) tmp += std::string(p, '0');
        unsigned n = std::stoll(tmp, nullptr, 2);
        std::string tmp2;
        for (size_t j = 0; j != 5; ++j) {
            tmp2.push_back(n % 85 + 33);
            n /= 85;
        }
        std::reverse(tmp2.begin(), tmp2.end());
        res += tmp2;
    }
    return std::string{ (char) ('0' + p / 10), (char) ('0' + p % 10) } + res;
}
constexpr std::string Base85Decode(const std::string& x) {
    std::string res;
    size_t len = x.length();
    res.reserve((len + 2) / 5 * 32);
    int p = (x[0] - '0') * 10 + (x[1] - '0');
    for (size_t i = 2; i <= len - 5;) {
        int cnt = 0;
        unsigned n = 0;
        size_t j;
        for (j = 0; cnt != 5; ++j) {
            if (x[i + j] == '\n') continue;
            n = 85 * n + (x[i + j] - 33);
            ++cnt;
        }
        i += j;
        char tmp2[32];
        for (j = 0; j != 32; ++j) {
            tmp2[31 - j] = '0' + n % 2;
            n /= 2;
        }
        res += std::string(tmp2, tmp2 + 32);
    }
    while (p--) res.pop_back();
    return res;
}
#endif

#if defined(INCLUDE_INTERVALSCHEDULING) || defined(INCLUDE_ALL)
template<class T> std::basic_string<bool> IntervalScheduling(std::vector<std::pair<T, T>> x) {
    std::sort(x.begin(), x.end(), [](const std::pair<T, T>& a, const std::pair<T, T>& b) { return a.second < b.second; });
    std::basic_string<bool> res(x.size(), false);
    auto cur = std::numeric_limits<T>::lowest();
    for (size_t i = 0, sz = x.size(); i != sz; ++i) {
        const bool f = cur <= x[i].first;
        res[i] = f;
        cur = (f ? x[i].second : cur);
    }
    return res;
}
template<class T> size_t IntervalSchedulingCount(std::vector<std::pair<T, T>> x) {
    std::sort(x.begin(), x.end(), [](const std::pair<T, T>& a, const std::pair<T, T>& b) { return a.second < b.second; });
    size_t res = 0;
    auto cur = std::numeric_limits<T>::lowest();
    for (size_t i = 0, sz = x.size(); i != sz; ++i) {
        const bool f = cur <= x[i].first;
        res += f;
        cur = (f ? x[i].second : cur);
    }
    return res;
}

#endif

#if defined(INCLUDE_BEAMSEARCH)
template<class State, class F1, class F2, class Rep, class Period> State BeamSearch(const State& init, F1 transition, F2 getscore, size_t width = 16, const std::chrono::duration<Rep, Period>& time) {
    using result_type = decltype(getscore(init));
    std::vector<State> state;
    state.emplace_back(init);
    for (auto start_time = std::chrono::system_clock::now(); std::chrono::system_clock::now() - start_time < time;) {
        for (size_t i = 0, sz = state.size(); i < sz; ++i)
            if constexpr (std::is_same_v<State, decltype(transition(state[i]))>) state.emplace_back(transition(state[i]));
            else
                for (State&& next : transition(state[i])) state.emplace_back(next);
        if (state.size() <= width) continue;
        std::vector<size_t> sorted(state.size());
        std::vector<result_type> evaluated(state.size());
        std::iota(sorted.begin(), sorted.end(), 0);
        for (size_t i = 0, sz = state.size(); i < sz; ++i) evaluated[i] = getscore(state[i]);
        std::nth_element(sorted.begin(), sorted.begin() + width, sorted.end(), [&](size_t a, size_t b) { return evaluated[a] > evaluated[b]; });
        std::vector<State> next;
        for (size_t i = 0; i < width; ++i) next.emplace_back(std::move(state[sorted[i]]));
        state = std::move(next);
    }
    std::vector<result_type> evaluated(state.size());
    for (size_t i = 0, sz = state.size(); i < sz; ++i) evaluated[i] = getscore(state[i]);
    size_t res = 0;
    result_type max_score = std::numeric_limits<result_type>::lowest();
    for (size_t i = 0, sz = state.size(); i < sz; ++i) {
        result_type score = getscore(state[i]);
        if (score > max_score) max_score = score, res = i;
    }
    return state[res];
}
#endif

#if defined(INCLUDE_SA)
template<class State, class Next, class Prev, class Eval, class Scheduler, class Rep, class Period> auto SimulatedAnnealing(State& curstate, Next next, Prev prev, Eval eval, Scheduler temp, const std::chrono::duration<Rep, Period>& time) {
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::duration dur = std::chrono::duration_cast<std::chrono::system_clock::duration>(time);
    uint32_t randval = std::random_device{}();
    auto curscore = eval(curstate);
    int cnt = 0;
    while (((++cnt) & 0xfff) != 0 || (std::chrono::system_clock::now() - start < dur && temp.get() > 0.0000001)) {
        auto d = next(curstate);
        auto score = eval(curstate);
        if (score >= curscore) [[unlikely]]
            curscore = score;
        else {
            randval ^= randval << 13;
            randval ^= randval >> 17;
            randval ^= randval << 5;
            if (std::bit_cast<float>((127 << 23) | (randval & 0x7fffff)) - 1.0f < std::exp(static_cast<float>(score - curscore) / temp.get())) curscore = score;
            else prev(curstate, std::move(d));
        }
        temp.next();
    }
    while (((++cnt) & 0xfff) != 0 || std::chrono::system_clock::now() - start < dur) {
        auto d = next(curstate);
        auto score = eval(curstate);
        if (score >= curscore) [[unlikely]]
            curscore = score;
        else prev(curstate, std::move(d));
    }
    return curscore;
}
namespace TempSchedulers {
struct Linear {
    float a, b;
    size_t cnt = 0;
    float prog = 0;
    std::chrono::system_clock::duration time;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    template<class Rep, class Period> Linear(float a_, float c_, const std::chrono::duration<Rep, Period>& time_) : a(a_), b(a_ - c_), time(std::chrono::duration_cast<decltype(time)>(time_)) {}
    float get() { return std::max<float>(0.0f, a - b * prog); }
    void next() {
        if (++cnt == 32) {
            cnt = 0;
            prog = (std::chrono::system_clock::now() - start) / time;
        }
    }
};
}  // namespace TempSchedulers
#endif

#if defined(INCLUDE_SORT) || defined(INCLUDE_ALL)
template<class T, bool Rev = false> void SortUnsigned32(T* const p, const unsigned n) {
    static unsigned cnt1[1 << 16], cnt2[1 << 16];
    std::memset(cnt1, 0, sizeof(cnt1));
    std::memset(cnt2, 0, sizeof(cnt2));
    for (unsigned i = 0; i != n; ++i) {
        const T a = p[i] & 0xffff;
        const T b = p[i] >> 16 & 0xffff;
        ++cnt1[a];
        ++cnt2[b];
    }
    for (unsigned i = 0; i != (1 << 16) - 1; ++i) {
        cnt1[i + 1] += cnt1[i];
        cnt2[i + 1] += cnt2[i];
    }
    T* const tmp = reinterpret_cast<T*>(std::malloc(sizeof(T) * n));
    if constexpr (Rev) {
        for (unsigned i = 0; i != n; ++i) tmp[--cnt1[p[i] & 0xffff]] = p[i];
        for (unsigned i = 0; i != n; ++i) p[--cnt2[tmp[i] >> 16 & 0xffff]] = tmp[i];
    } else {
        for (unsigned i = n; i != 0;) --i, tmp[--cnt1[p[i] & 0xffff]] = p[i];
        for (unsigned i = n; i != 0;) --i, p[--cnt2[tmp[i] >> 16 & 0xffff]] = tmp[i];
    }
    std::free(tmp);
}
template<class T, bool Rev = false> void SortUnsigned64(T* const p, const unsigned n) {
    static unsigned cnt1[1 << 16], cnt2[1 << 16], cnt3[1 << 16], cnt4[1 << 16];
    std::memset(cnt1, 0, sizeof(cnt1));
    std::memset(cnt2, 0, sizeof(cnt2));
    std::memset(cnt3, 0, sizeof(cnt3));
    std::memset(cnt4, 0, sizeof(cnt4));
    for (unsigned i = 0; i != n; ++i) {
        const T a = p[i] & 0xffff;
        const T b = p[i] >> 16 & 0xffff;
        const T c = p[i] >> 32 & 0xffff;
        const T d = p[i] >> 48 & 0xffff;
        ++cnt1[a];
        ++cnt2[b];
        ++cnt3[c];
        ++cnt4[d];
    }
    for (unsigned i = 0; i != (1 << 16) - 1; ++i) {
        cnt1[i + 1] += cnt1[i];
        cnt2[i + 1] += cnt2[i];
        cnt3[i + 1] += cnt3[i];
        cnt4[i + 1] += cnt4[i];
    }
    T* const tmp = reinterpret_cast<T*>(std::malloc(sizeof(T) * n));
    if constexpr (Rev) {
        for (unsigned i = 0; i != n; ++i) tmp[--cnt1[p[i] & 0xffff]] = p[i];
        for (unsigned i = 0; i != n; ++i) p[--cnt2[tmp[i] >> 16 & 0xffff]] = tmp[i];
        for (unsigned i = 0; i != n; ++i) tmp[--cnt3[p[i] >> 32 & 0xffff]] = p[i];
        for (unsigned i = 0; i != n; ++i) p[--cnt4[tmp[i] >> 48 & 0xffff]] = tmp[i];
    } else {
        for (unsigned i = n; i != 0;) --i, tmp[--cnt1[p[i] & 0xffff]] = p[i];
        for (unsigned i = n; i != 0;) --i, p[--cnt2[tmp[i] >> 16 & 0xffff]] = tmp[i];
        for (unsigned i = n; i != 0;) --i, tmp[--cnt3[p[i] >> 32 & 0xffff]] = p[i];
        for (unsigned i = n; i != 0;) --i, p[--cnt4[tmp[i] >> 48 & 0xffff]] = tmp[i];
    }
    std::free(tmp);
}
unsigned CompressUnsigned(unsigned* const p, unsigned n) {
    unsigned long long* const c = reinterpret_cast<unsigned long long*>(std::malloc(sizeof(unsigned long long) * n));
    for (unsigned i = 0; i != n; ++i) c[i] = (unsigned long long) i << 32 | p[i];
    SortUnsigned64(c, n);
    unsigned cnt = 0;
    for (unsigned i = 1; i != n; ++i) {
        p[c[i - 1] >> 32] = cnt;
        cnt += (c[i - 1] & 0xffffffff) != (c[i] & 0xffffffff);
    }
    p[c[n - 1] >> 32] = cnt;
    std::free(c);
    return cnt;
}
namespace internal {
template<unsigned N, class T, class Comp = std::less<T>> constexpr void OptimalSort_fixedlength(T* const p, const Comp& comp = Comp()) {
    // clang-format off
#define F(A,B) {if constexpr(std::is_trivially_move_assignable_v<T>){T a=p[A],b=p[B];const bool f=comp(a,b);p[A]=f?a:b;p[B]=f?b:a;}else{T a=std::move(p[A]),b=std::move(p[B]);const bool f=comp(a,b);p[A]=std::move(f?a:b);p[B]=std::move(f?b:a);}}
if constexpr(N==2){F(0,1)}
if constexpr(N==3){F(0,2)F(0,1)F(1,2)}
if constexpr(N==4){F(0,2)F(1,3)F(0,1)F(2,3)F(1,2)}
if constexpr(N==5){F(0,3)F(1,4)F(0,2)F(1,3)F(0,1)F(2,4)F(1,2)F(3,4)F(2,3)}
if constexpr(N==6){F(0,5)F(1,3)F(2,4)F(1,2)F(3,4)F(0,3)F(2,5)F(0,1)F(2,3)F(4,5)F(1,2)F(3,4)}
if constexpr(N==7){F(0,6)F(2,3)F(4,5)F(0,2)F(1,4)F(3,6)F(0,1)F(2,5)F(3,4)F(1,2)F(4,6)F(2,3)F(4,5)F(1,2)F(3,4)F(5,6)}
if constexpr(N==8){F(0,2)F(1,3)F(4,6)F(5,7)F(0,4)F(1,5)F(2,6)F(3,7)F(0,1)F(2,3)F(4,5)F(6,7)F(2,4)F(3,5)F(1,4)F(3,6)F(1,2)F(3,4)F(5,6)}
if constexpr(N==9){F(0,3)F(1,7)F(2,5)F(4,8)F(0,7)F(2,4)F(3,8)F(5,6)F(0,2)F(1,3)F(4,5)F(7,8)F(1,4)F(3,6)F(5,7)F(0,1)F(2,4)F(3,5)F(6,8)F(2,3)F(4,5)F(6,7)F(1,2)F(3,4)F(5,6)}
if constexpr(N==10){F(0,8)F(1,9)F(2,7)F(3,5)F(4,6)F(0,2)F(1,4)F(5,8)F(7,9)F(0,3)F(2,4)F(5,7)F(6,9)F(0,1)F(3,6)F(8,9)F(1,5)F(2,3)F(4,8)F(6,7)F(1,2)F(3,5)F(4,6)F(7,8)F(2,3)F(4,5)F(6,7)F(3,4)F(5,6)}
if constexpr(N==11){F(0,9)F(1,6)F(2,4)F(3,7)F(5,8)F(0,1)F(3,5)F(4,10)F(6,9)F(7,8)F(1,3)F(2,5)F(4,7)F(8,10)F(0,4)F(1,2)F(3,7)F(5,9)F(6,8)F(0,1)F(2,6)F(4,5)F(7,8)F(9,10)F(2,4)F(3,6)F(5,7)F(8,9)F(1,2)F(3,4)F(5,6)F(7,8)F(2,3)F(4,5)F(6,7)}
if constexpr(N==12){F(0,8)F(1,7)F(2,6)F(3,11)F(4,10)F(5,9)F(0,1)F(2,5)F(3,4)F(6,9)F(7,8)F(10,11)F(0,2)F(1,6)F(5,10)F(9,11)F(0,3)F(1,2)F(4,6)F(5,7)F(8,11)F(9,10)F(1,4)F(3,5)F(6,8)F(7,10)F(1,3)F(2,5)F(6,9)F(8,10)F(2,3)F(4,5)F(6,7)F(8,9)F(4,6)F(5,7)F(3,4)F(5,6)F(7,8)}
if constexpr(N==13){F(0,12)F(1,10)F(2,9)F(3,7)F(5,11)F(6,8)F(1,6)F(2,3)F(4,11)F(7,9)F(8,10)F(0,4)F(1,2)F(3,6)F(7,8)F(9,10)F(11,12)F(4,6)F(5,9)F(8,11)F(10,12)F(0,5)F(3,8)F(4,7)F(6,11)F(9,10)F(0,1)F(2,5)F(6,9)F(7,8)F(10,11)F(1,3)F(2,4)F(5,6)F(9,10)F(1,2)F(3,4)F(5,7)F(6,8)F(2,3)F(4,5)F(6,7)F(8,9)F(3,4)F(5,6)}
if constexpr(N==14){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(0,2)F(1,3)F(4,8)F(5,9)F(10,12)F(11,13)F(0,4)F(1,2)F(3,7)F(5,8)F(6,10)F(9,13)F(11,12)F(0,6)F(1,5)F(3,9)F(4,10)F(7,13)F(8,12)F(2,10)F(3,11)F(4,6)F(7,9)F(1,3)F(2,8)F(5,11)F(6,7)F(10,12)F(1,4)F(2,6)F(3,5)F(7,11)F(8,10)F(9,12)F(2,4)F(3,6)F(5,8)F(7,10)F(9,11)F(3,4)F(5,6)F(7,8)F(9,10)F(6,7)}
if constexpr(N==15){F(1,2)F(3,10)F(4,14)F(5,8)F(6,13)F(7,12)F(9,11)F(0,14)F(1,5)F(2,8)F(3,7)F(6,9)F(10,12)F(11,13)F(0,7)F(1,6)F(2,9)F(4,10)F(5,11)F(8,13)F(12,14)F(0,6)F(2,4)F(3,5)F(7,11)F(8,10)F(9,12)F(13,14)F(0,3)F(1,2)F(4,7)F(5,9)F(6,8)F(10,11)F(12,13)F(0,1)F(2,3)F(4,6)F(7,9)F(10,12)F(11,13)F(1,2)F(3,5)F(8,10)F(11,12)F(3,4)F(5,6)F(7,8)F(9,10)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(5,6)F(7,8)}
if constexpr(N==16){F(0,13)F(1,12)F(2,15)F(3,14)F(4,8)F(5,6)F(7,11)F(9,10)F(0,5)F(1,7)F(2,9)F(3,4)F(6,13)F(8,14)F(10,15)F(11,12)F(0,1)F(2,3)F(4,5)F(6,8)F(7,9)F(10,11)F(12,13)F(14,15)F(0,2)F(1,3)F(4,10)F(5,11)F(6,7)F(8,9)F(12,14)F(13,15)F(1,2)F(3,12)F(4,6)F(5,7)F(8,10)F(9,11)F(13,14)F(1,4)F(2,6)F(5,8)F(7,10)F(9,13)F(11,14)F(2,4)F(3,6)F(9,12)F(11,13)F(3,5)F(6,8)F(7,9)F(10,12)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(6,7)F(8,9)}
if constexpr(N==17){F(0,11)F(1,15)F(2,10)F(3,5)F(4,6)F(8,12)F(9,16)F(13,14)F(0,6)F(1,13)F(2,8)F(4,14)F(5,15)F(7,11)F(0,8)F(3,7)F(4,9)F(6,16)F(10,11)F(12,14)F(0,2)F(1,4)F(5,6)F(7,13)F(8,9)F(10,12)F(11,14)F(15,16)F(0,3)F(2,5)F(6,11)F(7,10)F(9,13)F(12,15)F(14,16)F(0,1)F(3,4)F(5,10)F(6,9)F(7,8)F(11,15)F(13,14)F(1,2)F(3,7)F(4,8)F(6,12)F(11,13)F(14,15)F(1,3)F(2,7)F(4,5)F(9,11)F(10,12)F(13,14)F(2,3)F(4,6)F(5,7)F(8,10)F(3,4)F(6,8)F(7,9)F(10,12)F(5,6)F(7,8)F(9,10)F(11,12)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)}
if constexpr(N==18){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(0,2)F(1,3)F(4,12)F(5,13)F(6,8)F(9,11)F(14,16)F(15,17)F(0,14)F(1,16)F(2,15)F(3,17)F(0,6)F(1,10)F(2,9)F(7,16)F(8,15)F(11,17)F(1,4)F(3,9)F(5,7)F(8,14)F(10,12)F(13,16)F(0,1)F(2,5)F(3,13)F(4,14)F(7,9)F(8,10)F(12,15)F(16,17)F(1,2)F(3,5)F(4,6)F(11,13)F(12,14)F(15,16)F(4,8)F(5,12)F(6,10)F(7,11)F(9,13)F(1,4)F(2,8)F(3,6)F(5,7)F(9,15)F(10,12)F(11,14)F(13,16)F(2,4)F(5,8)F(6,10)F(7,11)F(9,12)F(13,15)F(3,5)F(6,8)F(7,10)F(9,11)F(12,14)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)}
if constexpr(N==19){F(0,12)F(1,4)F(2,8)F(3,5)F(6,17)F(7,11)F(9,14)F(10,13)F(15,16)F(0,2)F(1,7)F(3,6)F(4,11)F(5,17)F(8,12)F(10,15)F(13,16)F(14,18)F(3,10)F(4,14)F(5,15)F(6,13)F(7,9)F(11,17)F(16,18)F(0,7)F(1,10)F(4,6)F(9,15)F(11,16)F(12,17)F(13,14)F(0,3)F(2,6)F(5,7)F(8,11)F(12,16)F(1,8)F(2,9)F(3,4)F(6,15)F(7,13)F(10,11)F(12,18)F(1,3)F(2,5)F(6,9)F(7,12)F(8,10)F(11,14)F(17,18)F(0,1)F(2,3)F(4,8)F(6,10)F(9,12)F(14,15)F(16,17)F(1,2)F(5,8)F(6,7)F(9,11)F(10,13)F(14,16)F(15,17)F(3,6)F(4,5)F(7,9)F(8,10)F(11,12)F(13,14)F(15,16)F(3,4)F(5,6)F(7,8)F(9,10)F(11,13)F(12,14)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)}
if constexpr(N==20){F(0,3)F(1,7)F(2,5)F(4,8)F(6,9)F(10,13)F(11,15)F(12,18)F(14,17)F(16,19)F(0,14)F(1,11)F(2,16)F(3,17)F(4,12)F(5,19)F(6,10)F(7,15)F(8,18)F(9,13)F(0,4)F(1,2)F(3,8)F(5,7)F(11,16)F(12,14)F(15,19)F(17,18)F(1,6)F(2,12)F(3,5)F(4,11)F(7,17)F(8,15)F(13,18)F(14,16)F(0,1)F(2,6)F(7,10)F(9,12)F(13,17)F(18,19)F(1,6)F(5,9)F(7,11)F(8,12)F(10,14)F(13,18)F(3,5)F(4,7)F(8,10)F(9,11)F(12,15)F(14,16)F(1,3)F(2,4)F(5,7)F(6,10)F(9,13)F(12,14)F(15,17)F(16,18)F(1,2)F(3,4)F(6,7)F(8,9)F(10,11)F(12,13)F(15,16)F(17,18)F(2,3)F(4,6)F(5,8)F(7,9)F(10,12)F(11,14)F(13,15)F(16,17)F(4,5)F(6,8)F(7,10)F(9,12)F(11,13)F(14,15)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)}
if constexpr(N==21){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(0,4)F(1,5)F(3,7)F(6,20)F(8,12)F(9,13)F(10,14)F(15,19)F(2,6)F(3,18)F(7,20)F(2,16)F(3,6)F(5,18)F(7,17)F(11,20)F(0,2)F(3,8)F(6,12)F(7,10)F(9,16)F(11,15)F(13,17)F(14,18)F(19,20)F(1,7)F(2,3)F(4,9)F(10,11)F(13,16)F(15,18)F(17,19)F(1,4)F(5,10)F(6,13)F(7,8)F(11,14)F(12,16)F(15,17)F(18,19)F(1,2)F(3,4)F(5,6)F(10,12)F(11,13)F(14,16)F(17,18)F(2,3)F(4,5)F(6,9)F(10,11)F(12,13)F(14,15)F(16,17)F(6,7)F(8,9)F(15,16)F(4,6)F(7,8)F(9,12)F(13,15)F(3,4)F(5,7)F(8,10)F(9,11)F(12,14)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)}
if constexpr(N==22){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(0,2)F(1,3)F(4,6)F(5,7)F(8,12)F(9,13)F(14,16)F(15,17)F(18,20)F(19,21)F(0,4)F(1,5)F(2,6)F(3,7)F(8,10)F(9,12)F(11,13)F(14,18)F(15,19)F(16,20)F(17,21)F(0,14)F(1,15)F(2,18)F(3,19)F(4,16)F(5,17)F(6,20)F(7,21)F(9,11)F(10,12)F(2,8)F(3,11)F(6,9)F(10,18)F(12,15)F(13,19)F(0,2)F(1,10)F(3,16)F(5,18)F(6,14)F(7,15)F(8,12)F(9,13)F(11,20)F(19,21)F(2,6)F(3,10)F(4,8)F(5,12)F(9,16)F(11,18)F(13,17)F(15,19)F(1,4)F(7,13)F(8,14)F(9,12)F(17,20)F(1,2)F(3,8)F(4,6)F(7,11)F(10,14)F(13,18)F(15,17)F(19,20)F(2,4)F(5,10)F(7,9)F(11,16)F(12,14)F(17,19)F(5,6)F(7,8)F(9,11)F(10,12)F(13,14)F(15,16)F(3,5)F(6,7)F(8,10)F(9,12)F(11,13)F(14,15)F(16,18)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)}
if constexpr(N==23){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(21,22)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(10,14)F(11,15)F(17,21)F(18,20)F(19,22)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(1,2)F(5,18)F(7,19)F(9,16)F(10,21)F(12,20)F(15,22)F(5,9)F(6,7)F(10,18)F(11,21)F(12,17)F(13,20)F(14,15)F(3,17)F(6,16)F(7,14)F(8,12)F(15,19)F(20,21)F(3,4)F(5,8)F(6,10)F(9,12)F(13,16)F(14,15)F(17,18)F(19,21)F(0,5)F(1,8)F(2,12)F(3,9)F(4,10)F(7,13)F(11,17)F(14,16)F(18,20)F(2,6)F(3,5)F(4,8)F(7,11)F(10,12)F(13,18)F(14,17)F(15,20)F(1,3)F(2,5)F(6,9)F(7,10)F(11,13)F(12,14)F(15,18)F(16,17)F(19,20)F(2,3)F(4,6)F(8,9)F(11,12)F(13,14)F(15,16)F(17,19)F(3,4)F(5,6)F(7,8)F(9,10)F(12,13)F(14,15)F(17,18)F(4,5)F(6,7)F(8,9)F(10,11)F(16,17)}
if constexpr(N==24){F(0,20)F(1,12)F(2,16)F(3,23)F(4,6)F(5,10)F(7,21)F(8,14)F(9,15)F(11,22)F(13,18)F(17,19)F(0,3)F(1,11)F(2,7)F(4,17)F(5,13)F(6,19)F(8,9)F(10,18)F(12,22)F(14,15)F(16,21)F(20,23)F(0,1)F(2,4)F(3,12)F(5,8)F(6,9)F(7,10)F(11,20)F(13,16)F(14,17)F(15,18)F(19,21)F(22,23)F(2,5)F(4,8)F(6,11)F(7,14)F(9,16)F(12,17)F(15,19)F(18,21)F(1,8)F(3,14)F(4,7)F(9,20)F(10,12)F(11,13)F(15,22)F(16,19)F(0,7)F(1,5)F(3,4)F(6,11)F(8,15)F(9,14)F(10,13)F(12,17)F(16,23)F(18,22)F(19,20)F(0,2)F(1,6)F(4,7)F(5,9)F(8,10)F(13,15)F(14,18)F(16,19)F(17,22)F(21,23)F(2,3)F(4,5)F(6,8)F(7,9)F(10,11)F(12,13)F(14,16)F(15,17)F(18,19)F(20,21)F(1,2)F(3,6)F(4,10)F(7,8)F(9,11)F(12,14)F(13,19)F(15,16)F(17,20)F(21,22)F(2,3)F(5,10)F(6,7)F(8,9)F(13,18)F(14,15)F(16,17)F(20,21)F(3,4)F(5,7)F(10,12)F(11,13)F(16,18)F(19,20)F(4,6)F(8,10)F(9,12)F(11,14)F(13,15)F(17,19)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)}
if constexpr(N==25){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(21,22)F(23,24)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(10,14)F(11,15)F(18,21)F(20,23)F(22,24)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(16,20)F(17,22)F(19,24)F(21,23)F(1,18)F(3,21)F(5,23)F(6,19)F(11,14)F(15,24)F(1,16)F(3,17)F(6,9)F(7,11)F(13,19)F(14,23)F(0,1)F(2,16)F(3,8)F(7,20)F(10,13)F(11,22)F(15,23)F(1,2)F(5,10)F(7,18)F(11,21)F(15,20)F(19,22)F(4,7)F(5,6)F(9,18)F(10,17)F(11,12)F(13,21)F(14,15)F(19,20)F(22,23)F(3,4)F(7,8)F(9,10)F(11,16)F(12,17)F(13,18)F(19,21)F(20,22)F(1,3)F(2,4)F(5,11)F(6,16)F(7,9)F(8,10)F(12,13)F(14,19)F(15,18)F(2,3)F(5,7)F(6,9)F(8,11)F(10,16)F(12,14)F(15,17)F(3,5)F(4,6)F(7,8)F(9,11)F(10,12)F(13,14)F(15,16)F(17,18)F(4,7)F(6,8)F(9,10)F(11,12)F(13,15)F(14,16)F(17,19)F(18,21)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)}
if constexpr(N==26){F(0,1)F(2,3)F(4,21)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)F(22,23)F(24,25)F(0,24)F(1,25)F(3,21)F(4,22)F(5,7)F(6,8)F(9,11)F(10,12)F(13,15)F(14,16)F(17,19)F(18,20)F(0,4)F(2,22)F(3,23)F(5,9)F(6,10)F(7,11)F(8,12)F(13,17)F(14,18)F(15,19)F(16,20)F(21,25)F(0,2)F(1,3)F(4,21)F(5,13)F(6,14)F(7,15)F(8,16)F(9,17)F(10,18)F(11,19)F(12,20)F(22,24)F(23,25)F(0,5)F(1,7)F(2,4)F(3,10)F(15,22)F(18,24)F(20,25)F(21,23)F(2,9)F(3,7)F(4,14)F(5,13)F(6,15)F(10,19)F(11,21)F(12,20)F(16,23)F(18,22)F(1,5)F(2,6)F(3,15)F(7,17)F(8,18)F(10,22)F(11,13)F(12,14)F(19,23)F(20,24)F(1,2)F(4,7)F(5,11)F(8,9)F(10,12)F(13,15)F(14,20)F(16,17)F(18,21)F(23,24)F(3,8)F(4,6)F(7,16)F(9,18)F(10,13)F(12,15)F(17,22)F(19,21)F(4,5)F(6,11)F(7,9)F(14,19)F(16,18)F(20,21)F(2,4)F(3,6)F(7,10)F(8,11)F(9,12)F(13,16)F(14,17)F(15,18)F(19,22)F(21,23)F(3,4)F(5,8)F(6,7)F(9,10)F(11,13)F(12,14)F(15,16)F(17,20)F(18,19)F(21,22)F(5,6)F(7,8)F(9,11)F(10,13)F(12,15)F(14,16)F(17,18)F(19,20)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)}
if constexpr(N==27){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,14)F(15,16)F(17,18)F(19,20)F(21,22)F(23,24)F(25,26)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,13)F(15,17)F(16,18)F(19,21)F(20,22)F(23,25)F(24,26)F(0,23)F(1,24)F(2,25)F(3,26)F(4,8)F(5,9)F(6,10)F(7,11)F(13,14)F(15,19)F(16,20)F(17,21)F(18,22)F(0,4)F(1,6)F(2,19)F(3,20)F(5,13)F(9,21)F(11,14)F(12,16)F(17,23)F(18,24)F(22,26)F(5,17)F(6,16)F(7,22)F(9,25)F(10,24)F(12,15)F(13,20)F(14,26)F(1,12)F(4,15)F(7,23)F(10,19)F(11,16)F(13,18)F(20,24)F(22,25)F(0,1)F(6,12)F(8,11)F(9,15)F(10,17)F(14,24)F(16,21)F(18,19)F(1,4)F(2,8)F(3,11)F(12,15)F(14,20)F(16,22)F(21,25)F(2,5)F(3,17)F(8,13)F(11,23)F(21,22)F(24,25)F(1,2)F(3,10)F(5,6)F(7,13)F(11,15)F(14,21)F(18,23)F(20,22)F(4,5)F(6,9)F(7,8)F(13,17)F(14,16)F(19,23)F(22,24)F(2,4)F(3,6)F(5,7)F(8,12)F(9,10)F(11,13)F(14,18)F(15,17)F(16,19)F(21,23)F(3,5)F(6,8)F(7,9)F(10,12)F(11,14)F(13,16)F(15,18)F(17,19)F(20,21)F(22,23)F(5,6)F(8,11)F(9,10)F(12,14)F(13,15)F(17,18)F(19,21)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,20)F(21,22)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)}
if constexpr(N==28){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)F(24,25)F(26,27)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(20,22)F(21,23)F(24,26)F(25,27)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(14,18)F(15,19)F(20,24)F(21,25)F(22,26)F(23,27)F(0,20)F(1,21)F(2,22)F(3,23)F(4,24)F(5,25)F(6,26)F(7,27)F(9,17)F(10,18)F(11,15)F(12,16)F(1,2)F(4,20)F(5,6)F(7,23)F(8,12)F(9,16)F(10,14)F(11,18)F(13,17)F(15,19)F(21,22)F(25,26)F(0,8)F(1,9)F(2,12)F(3,5)F(4,10)F(6,16)F(7,13)F(11,21)F(14,20)F(15,25)F(17,23)F(18,26)F(19,27)F(22,24)F(2,4)F(3,7)F(5,17)F(8,14)F(9,11)F(10,22)F(13,19)F(16,18)F(20,24)F(23,25)F(1,8)F(3,9)F(5,11)F(6,10)F(7,15)F(12,20)F(16,22)F(17,21)F(18,24)F(19,26)F(1,2)F(4,6)F(5,9)F(10,16)F(11,17)F(12,14)F(13,15)F(18,22)F(21,23)F(25,26)F(4,8)F(6,12)F(7,11)F(10,14)F(13,17)F(15,21)F(16,20)F(19,23)F(2,4)F(6,8)F(7,16)F(9,14)F(10,12)F(11,20)F(13,18)F(15,17)F(19,21)F(23,25)F(3,10)F(5,12)F(7,9)F(11,13)F(14,16)F(15,22)F(17,24)F(18,20)F(3,6)F(5,8)F(7,10)F(9,12)F(11,14)F(13,16)F(15,18)F(17,20)F(19,22)F(21,24)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)F(21,22)F(23,24)}
if constexpr(N==29){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,28)F(17,26)F(18,25)F(19,23)F(21,27)F(22,24)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(17,22)F(18,19)F(20,27)F(23,25)F(24,26)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(10,14)F(11,15)F(16,20)F(17,18)F(19,22)F(23,24)F(25,26)F(27,28)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(16,18)F(20,22)F(21,25)F(24,27)F(26,28)F(1,8)F(2,24)F(4,19)F(5,20)F(6,21)F(7,27)F(9,18)F(10,23)F(11,26)F(13,22)F(14,25)F(15,28)F(16,17)F(0,6)F(2,4)F(3,24)F(5,10)F(12,19)F(13,18)F(14,21)F(15,25)F(20,23)F(26,27)F(0,16)F(1,6)F(3,12)F(4,8)F(5,17)F(7,24)F(14,20)F(15,26)F(18,21)F(19,23)F(25,27)F(1,5)F(2,16)F(3,10)F(6,9)F(7,18)F(8,17)F(11,19)F(13,14)F(15,22)F(21,23)F(25,26)F(1,2)F(3,5)F(4,8)F(6,16)F(7,11)F(9,17)F(10,12)F(14,20)F(15,18)F(19,24)F(22,27)F(4,6)F(9,16)F(10,13)F(11,19)F(12,14)F(20,21)F(22,26)F(23,24)F(2,4)F(3,6)F(7,16)F(8,9)F(11,17)F(15,19)F(18,23)F(24,25)F(3,4)F(5,9)F(7,10)F(11,13)F(12,16)F(14,17)F(15,20)F(19,21)F(22,24)F(5,8)F(6,7)F(9,12)F(10,11)F(13,14)F(15,16)F(17,20)F(18,19)F(21,23)F(24,25)F(5,6)F(7,8)F(9,10)F(11,12)F(13,15)F(14,16)F(17,18)F(19,20)F(21,22)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)}
if constexpr(N==30){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)F(24,25)F(26,27)F(28,29)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(13,15)F(14,16)F(18,20)F(19,21)F(22,24)F(23,25)F(26,28)F(27,29)F(0,4)F(1,5)F(2,6)F(3,7)F(8,14)F(9,17)F(10,16)F(12,20)F(13,19)F(15,21)F(22,26)F(23,27)F(24,28)F(25,29)F(0,8)F(1,9)F(2,14)F(3,17)F(4,10)F(5,11)F(6,16)F(12,26)F(13,23)F(15,27)F(18,24)F(19,25)F(20,28)F(21,29)F(1,13)F(2,12)F(3,15)F(4,18)F(5,19)F(6,20)F(7,21)F(8,22)F(9,23)F(10,24)F(11,25)F(14,26)F(16,28)F(17,27)F(0,4)F(2,8)F(3,13)F(5,9)F(6,22)F(7,23)F(10,12)F(11,15)F(14,18)F(16,26)F(17,19)F(20,24)F(21,27)F(25,29)F(0,2)F(1,14)F(3,5)F(4,8)F(9,13)F(11,17)F(12,18)F(15,28)F(16,20)F(21,25)F(24,26)F(27,29)F(2,4)F(5,9)F(6,14)F(7,13)F(8,10)F(15,23)F(16,22)F(19,21)F(20,24)F(25,27)F(6,8)F(7,11)F(10,14)F(12,16)F(13,17)F(15,19)F(18,22)F(21,23)F(4,6)F(7,9)F(8,10)F(11,13)F(12,14)F(15,17)F(16,18)F(19,21)F(20,22)F(23,25)F(1,8)F(3,18)F(5,20)F(7,22)F(9,24)F(10,12)F(11,26)F(13,15)F(14,16)F(17,19)F(21,28)F(1,2)F(3,10)F(5,12)F(7,14)F(9,16)F(11,18)F(13,20)F(15,22)F(17,24)F(19,26)F(27,28)F(2,4)F(3,6)F(5,8)F(7,10)F(9,12)F(11,14)F(13,16)F(15,18)F(17,20)F(19,22)F(21,24)F(23,26)F(25,27)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)F(21,22)F(23,24)F(25,26)}
if constexpr(N==31){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)F(24,25)F(26,27)F(28,29)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(20,22)F(21,23)F(24,26)F(25,27)F(28,30)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(10,14)F(11,15)F(16,20)F(17,21)F(18,22)F(19,23)F(24,28)F(25,29)F(26,30)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(16,24)F(17,25)F(18,26)F(19,27)F(20,28)F(21,29)F(22,30)F(0,16)F(1,8)F(2,4)F(3,12)F(5,10)F(6,9)F(7,14)F(11,13)F(17,24)F(18,20)F(19,28)F(21,26)F(22,25)F(23,30)F(27,29)F(1,2)F(3,5)F(4,8)F(6,22)F(7,11)F(9,25)F(10,12)F(13,14)F(17,18)F(19,21)F(20,24)F(23,27)F(26,28)F(29,30)F(1,17)F(2,18)F(3,19)F(4,20)F(5,10)F(7,23)F(8,24)F(11,27)F(12,28)F(13,29)F(14,30)F(21,26)F(3,17)F(4,16)F(5,21)F(6,18)F(7,9)F(8,20)F(10,26)F(11,23)F(13,25)F(14,28)F(15,27)F(22,24)F(1,4)F(3,8)F(5,16)F(7,17)F(9,21)F(10,22)F(11,19)F(12,20)F(14,24)F(15,26)F(23,28)F(27,30)F(2,5)F(7,8)F(9,18)F(11,17)F(12,16)F(13,22)F(14,20)F(15,19)F(23,24)F(26,29)F(2,4)F(6,12)F(9,16)F(10,11)F(13,17)F(14,18)F(15,22)F(19,25)F(20,21)F(27,29)F(5,6)F(8,12)F(9,10)F(11,13)F(14,16)F(15,17)F(18,20)F(19,23)F(21,22)F(25,26)F(3,5)F(6,7)F(8,9)F(10,12)F(11,14)F(13,16)F(15,18)F(17,20)F(19,21)F(22,23)F(24,25)F(26,28)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)F(21,22)F(23,24)F(25,26)F(27,28)}
if constexpr(N==32){F(0,1)F(2,3)F(4,5)F(6,7)F(8,9)F(10,11)F(12,13)F(14,15)F(16,17)F(18,19)F(20,21)F(22,23)F(24,25)F(26,27)F(28,29)F(30,31)F(0,2)F(1,3)F(4,6)F(5,7)F(8,10)F(9,11)F(12,14)F(13,15)F(16,18)F(17,19)F(20,22)F(21,23)F(24,26)F(25,27)F(28,30)F(29,31)F(0,4)F(1,5)F(2,6)F(3,7)F(8,12)F(9,13)F(10,14)F(11,15)F(16,20)F(17,21)F(18,22)F(19,23)F(24,28)F(25,29)F(26,30)F(27,31)F(0,8)F(1,9)F(2,10)F(3,11)F(4,12)F(5,13)F(6,14)F(7,15)F(16,24)F(17,25)F(18,26)F(19,27)F(20,28)F(21,29)F(22,30)F(23,31)F(0,16)F(1,8)F(2,4)F(3,12)F(5,10)F(6,9)F(7,14)F(11,13)F(15,31)F(17,24)F(18,20)F(19,28)F(21,26)F(22,25)F(23,30)F(27,29)F(1,2)F(3,5)F(4,8)F(6,22)F(7,11)F(9,25)F(10,12)F(13,14)F(17,18)F(19,21)F(20,24)F(23,27)F(26,28)F(29,30)F(1,17)F(2,18)F(3,19)F(4,20)F(5,10)F(7,23)F(8,24)F(11,27)F(12,28)F(13,29)F(14,30)F(21,26)F(3,17)F(4,16)F(5,21)F(6,18)F(7,9)F(8,20)F(10,26)F(11,23)F(13,25)F(14,28)F(15,27)F(22,24)F(1,4)F(3,8)F(5,16)F(7,17)F(9,21)F(10,22)F(11,19)F(12,20)F(14,24)F(15,26)F(23,28)F(27,30)F(2,5)F(7,8)F(9,18)F(11,17)F(12,16)F(13,22)F(14,20)F(15,19)F(23,24)F(26,29)F(2,4)F(6,12)F(9,16)F(10,11)F(13,17)F(14,18)F(15,22)F(19,25)F(20,21)F(27,29)F(5,6)F(8,12)F(9,10)F(11,13)F(14,16)F(15,17)F(18,20)F(19,23)F(21,22)F(25,26)F(3,5)F(6,7)F(8,9)F(10,12)F(11,14)F(13,16)F(15,18)F(17,20)F(19,21)F(22,23)F(24,25)F(26,28)F(3,4)F(5,6)F(7,8)F(9,10)F(11,12)F(13,14)F(15,16)F(17,18)F(19,20)F(21,22)F(23,24)F(25,26)F(27,28)}
    // clang-format on
    static_assert(N <= 32, "OptimalSort_fixedlength / The length of the array must be less than or equal to 32.");
#undef F
}
}  // namespace internal
template<class T, class Comp = std::less<T>> void Sort(T* const p, unsigned N, Comp comp = Comp()) {
#define OS(n) internal::OptimalSort_fixedlength<n, T, Comp>
    static void (*const sortrun[])(T* const, Comp) = { OS(0), OS(1), OS(2), OS(3), OS(4), OS(5), OS(6), OS(7), OS(8), OS(9), OS(10), OS(11), OS(12), OS(13), OS(14), OS(15), OS(16), OS(17), OS(18), OS(19), OS(20), OS(21), OS(22), OS(23), OS(24), OS(25), OS(26), OS(27), OS(28), OS(29), OS(30), OS(31), OS(32) };
#undef OS
    if (N <= 32) {
        sortrun[N](p, comp);
        return;
    }
    const unsigned minrun = ((N >> (std::bit_width(N) - 5)) + ((N & ((1ull << (std::bit_width(N) - 5)) - 1)) != 0)) << std::has_single_bit(N);
    {
        const unsigned lim = N / minrun * minrun;
        const auto func = sortrun[minrun];
        for (unsigned i = 0; i < lim; i += minrun) func(p + i, comp);
        if (lim != N) sortrun[N - lim](p + lim, comp);
    }
    //T* const mem = (T* const) std::malloc(sizeof(T) * (N / 2));
    //T* cur = p, *work = mem;
    //std::free(mem);
}
#endif

#if (defined(INCLUDE_DEQUE) || defined(INCLUDE_ALL)) && __GNUC__ >= 12
template<class T> class Stack {
public:
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;

private:
    std::vector<std::unique_ptr<T[]>> data = []() {
        std::vector<std::unique_ptr<T[]>> res;
        res.emplace_back(new T[16]);
        return res;
    }();
    size_t x = 0, y = 0, sz = 0, max_length = 16;

public:
    constexpr Stack() {}
    template<class InputIterator> constexpr Stack(InputIterator first, InputIterator last) {
        for (auto itr = first; itr != last; ++itr) push(*itr);
    }
    constexpr Stack(const Stack&) = default;
    constexpr Stack(Stack&&) noexcept = default;
    constexpr ~Stack() {
        if constexpr (std::is_trivially_destructible_v<T>) return;
        size_t i = 0, j = 0;
        while (i != x || j != y) {
            if (j == 16ull * (1ull << i)) ++i, j = 0;
            std::destroy_at(&data[i][j++]);
        }
    }
    constexpr Stack& operator=(const Stack&) = default;
    constexpr Stack& operator=(Stack&&) noexcept = default;
    constexpr reference top() noexcept { return data[x][y - 1]; }
    constexpr const_reference top() const noexcept { return data[x][y - 1]; }
    [[nodiscard]] constexpr bool empty() const noexcept { return sz == 0; }
    constexpr size_type size() const noexcept { return sz; }
    constexpr void push(const value_type& n) {
        if (y == max_length) {
            y = 0, max_length = 16ull * (1ull << (++x));
            if (x == data.size()) {
                data.emplace_back(new T[max_length]);
            }
        }
        if constexpr (std::is_trivially_constructible_v<T>) data[x][y++] = n;
        else std::construct_at(&data[x][y++], n);
        ++sz;
    }
    constexpr void push(value_type&& n) {
        if (y == max_length) {
            y = 0, max_length = 16ull * (1ull << (++x));
            if (x == data.size()) {
                data.emplace_back(new T[max_length]);
            }
        }
        if constexpr (std::is_trivially_constructible_v<T>) data[x][y++] = n;
        else std::construct_at(&data[x][y++], std::move(n));
        ++sz;
    }
    template<class... Args> constexpr T& emplace(Args&&... args) {
        if (y == max_length) {
            y = 0, max_length = 16ull * (1ull << (++x));
            if (x == data.size()) {
                data.emplace_back(new T[max_length]);
            }
        }
        std::construct_at(&data[x][y], std::forward(args...));
        ++sz;
        return data[x][y++];
    }
    constexpr void pop() {
        if constexpr (!std::is_trivially_destructible_v<T>) std::destroy_at(&data[x][y--]);
        --sz;
        if (y == 0) --x, max_length = 16ull * (1ull << x), y = max_length;
    }
    constexpr void swap(Stack& s) noexcept {
        data.swap(s.data);
        std::swap(x, s.x);
        std::swap(y, s.y);
        std::swap(sz, s.sz);
        std::swap(max_length, s.max_length);
    }
    template<class U> friend void swap(Stack<U>& a, Stack<U>& b) noexcept { a.swap(b); }
};
#endif

#if defined(INCLUDE_BOOLEANSET) || defined(INCLUDE_ALL)
class BooleanSet {
    std::vector<size_t> index1;
    std::vector<size_t> index2;
    size_t true_counter;

public:
    BooleanSet(size_t N) : index1(N), index2(N), true_counter(0) {
        for (size_t i = 0; i < N; ++i) index1[i] = index2[i] = i;
    }
    bool test(size_t N) { return index1[N] < true_counter; }
    void set(size_t N) {
        if (!test(N)) {
            index1[N] = true_counter;
            std::swap(index2[N], index2[true_counter]);
            ++true_counter;
        }
    }
    void reset(size_t N) {
        if (test(N)) {
            --true_counter;
            index1[N] = true_counter;
            std::swap(index2[N], index2[true_counter]);
        }
    }
    std::vector<size_t> enumrate() {
        std::vector<size_t> ans(true_counter);
        for (size_t i = 0; i < true_counter; ++i) ans[i] = index2[i];
        return ans;
    }
};
#endif

#if defined(INCLUDE_BIT) || defined(INCLUDE_ALL)
template<class T, class Allocator = std::allocator<T>> class RangeSumQuery {
    std::vector<T, Allocator> bit;
public:
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    constexpr RangeSumQuery() noexcept(noexcept(Allocator())) : RangeSumQuery(Allocator()) {}
    constexpr explicit RangeSumQuery(const Allocator& alloc) noexcept : bit(alloc) {}
    constexpr explicit RangeSumQuery(size_type n, const Allocator& alloc = Allocator()) : bit(n, alloc) {}
    constexpr RangeSumQuery(size_type n, const T& value, const Allocator& alloc = Allocator()) : bit(alloc) { assign(n, value); }
    template<class InputIter> constexpr RangeSumQuery(InputIter first, InputIter last, const Allocator& alloc = Allocator()) : bit(alloc) { assign(first, last); }
    constexpr RangeSumQuery(const RangeSumQuery&) = default;
    constexpr RangeSumQuery(RangeSumQuery&&) noexcept = default;
    constexpr RangeSumQuery(const RangeSumQuery& x, const Allocator& alloc) : bit(x.bit, alloc) {}
    constexpr RangeSumQuery(RangeSumQuery&& x, const Allocator& alloc) : bit(std::move(x.bit), alloc) {}
    constexpr RangeSumQuery(std::initializer_list<T> il, const Allocator& alloc = Allocator()) : RangeSumQuery(il.begin(), il.end(), alloc) {}
    constexpr RangeSumQuery& operator=(const RangeSumQuery&) = default;
    constexpr RangeSumQuery& operator=(RangeSumQuery&&) noexcept(std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value || std::allocator_traits<Allocator>::is_always_equal::value) = default;
    constexpr RangeSumQuery& operator=(std::initializer_list<T> il) {
        assign(il);
        return *this;
    }
    constexpr size_type size() const noexcept { return bit.size(); }
    /*
    constexpr void resize(size_type sz) { resize(sz, value_type{}); }
    constexpr void resize(size_type sz, const T &c) {
        size_type n = bit.size();
        bit.resize(sz);
        if (n >= sz) return;
        // TODO:
    }
    */
    [[nodiscard]] constexpr bool empty() const noexcept { return bit.empty(); }
    constexpr value_type operator[](size_type n) const {
        value_type res = bit[n];
        if (!(n & 1)) return res;
        size_type tmp = n & (n + 1);
        for (size_type i = n; i != tmp; i &= i - 1) res -= bit[i - 1];
        return res;
    }
    constexpr value_type at(size_type n) const {
        if (n >= size()) throw std::out_of_range("RangeSumQuery::at / Index is out of range.");
        return operator[](n);
    }
    template<class InputIterator> constexpr void assign(InputIterator first, InputIterator last) {
        bit.assign(first, last);
        size_type n = bit.size();
        for (size_type i = 1; i != n; ++i) {
            const size_type a = i - 1;
            const size_type b = i & -i;
            bit[a + b] += (a + b < n ? bit[a] : value_type{});
        }
    }
    constexpr void assign(size_type n, const T& u) {
        if (n == 0) return;
        bit = std::vector<value_type, Allocator>(n, get_allocator());
        std::vector<value_type, Allocator> mul(std::bit_width(n), get_allocator());
        mul[0] = u;
        for (size_type i = 1, sz = mul.size(); i < sz; ++i) mul[i] = mul[i - 1], mul[i] += mul[i - 1];
        for (size_type i = 1; i <= n; ++i) bit[i - 1] = mul[std::countr_zero(i)];
    }
    constexpr void assign(std::initializer_list<T> il) { assign(il.begin(), il.end()); }
    constexpr void swap(RangeSumQuery& x) noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value || std::allocator_traits<Allocator>::is_always_equal::value) { bit.swap(x.bit); };
    constexpr void clear() { bit.clear(); }
    constexpr allocator_type get_allocator() const noexcept { return bit.get_allocator(); }
    constexpr void add(size_type n, const value_type& x) {
        for (size_type i = n + 1, sz = size(); i <= sz; i += (i & -i)) bit[i - 1] += x;
    }
    constexpr void minus(size_type n, const value_type& x) {
        for (size_type i = n + 1, sz = size(); i <= sz; i += (i & -i)) bit[i - 1] -= x;
    }
    constexpr void increme(size_type n) {
        for (size_type i = n + 1, sz = size(); i <= sz; i += (i & (-i))) ++bit[i - 1];
    }
    constexpr void decreme(size_type n) {
        for (size_type i = n + 1, sz = size(); i <= sz; i += (i & (-i))) --bit[i - 1];
    }
    constexpr value_type sum(size_type n) const {
        value_type res = {};
        for (size_type i = n; i != 0; i &= i - 1) res += bit[i - 1];
        return res;
    }
    constexpr value_type sum(size_type l, size_type r) const {
        size_type n = l & ~((std::bit_floor(l ^ r) << 1) - 1);
        value_type res = {};
        for (size_type i = r; i != n; i &= i - 1) res += bit[i - 1];
        for (size_type i = l; i != n; i &= i - 1) res -= bit[i - 1];
        return res;
    }
    constexpr size_type lower_bound(value_type x) const {
        static_assert(std::is_unsigned_v<value_type>, "RangeSumQuery::lower_bound / value_type must be unsigned.");
        size_type res = 0, n = size();
        for (size_type len = std::bit_floor(n); len != 0; len >>= 1) {
            if (res + len <= n && bit[res + len - 1] < x) {
                x -= bit[res + len - 1];
                res += len;
            }
        }
        return res;
    }
    constexpr size_type upper_bound(value_type x) const {
        static_assert(std::is_unsigned_v<value_type>, "RangeSumQuery::upper_bound / value_type must be unsigned.");
        size_type res = 0, n = size();
        for (size_type len = std::bit_floor(n); len != 0; len >>= 1) {
            if (res + len <= n && !(x < bit[res + len - 1])) {
                x -= bit[res + len - 1];
                res += len;
            }
        }
        return res;
    }
};
template<class U, class Alloc> constexpr void swap(RangeSumQuery<U, Alloc>& x, RangeSumQuery<U, Alloc>& y) noexcept(noexcept(x.swap(y))) {
    x.swap(y);
}
template<class InputIterator, class Allocator = std::allocator<typename std::iterator_traits<InputIterator>::value_type>> RangeSumQuery(InputIterator, InputIterator, Allocator = Allocator()) -> RangeSumQuery<typename std::iterator_traits<InputIterator>::value_type, Allocator>;
template<class T, class Allocator = std::allocator<T>> using RSQ = RangeSumQuery<T, Allocator>;
#endif

#if defined(INCLUDE_STATICRSQ) || defined(INCLUDE_ALL)
template<class T, class Allocator = std::allocator<T>> class StaticRangeSumQuery : public std::vector<T, Allocator> {
public:
    using std::vector<T, Allocator>::vector;
    constexpr void build() {
        for (size_t i = 0, last = this->size() - 1; i != last; ++i) this->operator[](i + 1) += this->operator[](i);
    }
    constexpr T sum(size_t n) const { return (n == 0 ? T{} : this->operator[](n - 1)); }
    constexpr T sum(size_t l, size_t r) const { return (l == 0 ? (r == 0 ? T{} : this->operator[](r - 1)) : this->operator[](r - 1) - this->operator[](l - 1)); }
};
template<class T, class Allocator = std::allocator<T>> class StaticRangeSumQuery2D : public std::vector<std::vector<T, Allocator>, typename std::allocator_traits<Allocator>::template rebind_alloc<std::vector<T, Allocator>>> {
    using base = std::vector<std::vector<T, Allocator>, typename std::allocator_traits<Allocator>::template rebind_alloc<std::vector<T, Allocator>>>;
public:
    using base::base;
    constexpr void build() {
        for (size_t i = 0, h = this->size(); i != h; ++i) {
            for (size_t j = 0, w = (*this)[i].size() - 1; j != w; ++j) (*this)[i][j + 1] += (*this)[i][j];
        }
        for (size_t i = 0, h = this->size() - 1; i != h; ++i) {
            for (size_t j = 0, w = (*this)[i].size(); j != w; ++j) (*this)[i + 1][j] += (*this)[i][j];
        }
    }
    constexpr T sum(size_t x1, size_t y1, size_t x2, size_t y2) const {
        if (x1 == 0) {
            if (y1 == 0) return (*this)[x2 - 1][y2 - 1];
            else return (*this)[x2 - 1][y2 - 1] - (*this)[x2 - 1][y1 - 1];
        } else {
            if (y1 == 0) return (*this)[x2 - 1][y2 - 1] - (*this)[x1 - 1][y2 - 1];
            else return (*this)[x2 - 1][y2 - 1] - (*this)[x1 - 1][y2 - 1] - (*this)[x2 - 1][y1 - 1] + (*this)[x1 - 1][y1 - 1];
        }
    }
};
#endif

#if defined(INCLUDE_SEGTREE) || defined(INCLUDE_ALL)
template<class T, class Operator, class Allocator = std::allocator<T>> class SegmentTree {
    size_t sz = 0;
    std::vector<T, Allocator> tree;
    [[no_unique_address]] Operator f;
    const T e;
public:
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using operator_type = Operator;
    constexpr SegmentTree(const T& ex) : tree(Allocator()), f(Operator()), e(ex) {}
    constexpr explicit SegmentTree(const Operator& opr, const T& ex, const Allocator& alloc = Allocator()) : tree(alloc), f(opr), e(ex) {}
    constexpr explicit SegmentTree(const T& ex, const Allocator& alloc) : tree(alloc), f(Operator()), e(ex) {}
    constexpr explicit SegmentTree(size_type n, const Operator& opr, const T& ex, const Allocator& alloc = Allocator()) : sz(n), tree((std::bit_ceil(n) << 1) - 1, ex, alloc), f(opr), e(ex) {}
    constexpr explicit SegmentTree(size_type n, const T& ex, const Allocator& alloc = Allocator()) : SegmentTree(n, Operator(), ex, alloc) {}
    constexpr SegmentTree(size_type n, const T& value, const Operator& opr, const T& ex, const Allocator& alloc = Allocator()) : SegmentTree(opr, ex, alloc) { assign(n, value); }
    constexpr SegmentTree(size_type n, const T& value, const T& ex, const Allocator& alloc) : SegmentTree(n, value, Operator(), ex, alloc) {}
    template<class InputIter> constexpr SegmentTree(InputIter first, InputIter last, const Operator& opr, const T& ex, const Allocator& alloc = Allocator()) : tree(alloc), f(opr), e(ex) { assign(first, last); }
    template<class InputIter> constexpr SegmentTree(InputIter first, InputIter last, const T& ex, const Allocator& alloc = Allocator()) : SegmentTree(first, last, Operator(), ex, alloc) {}
    constexpr SegmentTree(const SegmentTree&) = default;
    constexpr SegmentTree(SegmentTree&&) = default;
    constexpr SegmentTree(const SegmentTree& x, const Allocator& alloc) : sz(x.sz), tree(x.tree, alloc), f(x.f), e(x.e) {}
    constexpr SegmentTree(SegmentTree&& y, const Allocator& alloc) : sz(y.sz), tree(std::move(y.tree), alloc), f(y.f), e(std::move(y.e)) {}
    constexpr SegmentTree(std::initializer_list<T> init, const T& ex, const Allocator& alloc = Allocator()) : SegmentTree(init.begin(), init.end(), Operator(), ex, alloc) {}
    constexpr SegmentTree(std::initializer_list<T> init, const Operator& opr, const T& ex, const Allocator& alloc = Allocator()) : SegmentTree(init.begin(), init.end(), opr, ex, alloc) {}
    constexpr SegmentTree& operator=(const SegmentTree&) = default;
    constexpr SegmentTree& operator=(SegmentTree&&) noexcept(std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value || std::allocator_traits<Allocator>::is_always_equal::value) = default;
    constexpr SegmentTree& operator=(std::initializer_list<value_type> il) {
        assign(il);
        return *this;
    }
    constexpr size_type size() const noexcept { return sz; }
    constexpr void resize(size_type n) { resize(n, e); }
    constexpr void resize(size_type n, const T& c) {
        std::vector<value_type> tmp;
        tmp.reserve(sz);
        for (size_t i = 0; i != sz; ++i) tmp.emplace_back(std::move(operator[](i)));
        tmp.resize(n, c);
        assign(tmp.begin(), tmp.end());
    }
    [[nodiscard]] bool empty() const noexcept { return sz == 0; }
    constexpr const_reference operator[](size_type n) const { return tree[n + tree.size() / 2]; }
    constexpr const_reference at(size_type n) const {
        if (n >= sz) throw std::out_of_range("SegmentTree::at / Index is out of range.");
        return tree[n + tree.size() / 2];
    }
    template<class InputIterator> constexpr void assign(InputIterator first, InputIterator last) {
        sz = std::distance(first, last);
        tree.assign((std::bit_ceil(sz) << 1) - 1, e);
        size_t h = tree.size() / 2;
        InputIterator itr = first;
        for (size_t i = 0; i != sz; ++i, ++itr) tree[h + i] = *itr;
        for (size_t i = 0; i != h; ++i) {
            size_t tmp = h - i - 1;
            tree[tmp] = f(tree[(tmp << 1) + 1], tree[(tmp << 1) + 2]);
        }
    }
    constexpr void assign(size_type n, const value_type& u) {
        sz = n;
        tree.assign((std::bit_ceil(sz) << 1) - 1, e);
        size_t h = tree.size() / 2;
        for (size_t i = 0; i != sz; ++i) tree[h + i] = u;
        for (size_t i = 0; i != h; ++i) {
            size_t tmp = h - i - 1;
            tree[tmp] = f(tree[(tmp << 1) + 1], tree[(tmp << 1) + 2]);
        }
    }
    constexpr void assign(std::initializer_list<value_type> il) { assign(il.begin(), il.end()); }
    constexpr void swap(SegmentTree& x) noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value || std::allocator_traits<Allocator>::is_always_equal::value) {
        using std::swap;
        swap(sz, x.sz), swap(tree, x.tree), swap(f, x.f);
    };
    constexpr void clear() { sz = 0, tree.clear(); }
    constexpr allocator_type get_allocator() const noexcept { return tree.get_allocator(); }
    constexpr void set(size_type n, const value_type& x) {
        size_type i = n + (tree.size() >> 1);
        tree[i] = x;
        while (i > 0) {
            i = (i - 1) >> 1;
            tree[i] = f(tree[(i << 1) + 1], tree[(i << 1) + 2]);
        }
    }
    constexpr const_reference get(size_type n) const { return operator[](n); }
    constexpr value_type prod(size_type l, size_type r) {
        value_type resl = e, resr = e;
        size_type h = (tree.size() + 1) >> 1;
        for (l += h, r += h; l < r; l = (l + 1) >> 1, r >>= 1) {
            resl = l & 1 ? f(resl, tree[l - 1]) : resl;
            resr = r & 1 ? f(tree[r - 2], resr) : resr;
        }
        return f(resl, resr);
    }
    constexpr value_type all_prod() const { return (sz ? tree[0] : e); }
    // p(prod[l,r)) == true && (r == N || p(prod[l,r]) == false)となるrを一つ見つける
    // p(prod[l,i))がiに関して単調な時、rはp(prod[l,r)) == trueとなる最大のもの
    template<class F> constexpr size_type max_right(size_type l, F p = F()) {
        value_type x = e;
        size_type h = (tree.size() + 1) >> 1;
        for (size_type curl = l + h, curr = tree.size() + 1; curl < curr; curl >>= 1, curr >>= 1) {
            if (curl & 1) {
                value_type tmp = f(x, tree[(++curl) - 2]);
                if (!p(tmp)) {
                    --curl;
                    while (curl < h) {
                        curl <<= 1;
                        value_type tmp = f(x, tree[curl - 1]);
                        if (p(tmp)) {
                            x = tmp, ++curl;
                        }
                    }
                    return curl - h;
                } else x = tmp;
            }
        }
        return sz;
    }
    // p(prod[l,r)) == true && (l == 0 || p(prod[l - 1, r)) == false)となるlを一つ見つける
    // p(prod[i,r))がiに関して単調な時、lはp(prod[l,r)) == trueとなる最小のもの
    template<class F> constexpr size_type min_left(size_type r, F p = F()) {
        //TODO
        return 0;
    }
};
template<class U, class Opr, class Alloc> constexpr void swap(SegmentTree<U, Opr, Alloc>& x, SegmentTree<U, Opr, Alloc>& y) noexcept(noexcept(x.swap(y))) {
    x.swap(y);
}
template<class T, class Operator, class E, class Allocator = std::allocator<T>> class SegmentTreeWrapper : public SegmentTree<T, Operator, Allocator> {
    using base = SegmentTree<T, Operator, Allocator>;
    using size_type = base::size_type;
public:
    constexpr SegmentTreeWrapper() : base(E()()) {}
    constexpr explicit SegmentTreeWrapper(const Allocator& alloc) : base(E()(), alloc) {}
    constexpr explicit SegmentTreeWrapper(size_type n, const Allocator& alloc = Allocator()) : base(n, E()(), alloc) {}
    constexpr SegmentTreeWrapper(size_type n, const T& value, const Allocator& alloc) : base(n, value, E()(), alloc) {}
    template<class InputIter> constexpr SegmentTreeWrapper(InputIter first, InputIter last, const Allocator& alloc = Allocator()) : base(first, last, E()(), alloc) {}
    constexpr SegmentTreeWrapper(const SegmentTreeWrapper&) = default;
    constexpr SegmentTreeWrapper(SegmentTreeWrapper&&) = default;
    constexpr SegmentTreeWrapper(const SegmentTreeWrapper& x, const Allocator& alloc) : base(x, E()(), alloc) {}
    constexpr SegmentTreeWrapper(SegmentTreeWrapper&& y, const Allocator& alloc) : base(std::move(y), E()(), alloc) {}
    constexpr SegmentTreeWrapper(std::initializer_list<T> init, const Allocator& alloc = Allocator()) : base(init, E()(), alloc) {}
};
template<class InputIter, class Operator, class E, class Allocator = std::allocator<typename std::iterator_traits<InputIter>::value_type>> SegmentTreeWrapper(InputIter, InputIter, Allocator = Allocator()) -> SegmentTreeWrapper<typename std::iterator_traits<InputIter>::value_type, Operator, E, Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeMaximumQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return std::max(a, b); }), decltype([]() { return std::numeric_limits<T>::lowest(); }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeMinimumQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return std::min(a, b); }), decltype([]() { return std::numeric_limits<T>::max(); }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeUnionQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return a + b; }), decltype([]() { return T{}; }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeOrQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return a | b; }), decltype([]() -> T { return 0; }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeAndQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return a & b; }), decltype([]() -> T { return ~static_cast<T>(0); }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeXorQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return a ^ b; }), decltype([]() -> T { return 0; }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeMulQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return a * b; }), decltype([]() -> T { return 1; }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeCompositeQuery = SegmentTreeWrapper<std::pair<T, T>, decltype([](const std::pair<T, T>& a, const std::pair<T, T>& b) { return std::pair<T, T>{ a.first * b.first, a.second * b.first + b.second }; }), decltype([]() { return std::pair<T, T>{ 1, 0 }; }), typename std::allocator_traits<Allocator>::template rebind_alloc<std::pair<T, T>>>;
template<class T, class Allocator = std::allocator<T>> using RangeGCDQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return std::gcd(a, b); }), decltype([]() -> T { return 0; }), Allocator>;
template<class T, class Allocator = std::allocator<T>> using RangeLCMQuery = SegmentTreeWrapper<T, decltype([](const T& a, const T& b) { return std::lcm(a, b); }), decltype([]() -> T { return 1; }), Allocator>;
#endif

#if defined(INCLUDE_LAZYSEGTREE)
template<class T, class F, class Operator, class Mapping, class Composition, class Allocator = std::allocator<T>> class LazySegmentTree {
    size_t sz = 0;
    std::vector<T, Allocator> tree;
    std::vector<F, typename std::allocator_traits<Allocator>::template rebind_alloc<F>> lazy;
    Operator f;
    Mapping g;
    Composition h;
    T e;
    F id;
#if __cplusplus >= 202001U
    constexpr size_t bitceil(size_t n) { return std::bit_ceil(n); }
#else
    constexpr size_t bitceil(size_t n) {
        size_t res = 1;
        while (res < n) res <<= 1;
        return res;
    }
#endif
    constexpr void eval(size_t n) {
        if (lazy[n] == id) return;
        tree[n] = g(lazy[n], tree[n]);
        if (n < sz - 1) {
            lazy[n * 2 + 1] = h(lazy[n * 2 + 1], lazy[n]);
            lazy[n * 2 + 2] = h(lazy[n * 2 + 2], lazy[n]);
        }
        lazy[n] = id;
    }
    constexpr void propagate(size_t cur) {
        if (cur != 1) propagate(cur >> 1);
        eval(cur - 1);
    }
public:
    class Operators {
        friend class LazySegmentTree;
        Operator f;
        Mapping g;
        Composition h;
    public:
        constexpr Operators(const Operator& f_, const Mapping& g_ = Mapping(), const Composition& h_ = Composition()) : f(f_), g(g_), h(h_) {}
        constexpr Operators(const Operator& f_, const Composition& h_) : f(f_), g(Mapping()), h(h_) {}
        constexpr Operators(const Mapping& g_, const Composition& h_ = Composition()) : f(Operator()), g(g_), h(h_) {}
        constexpr Operators(const Composition& h_) : f(Operator()), g(Mapping()), h(h_) {}
    };
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using operator_type = Operator;
    constexpr LazySegmentTree(const T& e_, const F& id_) : tree(Allocator()), lazy(Allocator()), f(Operator()), g(Mapping()), h(Composition()), e(e_), id(id_) {}
    constexpr explicit LazySegmentTree(const Operators& oprs, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : tree(alloc), lazy(alloc), f(oprs.f), g(oprs.g), h(oprs.h), e(e_), id(id_) {}
    constexpr explicit LazySegmentTree(const T& e_, const F& id_, const Allocator& alloc) : tree(alloc), lazy(alloc), f(Operator()), g(Mapping()), h(Composition()), e(e_), id(id_) {}
    constexpr explicit LazySegmentTree(size_type n, const Operators& oprs, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : sz(n), tree((bitceil(n) << 1) - 1, e_, alloc), lazy((bitceil(n) << 1) - 1, id_, alloc), f(oprs.f), g(oprs.g), h(oprs.h), e(e_), id(id_) {}
    constexpr explicit LazySegmentTree(size_type n, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : LazySegmentTree(n, Operators{ Operator(), Mapping(), Composition() }, e_, id_, alloc) {}
    constexpr LazySegmentTree(size_type n, const T& value, const Operators& oprs, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : LazySegmentTree(oprs, e_, id_, alloc) { assign(n, value); }
    constexpr LazySegmentTree(size_type n, const T& value, const T& e_, const F& id_, const Allocator& alloc) : LazySegmentTree(n, value, Operators{ Operator(), Mapping(), Composition() }, e_, id_, alloc) {}
    template<class InputIter> constexpr LazySegmentTree(InputIter first, InputIter last, const Operators& oprs, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : tree(alloc), lazy(alloc), f(oprs.f), g(oprs.g), h(oprs.h), e(e_), id(id_) { assign(first, last); }
    template<class InputIter> constexpr LazySegmentTree(InputIter first, InputIter last, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : LasySegmentTree(first, last, Operators{ Operator(), Mapping(), Composition() }, e_, id_, alloc) {}
    constexpr LazySegmentTree(const LazySegmentTree&) = default;
    constexpr LazySegmentTree(LazySegmentTree&&) = default;
    constexpr LazySegmentTree(const LazySegmentTree& x, const Allocator& alloc) : sz(x.sz), tree(x.tree, alloc), lazy(x.lazy, alloc), f(x.f), g(x.g), h(x.h), e(x.e), id(x.id) {}
    constexpr LazySegmentTree(LazySegmentTree&& y, const Allocator& alloc) : sz(y.sz), tree(std::move(y.tree), alloc), lazy(std::move(y.lazy), alloc), f(y.f), g(y.g), h(y.h), e(std::move(y.e)), id(std::move(y.id)) {}
    constexpr LazySegmentTree(std::initializer_list<T> init, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : LazySegmentTree(init.begin(), init.end(), Operators{ Operator(), Mapping(), Composition() }, e, id, alloc) {}
    constexpr LazySegmentTree(std::initializer_list<T> init, const Operators& oprs, const T& e_, const F& id_, const Allocator& alloc = Allocator()) : LazySegmentTree(init.begin(), init.end(), oprs, e_, id_, alloc) {}
    constexpr LazySegmentTree& operator=(const LazySegmentTree&) = default;
    constexpr LazySegmentTree& operator=(LazySegmentTree&&) noexcept(std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value || std::allocator_traits<Allocator>::is_always_equal::value) = default;
    constexpr LazySegmentTree& operator=(std::initializer_list<T> il) {
        assign(il);
        return *this;
    }
    constexpr size_type size() const noexcept { return sz; }
    constexpr void resize(size_type n) { resize(n, e); }
    constexpr void resize(size_type n, const T& c) {
        // TODO:
    }
    [[nodiscard]] bool empty() const noexcept { return sz == 0; }
    constexpr const_reference operator[](size_type n) const { return tree[n + tree.size() / 2]; }
    constexpr const_reference at(size_type n) const {
        if (n >= sz) throw std::out_of_range("LazySegmentTree::at / Index is out of range.");
        return tree[n + tree.size() / 2];
    }
    template<class InputIterator> constexpr void assign(InputIterator first, InputIterator last) {
        sz = std::distance(first, last);
        tree.assign((bitceil(sz) << 1) - 1, e);
        lazy.assign(tree.size(), id);
        size_t h = tree.size() / 2;
        InputIterator itr = first;
        for (size_t i = 0; i != sz; ++i, ++itr) {
            tree[h + i] = *itr;
        }
        for (size_t i = 0; i != h; ++i) {
            size_t tmp = h - i - 1;
            tree[tmp] = f(tree[(tmp << 1) + 1], tree[(tmp << 1) + 2]);
        }
    }
    constexpr void assign(size_type n, const value_type& u) {
        // TODO:
    }
    constexpr void assign(std::initializer_list<value_type> il) { assign(il.begin(), il.end()); }
    constexpr void swap(LazySegmentTree& x) noexcept(std::allocator_traits<Allocator>::propagate_on_container_swap::value || std::allocator_traits<Allocator>::is_always_equal::value) { std::swap(*this, x); };
    constexpr void clear() { sz = 0, tree.clear(), lazy.clear(); }
    constexpr allocator_type get_allocator() const noexcept { return tree.get_allocator(); }
    constexpr void set(size_type n, const value_type& x) {
        size_type i = n + (tree.size() >> 1);
        propagate(i + 1);
        tree[i] = x;
        while (i > 0) {
            i = (i - 1) >> 1;
            tree[i] = f(tree[(i << 1) + 1], tree[(i << 1) + 2]);
        }
    }
};
#endif

#if defined(INCLUDE_VEBTREE)
template<class T, size_t M> class vanEmdeBoasTree {
    class iterator_ {
        template<class U, size_t N> friend class vanEmdeBoasTree<U, N>;
        template<class U, size_t N> friend class vanEmdeBoasTree<U, N>::iterator_;
        const T* ptr = nullptr;
        constexpr iterator_(const T& x) { ptr = &x; }

    public:
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::contiguous_iterator_tag;
        constexpr reference operator*() const { return *ptr; }
        constexpr pointer operator->() const { return ptr; }
        constexpr iterator_() {}
        template<class U, size_t N> constexpr iterator_(const vanEmdeBoasTree<U, N>::iterator_& u) : ptr(u.ptr) {}
        template<class U, size_t N> constexpr iterator_& operator=(const vanEmdeBoasTree<U, N>::iterator_& u) { return ptr = u.ptr, *this; }
        template<class U1, size_t N1, class U2, size_t N2> friend constexpr bool operator==(const vanEmdeBoasTree<U1, N1>::iterator_& x, const vanEmdeBoasTree<U2, N2>::iterator_& y) { return x.ptr == y.ptr; }
        template<class U1, size_t N1, class U2, size_t N2> friend constexpr bool operator!=(const vanEmdeBoasTree<U1, N1>::iterator_& x, const vanEmdeBoasTree<U2, N2>::iterator_& y) { return x.ptr != y.ptr; }
    };

public:
    using key_type = T;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = iterator_;
    using const_iterator = iterator;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

private:
    using child_type = vanEmdeBoasTree<value_type, M / 2>;
    using aux_type = vanEmdeBoasTree<size_t, (M + 1) / 2>;
    constexpr static T null_value = static_cast<T>(1) << M;
    constexpr static size_t shift = M / 2;
    constexpr static T mask = (static_cast<T>(1) << (M / 2)) - 1;
    T minel = null_value, maxel = null_value;
    std::array<child_type, (M + 1) / 2> children;
    aux_type aux;
    size_type sz = 0;
    void children_init() {
        for (auto& child : children) child.child_type();
    }

public:
    constexpr vanEmdeBoasTree() { children_init(); }
    template<class InputIter> constexpr vanEmdeBoasTree(InputIter first, InputIter last) {
        for (auto itr = first; itr != last; ++itr) insert(*itr);
    }
    constexpr vanEmdeBoasTree(const vanEmdeBoasTree&) = default;
    constexpr vanEmdeBoasTree(std::initializer_list<value_type> init) : vanEmdeBoasTree(init.begin(), init.end()) {}
    constexpr vanEmdeBoasTree& operator=(const vanEmdeBoasTree& x) = default;
    constexpr vanEmdeBoasTree& operator=(std::initializer_list<value_type> init) {
        for (auto x : init) insert(x);
    }
    constexpr iterator begin() noexcept { return iterator(minel); }
    constexpr const_iterator begin() const noexcept { return const_iterator(minel); }
    constexpr const_iterator cbegin() const noexcept { return const_iterator(minel); }
    constexpr iterator end() noexcept { return iterator(); }
    constexpr const_iterator end() const noexcept { return const_iterator(); }
    constexpr const_iterator cend() const noexcept { return const_iterator(); }
    constexpr iterator rbegin() noexcept { return iterator(maxel); }
    constexpr const_iterator rbegin() const noexcept { return const_iterator(maxel); }
    constexpr const_iterator crbegin() const noexcept { return const_iterator(maxel); }
    constexpr iterator rend() noexcept { return iterator(); }
    constexpr const_iterator rend() const noexcept { return const_iterator(); }
    constexpr const_iterator crend() const noexcept { return const_iterator(); }
    [[nodiscard]] constexpr bool empty() const noexcept { return sz == 0; }
    constexpr size_type size() const noexcept { return sz; }
    constexpr size_type max_size() const noexcept { return size_type(1) << M; }
    constexpr void clear() noexcept {
        minel = null_value, maxel = null_value, sz = 0;
        aux.clear();
        for (auto& child : children) child.clear();
    }
    constexpr std::pair<iterator, bool> insert(const value_type& x) {
        if (empty()) {
            minel = maxel = x;
            ++sz;
            return std::pair{ iterator(minel), true };
        }
        if (x == minel) {
            return std::pair{ iterator(minel), false };
        }
        if (x < minel) {
            value_type tmp = std::move(minel);
            minel = x;
            auto [itr, f] = children[tmp >> shift].insert(tmp & mask);
            if (f) ++sz;
            return std::pair{ iterator(itr), f };
        }
        if (x > maxel) {
            maxel = x;
        }
        size_t i = x >> shift;
        if (children[i].empty()) aux.insert(i);
        auto [itr, f] = children[i].insert(x & mask);
        if (f) ++sz;
        return std::pair{ iterator(itr), f };
    }
    template<class InputIter> void insert(InputIter first, InputIter last) {
        for (auto itr = first; itr != last; ++itr) insert(*itr);
    }
    void insert(std::initializer_list<value_type> init) {
        for (auto& x : init) insert(x);
    }
    size_type erase(const key_type& x) {
        if (minel == x && maxel == x) {
            minel = maxel = null_value;
            --sz;
            return 1;
        }
        if (minel == x) {
            minel = x = aux.minel + children[aux.minel].minel;
        }
        return 0;
    }
};
#endif

#if defined(INCLUDE_FASTDSU) || defined(INCLUDE_ALL)
template<size_t sz> struct FastDSU {
    int parent[sz];
    constexpr void init(int n) {
        while (n--) parent[n] = -1;
    }
    constexpr int root(int n) {
        if (parent[n] < 0) return n;
        return parent[n] = root(parent[n]);
    }
    constexpr void merge(int a, int b) {
        int ra = root(a), rb = root(b);
        if (ra == rb) return;
        if (parent[ra] > parent[rb]) {
            parent[rb] += parent[ra];
            parent[ra] = rb;
        } else {
            parent[ra] += parent[rb];
            parent[rb] = ra;
        }
    }
    constexpr bool merge_or_same(int a, int b) {
        int ra = root(a), rb = root(b);
        if (ra == rb) return true;
        if (parent[ra] > parent[rb]) {
            parent[rb] += parent[ra];
            parent[ra] = rb;
        } else {
            parent[ra] += parent[rb];
            parent[rb] = ra;
        }
        return false;
    }
    constexpr bool same(int a, int b) { return root(a) == root(b); }
};
#endif

#if defined(INCLUDE_DSU) || defined(INCLUDE_ALL)
template<class Container = std::vector<int>> class DisjointSetUnion {
public:
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;
    using container_type = Container;
    using allocator_type = typename Container::allocator_type;
    static_assert(std::is_signed_v<value_type>, "DisjointSetUnion / Container::value_type must be signed.");

protected:
    Container parent;
    size_type counter = 0;

private:
    value_type root(value_type n) noexcept {
        if (parent[n] < 0) return n;
        return parent[n] = root(parent[n]);
    }

public:
    DisjointSetUnion() : parent() {}
    explicit DisjointSetUnion(size_type n) : parent(n, -1), counter(n) {}
    DisjointSetUnion(const DisjointSetUnion&) = default;
    DisjointSetUnion(DisjointSetUnion&&) = default;
    explicit DisjointSetUnion(const allocator_type& alloc) : parent(alloc) {}
    DisjointSetUnion(size_type n, const allocator_type& alloc) : parent(n, -1, alloc), counter(n) {}
    DisjointSetUnion(const DisjointSetUnion& x, const allocator_type& alloc) : parent(x.parent, alloc), counter(x.counter) {}
    DisjointSetUnion(DisjointSetUnion&& x, const allocator_type& alloc) : parent(std::move(x.parent), alloc), counter(x.counter) {}
    size_type size() const noexcept { return parent.size(); }
    [[nodiscard]] bool empty() const noexcept { return parent.empty(); }
    void resize(size_type n) {
        if (n < size()) throw std::invalid_argument("DisjointSetUnion::resize");
        counter += n - size();
        parent.resize(n, -1);
    }
    size_type leader(size_type n) {
        if (n >= size()) throw std::out_of_range("DisjointSetUnion::leader");
        return static_cast<size_type>(root(static_cast<value_type>(n)));
    }
    bool is_leader(size_type n) const {
        if (n >= size()) throw std::out_of_range("DisjointSetUnion::is_leader");
        return parent[n] < 0;
    }
    bool same(size_type a, size_type b) {
        if (a >= size() || b >= size()) throw std::out_of_range("DisjointSetUnion::same");
        return root(static_cast<value_type>(a)) == root(static_cast<value_type>(b));
    }
    bool merge(size_type a, size_type b) {
        if (a >= size() || b >= size()) throw std::out_of_range("DisjointSetUnion::merge");
        value_type ar = root(static_cast<value_type>(a)), br = root(static_cast<value_type>(b));
        if (ar == br) return false;
        if (parent[ar] < parent[br]) {
            parent[ar] += parent[br];
            parent[br] = ar;
        } else {
            parent[br] += parent[ar];
            parent[ar] = br;
        }
        --counter;
        return true;
    }
    size_type size(size_type n) {
        if (n >= size()) throw std::out_of_range("DisjointSetUnion::size");
        return -parent[root(static_cast<value_type>(n))];
    }
    size_type count_groups() const noexcept { return counter; }
    std::vector<value_type> extract(size_type n) {
        if (n >= size()) throw std::out_of_range("DisjointSetUnion::extract");
        int nr = root(static_cast<value_type>(n));
        std::vector<value_type> res;
        for (size_type i = 0, s = size(); i < s; ++i)
            if (root(static_cast<value_type>(i)) == nr) res.push_back(i);
        return res;
    }
    std::vector<std::vector<value_type>> groups() {
        value_type* key = parent.get_allocator().allocate(size());
        value_type cnt = 0;
        for (value_type i = 0, s = static_cast<value_type>(size()); i < s; ++i) {
            if (parent[i] >= 0) continue;
            key[i] = cnt++;
        }
        std::vector<std::vector<value_type>> res(cnt);
        for (value_type i = 0, s = static_cast<value_type>(size()); i < s; ++i) res[key[root(i)]].push_back(i);
        parent.get_allocator().deallocate(key, size());
        return res;
    }
};
template<class Container = std::vector<int>> using DSU = DisjointSetUnion<Container>;

template<class Abel, class Container = std::vector<int>> class WeightedDisjointSetUnion {
public:
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;
    using container_type = Container;
    using allocator_type = typename Container::allocator_type;
    using weight_type = Abel;
    static_assert(std::is_signed_v<value_type>, "WeightedDisjointSetUnion / Container::value_type must be signed.");

protected:
    Container parent;
    std::vector<weight_type> diff;
    size_type counter = 0;

private:
    value_type root(value_type n) noexcept {
        if (parent[n] < 0) return n;
        value_type r = root(parent[n]);
        diff[n] += diff[parent[n]];
        return parent[n] = r;
    }

public:
    WeightedDisjointSetUnion() : parent(), diff() {}
    explicit WeightedDisjointSetUnion(size_type n) : parent(n, -1), diff(n, 0), counter(n) {}
    WeightedDisjointSetUnion(const WeightedDisjointSetUnion&) = default;
    WeightedDisjointSetUnion(WeightedDisjointSetUnion&&) = default;
    explicit WeightedDisjointSetUnion(const allocator_type& alloc) : parent(alloc), diff(alloc) {}
    WeightedDisjointSetUnion(size_type n, const allocator_type& alloc) : parent(n, -1, alloc), diff(n, 0, alloc), counter(n) {}
    WeightedDisjointSetUnion(const WeightedDisjointSetUnion& x, const allocator_type& alloc) : parent(x.parent, alloc), diff(x.diff, alloc), counter(x.counter) {}
    WeightedDisjointSetUnion(WeightedDisjointSetUnion&& x, const allocator_type& alloc) : parent(std::move(x.parent), alloc), diff(std::move(x.diff), alloc), counter(x.counter) {}
    size_type size() const noexcept { return parent.size(); }
    [[nodiscard]] bool empty() const noexcept { return parent.empty(); }
    void resize(size_type n) {
        if (n < size()) throw std::invalid_argument("WeightedDisjointSetUnion::resize");
        counter += n - size();
        parent.resize(n, -1);
    }
    size_type leader(size_type n) {
        if (n >= size()) throw std::out_of_range("WeightedDisjointSetUnion::leader");
        return static_cast<size_type>(root(static_cast<value_type>(n)));
    }
    bool is_leader(size_type n) const {
        if (n >= size()) throw std::out_of_range("DisjointSetUnion::is_leader");
        return parent[n] < 0;
    }
    weight_type weight(size_type n) {
        if (n >= size()) throw std::out_of_range("WeightedDisjointSetUnion::weight");
        root(static_cast<value_type>(n));
        return diff[n];
    }
    bool same(size_type a, size_type b) {
        if (a >= size() || b >= size()) throw std::out_of_range("WeightedDisjointSetUnion::same");
        return root(static_cast<value_type>(a)) == root(static_cast<value_type>(b));
    }
    bool merge(size_type a, size_type b, const weight_type& w) {
        if (a >= size() || b >= size()) throw std::out_of_range("WeightedDisjointSetUnion::merge");
        value_type ar = root(static_cast<value_type>(a)), br = root(static_cast<value_type>(b));
        if (ar == br) return diff[a] - diff[b] == w;
        if (parent[ar] < parent[br]) {
            parent[ar] += parent[br];
            parent[br] = ar;
            diff[br] = -w + diff[a] - diff[b];
        } else {
            parent[br] += parent[ar];
            parent[ar] = br;
            diff[ar] = w - diff[a] + diff[b];
        }
        --counter;
        return true;
    }
    size_type size(size_type n) {
        if (n >= size()) throw std::out_of_range("WeightedDisjointSetUnion::size");
        return -parent[root(static_cast<value_type>(n))];
    }
    size_type count_groups() const noexcept { return counter; }
    std::vector<value_type> extract(size_type n) {
        if (n >= size()) throw std::out_of_range("WeightedDisjointSetUnion::extract");
        int nr = root(static_cast<value_type>(n));
        std::vector<value_type> res;
        for (size_type i = 0, s = size(); i < s; ++i)
            if (root(static_cast<value_type>(i)) == nr) res.push_back(i);
        return res;
    }
    std::vector<std::vector<value_type>> groups() {
        value_type* key = parent.get_allocator().allocate(size());
        value_type cnt = 0;
        for (value_type i = 0, s = static_cast<value_type>(size()); i < s; ++i) {
            if (parent[i] >= 0) continue;
            key[i] = cnt++;
        }
        std::vector<std::vector<value_type>> res(cnt);
        for (value_type i = 0, s = static_cast<value_type>(size()); i < s; ++i) res[key[root(i)]].push_back(i);
        parent.get_allocator().deallocate(key, size());
        return res;
    }
};
template<class Abel, class Container = std::vector<int>> using WDSU = WeightedDisjointSetUnion<Abel, Container>;
#endif

#if defined(INCLUDE_ASSOCIATIVEDSU)
template<class Container> class aDSU_impl {
public:
    using value_type = typename Container::key_type;
    using reference = value_type&;
    using const_reference = const reference;
    using size_type = size_t;
    using container_type = Container;
    using node_type = typename Container::value_type;
    using allocator_type = typename std::allocator_traits<typename Container::allocator_type>::template rebind_alloc<value_type>;

protected:
    Container c;
    size_type counter = 0;

private:
    node_type* root(node_type* n) noexcept {
        if (n->second.first == nullptr) return n;
        return (node_type*) (n->second.first = root((node_type*) (n->second.first)));
    }

public:
    aDSU_impl() : c() {}
    aDSU_impl(const aDSU_impl&) = default;
    aDSU_impl(aDSU_impl&&) = default;
    explicit aDSU_impl(const allocator_type& alloc) : c(alloc) {}
    aDSU_impl(const aDSU_impl& x, const allocator_type& alloc) : c(x.c, alloc) {}
    aDSU_impl(aDSU_impl&& x, const allocator_type& alloc) : c(std::forward(x.c), alloc) {}
    size_type size() const noexcept { return c.size(); }
    bool empty() const noexcept { return c.empty(); }
    void clear() noexcept { c.clear(), counter = 0; }
    bool insert(const value_type& n) {
        bool res = c.emplace(n, std::pair<void*, size_type>{ nullptr, 1 }).second;
        return counter += res, res;
    }
    bool insert(value_type&& n) {
        bool res = c.emplace(std::move(n), std::pair<void*, size_type>{ nullptr, 1 }).second;
        return counter += res, res;
    }
    template<class... Args> bool emplace(Args&&... args) {
        bool res = c.emplace(std::piecewise_construct, std::forward_as_tuple(args...), std::make_tuple(nullptr, 1)).second;
        return counter += res, res;
    }
    value_type leader(const value_type& n) {
        auto [itr, added] = c.emplace(n, std::pair<void*, size_type>{ nullptr, 1 });
        return counter += added, root(&*itr)->first;
    }
    bool same(const value_type& a, const value_type& b) {
        auto [itr1, added1] = c.emplace(a, std::pair<void*, size_type>{ nullptr, 1 });
        auto [itr2, added2] = c.emplace(b, std::pair<void*, size_type>{ nullptr, 1 });
        return counter += added1, counter += added2, root(&*itr1) == root(&*itr2);
    }
    bool merge(const value_type& a, const value_type& b) {
        auto [itr1, added1] = c.emplace(a, std::pair<void*, size_type>{ nullptr, 1 });
        auto [itr2, added2] = c.emplace(b, std::pair<void*, size_type>{ nullptr, 1 });
        counter += added1, counter += added2;
        node_type *ar = root(&*itr1), *br = root(&*itr2);
        if (ar == br) return false;
        if (ar->second.second >= br->second.second) {
            ar->second.second += br->second.second;
            br->second.first = ar;
        } else {
            br->second.second += ar->second.second;
            ar->second.first = br;
        }
        --counter;
        return true;
    }
    size_type size(const value_type& n) noexcept {
        auto [itr, added] = c.emplace(n, std::pair<void*, size_type>{ nullptr, 1 });
        counter += added;
        return itr->second.second;
    }
    size_type count_groups() const noexcept { return counter; }
    std::vector<value_type> extract(const value_type& n) noexcept {
        auto [itr, added] = c.emplace(n, std::pair<void*, size_type>{ nullptr, 1 });
        if (added) return std::vector<value_type>{ n };
        std::vector<value_type> res;
        node_type* nr = root(&*itr);
        for (auto& e : c)
            if (root(&e) == nr) res.emplace_back(e);
        return res;
    }
    std::vector<std::vector<value_type>> groups() {
        std::unordered_map<node_type*, size_type, std::hash<node_type*>, std::equal_to<node_type*>, typename std::allocator_traits<decltype(c.get_allocator())>::template rebind_alloc<std::pair<node_type* const, size_type>>> key(c.get_allocator());
        std::vector<std::vector<value_type>> res;
        for (auto& e : c) {
            auto [itr, added] = key.emplace(root(&e), res.size());
            if (added) {
                res.emplace_back();
                res.back().emplace_back(e.first);
            } else res[itr->second].emplace_back(e.first);
        }
        return res;
    }
};
template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T>> using AssociativeDisjointSetUnion = aDSU_impl<std::map<T, std::pair<void*, size_t>, Compare, typename std::allocator_traits<Allocator>::template rebind_alloc<std::pair<const T, std::pair<void*, size_t>>>>>;
template<class T, class Hash = std::hash<T>, class Pred = std::equal_to<T>, class Allocator = std::allocator<T>> using UnorderedAssociativeDisjointSetUnion = aDSU_impl<std::unordered_map<T, std::pair<void*, size_t>, Hash, Pred, typename std::allocator_traits<Allocator>::template rebind_alloc<std::pair<const T, std::pair<void*, size_t>>>>>;
template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T>> using aDSU = AssociativeDisjointSetUnion<T, Compare, Allocator>;
template<class T, class Hash = std::hash<T>, class Pred = std::equal_to<T>, class Allocator = std::allocator<T>> using unordered_aDSU = UnorderedAssociativeDisjointSetUnion<T, Hash, Pred, Allocator>;
#endif

#if defined(INCLUDE_HASHSET)
template<class Key, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>, class Allocator = std::allocator<Key>, bool Unique = true> class FastHashTable {
    using std::swap;
public:
    using key_type = Key;
    using value_type = Key;
    using hasher = Hash;
    using key_equal = Pred;
    using allocator_type = Allocator;
    using pointer = std::allocator_traits<Allocator>::pointer;
    using const_pointer = std::allocator_traits<Allocator>::const_pointer;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using iterator = value_type*;              //TODO
    using const_iterator = const value_type*;  //TODO
    using local_iterator = iterator;
    using const_local_iterator = const_iterator;
    using node_type = int;           //TODO
    using insert_return_type = int;  //TODO
private:
    using alloc_t = typename std::allocator_traits<allocator_type>::template rebind_alloc<char>;
    using traits = typename std::allocator_traits<alloc_t>;
    [[no_unique_address]] hasher hs;
    [[no_unique_address]] key_equal eq;
    [[no_unique_address]] alloc_t alloc;
    char* buckets;
    uint32_t* psl;
    uint32_t* idx;
    value_type* data;
    uint32_t mx;
    uint32_t sz;
    constexpr void new_buckets(uint32_t n) {
        mx = n, buckets = traits::allocate(alloc, mx * (2 * sizeof(uint32_t) + sizeof(value_type)));
        psl = static_cast<uint32_t*>(buckets), idx = static_cast<uint32_t*>(buckets + mx * sizeof(uint32_t));
        data = static_cast<value_type*>(buckets + 2 * mx * sizeof(uint32_t));
        std::memset(buckets, 0, 2 * mx * sizeof(uint32_t));
    }
    constexpr void del_buckets() { traits::deallocate(alloc, buckets, mx * (2 * sizeof(uint32_t) + sizeof(value_type))); }
    template<class... Args> constexpr void do_emplace(Args...&& args) {
        value_type n(std::forward<Args>(args)...);
        uint64_t h = hs(n);
        uint32_t lim = mx - 1;
        uint32_t q = (h >> 32) & 0xffff;
        uint32_t p = q + 65536;
        for (uint32_t i = h & lim; p != q; i = (i + 1) & lim, p += 65536) {
            if (psl[i] < p) {
                if (psl[i] == 0) {
                    psl[i] = p;
                    // TODO
                    return;
                }
                std::swap(n, data[idx[i]]);
            } else if constexpr (Unique) {
                if (psl[i] == p) {
                    //TODO
                }
            }
        }
    }
    constexpr int min_bucket_size = 16;
public:
    constexpr FastHashTable();
    constexpr explicit FastHashTable(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
    template<class InputIterator> constexpr FastHashTable(InputIterator first, InputIterator last, size_type n = min_bucket_size, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
    constexpr FastHashTable(const FastHashTable& v);
    constexpr FastHashTable(FastHashTable&& rv);
    constexpr explicit FastHashTable(const allocator_type& a);
    constexprFastHashTable(const FastHashTable& v, const allocator_type& a);
    constexpr FastHashTable(FastHashTable&& rv, const allocator_type& a);
    constexpr FastHashTable(initializer_list<value_type> il, size_type n = min_bucket_size, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
    constexpr FastHashTable(size_type n, const allocator_type& a);
    constexpr FastHashTable(size_type n, const hasher& hf, const allocator_type& a);
    template<class InputIterator> constexpr FastHashTable(InputIterator f, InputIterator l, size_type n, const allocator_type& a);
    template<class InputIterator> constexpr FastHashTable(InputIterator f, InputIterator l, size_type n, const hasher& hf, const allocator_type& a);
    constexpr FastHashTable(std::initializer_list<value_type> il, size_type n, const allocator_type& a);
    constexpr FastHashTable(std::initializer_list<value_type> il, size_type n, const hasher& hf, const allocator_type& a);
    constexpr ~FastHashTable();
    constexpr FastHashTable& operator=(const FastHashTable& v);
    constexpr FastHashTable& operator=(FastHashTable&& x) noexcept(std::allocator_traits<Allocator>::is_always_equal::value && std::is_nothrow_move_assignable<Hash>::value);
    constexpr FastHashTable& operator=(std::initializer_list<value_type> il);
    [[nodiscard]] constexpr bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr allocator_type get_allocator() const noexcept;
    template<class... Args> constexpr std::pair<iterator, bool> emplace(Args&&... args);
    template<class... Args> constexpr iterator emplace_hint([[maybe_unused]] const_iterator position, Args&&... args);
    constexpr std::pair<iterator, bool> insert(const value_type& v);
    constexpr std::pair<iterator, bool> insert(value_type&& rv);
    constexpr iterator insert(const_iterator position, const value_type& v);
    constexpr iterator insert(const_iterator position, value_type&& rv);
    template<class InputIterator> constexpr void insert(InputIterator first, InputIterator last);
    constexpr void insert(initializer_list<value_type> il);
    constexpr insert_return_type insert(node_type&& nh);
    constexpr iterator insert(const_iterator hint, node_type&& nh);
    constexpr iterator erase(iterator position);
    constexpr iterator erase(const_iterator position);
    constexpr size_type erase(const key_type& k);
    constexpr iterator erase(const_iterator first, const_iterator last);
    constexpr void clear() noexcept;
    constexpr void swap(FastHashTable& v);
    constexpr void swap(FastHashTable& x) noexcept(std::allocator_traits<Allocator>::is_always_equal::value&& noexcept(swap(std::declval<Hash&>(), std::declval<Hash&>())) && noexcept(swap(std::declval<Pred&>(), std::declval<Pred&>())));
    constexpr node_type extract(const_iterator position);
    constexpr node_type extract(const key_type& x);
    template<class H2, class P2, bool U2> constexpr void merge(FastHashTable<Key, H2, P2, Allocator, U2>& source);
    template<class H2, class P2, bool U2> constexpr void merge(FastHashTable<Key, H2, P2, Allocator, U2>&& source);
    constexpr hasher hash_function() const;
    constexpr key_equal key_eq() const;
    constexpr iterator find(const key_type& x);
    constexpr const_iterator find(const key_type& x) const;
    template<class K> constexpr iterator find(const K& k);
    template<class K> constexpr const_iterator find(const K& k) const;
    constexpr size_type count(const key_type& x) const;
    template<class K> constexpr size_type count(const K& k) const;
    constexpr bool contains(const key_type& x) const;
    template<class K> constexpr bool contains(const K& k) const;
    constexpr std::pair<iterator, iterator> equal_range(const key_type& x);
    constexpr std::pair<const_iterator, const_iterator> equal_range(const key_type& x) const;
    template<class K> constexpr std::pair<iterator, iterator> equal_range(const K& k);
    template<class K> constexpr std::pair<const_iterator, const_iterator> equal_range(const K& k) const;
    constexpr size_type bucket_count() const noexcept;
    constexpr size_type max_bucket_count() const noexcept;
    constexpr size_type bucket_size(size_type n) const;
    constexpr size_type bucket(const key_type& k) const;
    constexpr local_iterator begin(size_type n);
    constexpr const_local_iterator begin(size_type n) const;
    constexpr local_iterator end(size_type n);
    constexpr const_local_iterator end(size_type n) const;
    constexpr const_local_iterator cbegin(size_type n) const;
    constexpr const_local_iterator cend(size_type n) const;
    constexpr float load_factor() const noexcept;
    constexpr float max_load_factor() const noexcept;
    constexpr void max_load_factor(float z);
    constexpr void rehash(size_type n);
    constexpr void reserve(size_type n);
};
#endif

#if defined(INCLUDE_GRAPH) || defined(INCLUDE_ALL)
template<class Weight> class GraphBase;
namespace Graph {
template<class Weight> struct Edge {
    friend class GraphBase<Weight>;
    using weight_type = Weight;
    size_t to;
    Weight weight;
    constexpr operator size_t() const noexcept { return to; }
private:
    constexpr Edge(size_t t = 0, Weight w = {}) : to(t), weight(w) {}
};
template<> struct Edge<void> {
    friend class GraphBase<void>;
    using weight_type = size_t;
    size_t to;
    constexpr operator size_t() const noexcept { return to; }
private:
    constexpr Edge(size_t t = 0) : to(t) {}
};

#if __GNUC__ >= 12
struct dsu {
    std::vector<int> par;
    constexpr dsu(size_t n) : par(n, -1) {}
    constexpr int root(int n) {
        if (par[n] < 0) return n;
        return par[n] = root(par[n]);
    }
    constexpr bool merge(int a, int b) {
        int ar = root(a), br = root(b);
        if (ar == br) return false;
        if (par[ar] < par[br]) {
            par[ar] += par[br];
            par[br] = ar;
        } else {
            par[br] += par[ar];
            par[ar] = br;
        }
        return true;
    }
};
#else
struct dsu {
    std::vector<int> par;
    dsu(size_t n) : par(n, -1) {}
    int root(int n) {
        if (par[n] < 0) return n;
        return par[n] = root(par[n]);
    }
    bool merge(int a, int b) {
        int ar = root(a), br = root(b);
        if (ar == br) return false;
        if (par[ar] < par[br]) {
            par[ar] += par[br];
            par[br] = ar;
        } else {
            par[br] += par[ar];
            par[ar] = br;
        }
        return true;
    }
};
#endif

}  // namespace Graph

template<class Weight> class GraphBase {
public:
    using edge_type = Graph::Edge<Weight>;
    using weight_type = typename edge_type::weight_type;
    constexpr static bool is_weighted = !std::is_void_v<Weight>;
private:
    struct node {
        edge_type edge;
        node* next;
        constexpr node(size_t t, node* p) : edge(t), next(p) {}
        constexpr node(size_t t, const weight_type& w, node* p) : edge(t, w), next(p) {}
        constexpr node(const node&) = delete;
    };
    std::vector<node*> vertices;
    std::vector<std::unique_ptr<node[]>> edges;
    size_t edges_last = 0;
protected:
    constexpr void connect(size_t from, size_t to) {
        if (edges_last == 0) [[unlikely]]
            edges.emplace_back(static_cast<node*>(::operator new[]((1ull << edges.size()) * sizeof(node))));
        node* tmp = vertices[from];
        vertices[from] = edges.back().get() + edges_last;
        new (vertices[from]) node(to, tmp);
        edges_last *= (++edges_last != (1ull << (edges.size() - 1)));
    }
    constexpr void connect(size_t from, size_t to, const weight_type& w) {
        if (edges_last == 0) [[unlikely]]
            edges.emplace_back(static_cast<node*>(::operator new[]((1ull << edges.size()) * sizeof(node))));
        node* tmp = vertices[from];
        vertices[from] = edges.back().get() + edges_last;
        new (vertices[from]) node(to, w, tmp);
        edges_last *= (++edges_last != (1ull << (edges.size() - 1)));
    }
public:
    constexpr GraphBase() : vertices() {}
    constexpr GraphBase(size_t n) : vertices(n, nullptr) {}
    constexpr GraphBase(const GraphBase&) = default;
    constexpr GraphBase(GraphBase&&) = default;
protected:
#if __GNUC__ >= 12
    constexpr ~GraphBase() = default;
#else
    ~GraphBase() = default;
#endif
public:
    class AdjacencyList {
        friend class GraphBase;
    protected:
        size_t vertex;
        const GraphBase& graph;
        constexpr AdjacencyList(size_t n, const GraphBase& ref) noexcept : vertex(n), graph(ref) {}
    public:
        class iterator {
            friend class AdjacencyList;
            const node* ptr;
            constexpr iterator(const node* p) noexcept : ptr(p) {}
        public:
            constexpr const edge_type& operator*() const noexcept { return ptr->edge; }
            constexpr const edge_type* operator->() const noexcept { return &(ptr->edge); }
            constexpr iterator& operator++() noexcept {
                ptr = ptr->next;
                return *this;
            }
            constexpr iterator& operator++(int) noexcept {
                iterator copy(*this);
                ptr = ptr->next;
                return copy;
            }
            constexpr bool operator==(iterator r) noexcept { return ptr == r.ptr; }
            constexpr bool operator!=(iterator r) noexcept { return ptr != r.ptr; }
        };
        using const_iterator = iterator;
        constexpr iterator begin() noexcept { return iterator(graph.vertices[vertex]); }
        constexpr const_iterator begin() const noexcept { return const_iterator(graph.vertices[vertex]); }
        constexpr const_iterator cbegin() const noexcept { return const_iterator(graph.vertices[vertex]); }
        constexpr iterator end() noexcept { return iterator(nullptr); }
        constexpr const_iterator end() const noexcept { return const_iterator(nullptr); }
        constexpr const_iterator cend() const noexcept { return const_iterator(nullptr); }
        constexpr operator size_t() const noexcept { return vertex; }
    };
    class iterator : AdjacencyList {
        friend class GraphBase;
    protected:
        using AdjacencyList::vertex, AdjacencyList::graph;
        constexpr iterator(size_t n, const GraphBase& ref) : AdjacencyList(n, ref) {}
    public:
        constexpr const AdjacencyList& operator*() const noexcept { return *this; }
        constexpr const AdjacencyList* operator->() const noexcept { return this; }
        constexpr iterator& operator++() noexcept {
            ++vertex;
            return *this;
        }
        constexpr iterator& operator++(int) noexcept {
            iterator copy(*this);
            ++vertex;
            return copy;
        }
        constexpr bool operator==(const iterator& r) noexcept { return vertex == r.vertex && (&graph) == (&r.graph); }
        constexpr bool operator!=(const iterator& r) noexcept { return vertex != r.vertex || (&graph) != (&r.graph); }
    };
    using const_iterator = iterator;
    constexpr iterator begin() noexcept { return iterator(0, *this); }
    constexpr const_iterator begin() const noexcept { return const_iterator(0, *this); }
    constexpr const_iterator cbegin() const noexcept { return const_iterator(0, *this); }
    constexpr iterator end() noexcept { return iterator(count_vertices(), *this); }
    constexpr const_iterator end() const noexcept { return const_iterator(count_vertices(), *this); }
    constexpr const_iterator cend() const noexcept { return const_iterator(count_vertices(), *this); }
    constexpr inline static weight_type inf = std::numeric_limits<weight_type>::max();
    constexpr size_t count_vertices() const noexcept { return vertices.size(); }
protected:
    constexpr size_t count_edges_impl() const noexcept { return edges.empty() ? 0 : (1ull << (edges.size() - 1)) - 1 + edges_last; }
public:
    constexpr AdjacencyList operator[](size_t n) const {
        if (n >= count_vertices()) throw std::out_of_range("GraphBase::operator[] / Index is out of range");
        return AdjacencyList(n, *this);
    }
};

template<class Weight = void> class DirectedGraph : public GraphBase<Weight> {
    using base = GraphBase<Weight>;
    std::vector<size_t> ideg, odeg;
public:
    using edge_type = typename base::edge_type;
    using weight_type = typename base::weight_type;
    constexpr DirectedGraph() : base() {}
    constexpr DirectedGraph(size_t n) : base(n), ideg(n), odeg(n) {}
    constexpr DirectedGraph(const DirectedGraph&) = default;
    constexpr DirectedGraph(DirectedGraph&&) = default;
    constexpr DirectedGraph& connect(size_t n, size_t m) {
        if (n >= base::count_vertices() || m >= base::count_vertices()) throw std::out_of_range("DirectedGraph::connect / Index is out of range");
        ++odeg[n], ++ideg[m];
        base::connect(n, m);
        return *this;
    }
    constexpr DirectedGraph& connect(size_t n, size_t m, weight_type w) {
        if (n >= base::count_vertices() || m >= base::count_vertices()) throw std::out_of_range("DirectedGraph::connect / Index is out of range");
        ++odeg[n], ++ideg[m];
        base::connect(n, m, w);
        return *this;
    }
    constexpr size_t count_edges() const noexcept { return base::count_edges_impl(); }
    constexpr size_t indegree(size_t n) const {
        if (n >= base::count_vertices()) throw std::out_of_range("DirectedGraph::indegree / Index is out of range");
        return ideg[n];
    }
    constexpr const std::vector<size_t>& indegree() const { return ideg; }
    constexpr size_t outdegree(size_t n) const {
        if (n >= base::count_vertices()) throw std::out_of_range("DirectedGraph::outdegree / Index is out of range");
        return odeg[n];
    }
    constexpr const std::vector<size_t>& outdegree() const { return odeg; }
};

template<class Weight = void> class UndirectedGraph : public GraphBase<Weight> {
    using base = GraphBase<Weight>;
    std::vector<size_t> deg;
public:
    using edge_type = typename base::edge_type;
    using weight_type = typename base::weight_type;
    constexpr UndirectedGraph() : base() {}
    constexpr UndirectedGraph(size_t n) : base(n), deg(n) {}
    constexpr UndirectedGraph(const UndirectedGraph&) = default;
    constexpr UndirectedGraph(UndirectedGraph&&) = default;
    constexpr UndirectedGraph& connect(size_t n, size_t m) {
        if (n >= base::count_vertices() || m >= base::count_vertices()) throw std::out_of_range("UndirectedGraph::connect / Index is out of range");
        ++deg[n], ++deg[m];
        base::connect(n, m);
        base::connect(m, n);
        return *this;
    }
    constexpr UndirectedGraph& connect(size_t n, size_t m, weight_type w) {
        if (n >= base::count_vertices() || m >= base::count_vertices()) throw std::out_of_range("UndirectedGraph::connect / Index is out of range");
        ++deg[n], ++deg[m];
        base::connect(n, m, w);
        base::connect(m, n, w);
        return *this;
    }
    constexpr size_t count_edges() const noexcept { return base::count_edges_impl() >> 1; }
    constexpr size_t degree(size_t n) const {
        if (n >= base::count_vertices()) throw std::out_of_range("UndirectedGraph::degree / Index is out of range");
        return deg[n];
    }
    constexpr const std::vector<size_t>& degree() const { return deg; }
    constexpr auto toDirected() const {
        DirectedGraph<weight_type> res(base::count_vertices());
        for (size_t i = 0, n = base::count_vertices(); i != n; ++i) {
            for (auto [j, cost] : base::operator[](i)) {
                res.connect(i, j, cost);
            }
        }
        return res;
    }
    constexpr operator DirectedGraph<weight_type>() const { return toDirected(); }
};

struct ConnectedComponents {
    std::vector<std::vector<size_t>> vertex;
    std::vector<size_t> aff;
#if __GNUC__ >= 12
    constexpr size_t size() const noexcept { return aff.size(); }
    [[nodiscard]] constexpr bool empty() const noexcept { return aff.empty(); }
    constexpr size_t leader(size_t n) const { return vertex[aff[n]][0]; }
    constexpr size_t is_leader(size_t n) const { return vertex[aff[n]][0] == n; }
    constexpr bool same(size_t a, size_t b) const { return aff[a] == aff[b]; }
    constexpr size_t size(size_t n) const { return vertex[aff[n]].size(); }
    constexpr size_t count_groups() const { return vertex.size(); }
    constexpr const std::vector<size_t>& extract(size_t n) const { return vertex[aff[n]]; }
    constexpr const std::vector<std::vector<size_t>>& groups() const { return vertex; }
    constexpr size_t affiliation(size_t n) const { return aff[n]; }
    constexpr const std::vector<size_t>& affiliation() const { return aff; }
#else
    size_t size() const noexcept { return aff.size(); }
    [[nodiscard]] bool empty() const noexcept { return aff.empty(); }
    size_t leader(size_t n) const { return vertex[aff[n]][0]; }
    size_t is_leader(size_t n) const { return vertex[aff[n]][0] == n; }
    bool same(size_t a, size_t b) const { return aff[a] == aff[b]; }
    size_t size(size_t n) const { return vertex[aff[n]].size(); }
    size_t count_groups() const { return vertex.size(); }
    const std::vector<size_t>& extract(size_t n) const { return vertex[aff[n]]; }
    const std::vector<std::vector<size_t>>& groups() const { return vertex; }
    size_t affiliation(size_t n) const { return aff[n]; }
    const std::vector<size_t>& affiliation() const { return aff; }
#endif
    template<class DG> constexpr DG to_directedgraph(const DG& g) const {
        if (aff.size() != g.count_vertices()) throw std::runtime_error("ConnectedComponents::to_directedgraph / The number of vertices does not match.");
        size_t N = aff.size();
        DG res(N);
        for (size_t i = 0; i != N; ++i) {
            if constexpr (DG::is_weighted) {
                for (auto [j, w] : g[i]) {
                    if (aff[i] == aff[j]) res.connect(i, j, w);
                }
            } else {
                for (size_t j : g[i]) {
                    if (aff[i] == aff[j]) res.connect(i, j);
                }
            }
        }
        return res;
    }
    template<class UG> constexpr UG to_undirectedgraph(const UG& g) const {
        if (aff.size() != g.count_vertices()) throw std::runtime_error("ConnectedComponents::to_undirectedgraph / The number of vertices does not match.");
        size_t N = aff.size();
        UG res(N);
        for (size_t i = 0; i != N; ++i) {
            if constexpr (UG::is_weighted) {
                for (auto [j, w] : g[i]) {
                    if (i < j && aff[i] == aff[j]) res.connect(i, j, w);
                }
            } else {
                for (size_t j : g[i]) {
                    if (i < j && aff[i] == aff[j]) res.connect(i, j);
                }
            }
        }
        return res;
    }
};

template<class UG> constexpr size_t CountConnectedComponents(const UG& g) {
    size_t N = g.count_vertices();
    Graph::dsu uf(N);
    size_t res = N;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j : g[i])
            if (uf.merge(i, j)) --res;
    }
    return res;
}
template<class UG> constexpr bool isConnectedGraph(const UG& g) {
    return CountConnectedComponents(g) == 1;
}
template<class UG> constexpr bool isPathGraph(const UG& g) {
    if (g.count_vertices() - 1 != g.count_edges()) return false;
    for (size_t i = 0, n = g.count_vertices(); i != n; ++i) {
        size_t cnt = 0;
        for ([[maybe_unused]] auto& tmp : g[i]) ++cnt;
        if (cnt > 2) return false;
    }
    return isConnectedGraph(g);
}
template<class UG> constexpr bool isTree(const UG& g) {
    if (g.count_vertices() - 1 != g.count_edges()) return false;
    return isConnectedGraph(g);
}

template<class DG> constexpr std::vector<size_t> TopologicalSort(const DG& g) {
    size_t N = g.count_vertices();
    std::vector<size_t> res;
    res.reserve(N);
    std::vector<size_t> d = g.indegree();
    std::vector<size_t> s;
    for (size_t i = 0; i != N; ++i)
        if (d[i] == 0) s.push_back(i);
    size_t cnt = 0;
    while (!s.empty()) {
        ++cnt;
        size_t n = s.back();
        s.pop_back();
        res.push_back(n);
        for (size_t m : g[n]) {
            if (--d[m] == 0) s.push_back(m);
        }
    }
    if (cnt != N) res.clear();
    return res;
}
template<class DG, class Comp> constexpr std::vector<size_t> TopologicalSort(const DG& g, const Comp& c = Comp()) {
    size_t N = g.count_vertices();
    std::vector<size_t> res;
    res.reserve(N);
    std::vector<size_t> d = g.indegree();
    auto comp = [&c](size_t a, size_t b) {
        return !c(a, b);
    };
    std::priority_queue<size_t, std::vector<size_t>, decltype(comp)> s(comp);
    for (size_t i = 0; i != N; ++i)
        if (d[i] == 0) s.push(i);
    size_t cnt = 0;
    while (!s.empty()) {
        ++cnt;
        size_t n = s.top();
        s.pop();
        res.push_back(n);
        for (size_t m : g[n]) {
            if (--d[m] == 0) s.push(m);
        }
    }
    if (cnt != N) res.clear();
    return res;
}


template<class DG> constexpr std::vector<size_t> LongestPathLength(const DG& g) {
    size_t N = g.count_vertices();
    std::vector<size_t> res(N);
    std::vector<size_t> d = g.indegree();
    std::vector<size_t> s;
    for (size_t i = 0; i != N; ++i)
        if (d[i] == 0) s.push_back(i);
    size_t cnt = 0;
    while (!s.empty()) {
        ++cnt;
        size_t n = s.back();
        s.pop_back();
        for (size_t m : g[n]) {
            res[m] = std::max(res[m], res[n] + 1);
            if (--d[m] == 0) s.push_back(m);
        }
    }
    if (cnt != N) res.clear();
    return res;
}

template<class G> constexpr auto TravelingSalesmanProblemLength(const G& g) {
    const size_t N = g.count_vertices();
    if (N >= 32) throw std::runtime_error("TravelingSalesmanProblemLength / The number of vertices is too large.");
    constexpr auto e = std::numeric_limits<typename G::weight_type>::max();
    std::vector dist(N, std::vector(N, e));
    std::vector<size_t> mask(N);
    for (size_t i = 0; i != N; ++i) {
        for (auto [j, w] : g[i]) dist[i][j] = (dist[i][j] < w ? dist[i][j] : w);
        for (size_t j = 0; j != N; ++j)
            if (dist[i][j] != e) mask[i] |= (1ull << j);
    }
    std::vector dp(1ull << N, std::vector(N, e));
    dp[1][0] = 0;
    for (size_t i = 1; i != (1ull << N); ++i) {
        const size_t u = (~i) & ((1ull << N) - 1);
        for (size_t s = i; s != 0;) {
            const int n = std::countr_zero(s);
            s ^= 1ull << n;
            const auto x = dp[i][n];
            if (dp[i][n] == e) continue;
            for (size_t t = u & mask[n]; t != 0;) {
                const size_t m = std::countr_zero(t);
                const auto a = dp[i | (1ull << m)][m];
                const auto b = x + dist[n][m];
                dp[i | (1ull << m)][m] = (a < b ? a : b);
                t ^= 1ull << m;
            }
        }
    }
    auto res = e;
    for (size_t i = 0; i != N; ++i) {
        const auto d = dp[(1ull << N) - 1][i] + dist[i][0];
        res = (res < d ? res : d);
    }
    return res;
}

namespace Graph {
namespace ShortestPath {
    class BFS {};
    class DPonDAG {};
    class Dijkstra {};
    class BFS01 {};
    class BellmanFord {};
    class DFSonTree {};
    class SPFA {};
    class FloydWarshall {};
}  // namespace ShortestPath
template<class G> struct ShortestPathResult {
    constexpr static size_t e = std::numeric_limits<size_t>::max();
    constexpr static auto inf = std::numeric_limits<typename G::weight_type>::max();
    std::vector<size_t> prev;
    std::vector<typename G::weight_type> dist;
    constexpr ShortestPathResult(size_t n) : prev(n, e), dist(n, inf) {}
    constexpr size_t size() const noexcept { return prev.size(); }
    constexpr auto distance(size_t n) const { return dist[n]; }
    constexpr const std::vector<typename G::weight_type>& distance() const { return dist; }
    constexpr std::vector<size_t> path(size_t n) const {
        if (dist[n] == inf) return std::vector<size_t>{};
        std::vector<size_t> res;
        while (n != e) {
            res.push_back(n);
            n = prev[n];
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    constexpr auto tree() const {
        DirectedGraph res(prev.size());
        for (size_t i = 0, n = prev.size(); i != n; ++i) {
            if (prev[i] == e) continue;
            res.connect(prev[i], i);
        }
        return res;
    }
    constexpr auto weighted_tree() const {
        DirectedGraph<typename G::weight_type> res(prev.size());
        for (size_t i = 0, n = prev.size(); i != n; ++i) {
            if (prev[i] == e) continue;
            res.connect(prev[i], i, dist[i] - dist[prev[i]]);
        }
        return res;
    }
};
}  // namespace Graph
template<class Algorithm, class G> Graph::ShortestPathResult<G> ShortestPath(const G& g, size_t n) {
    size_t N = g.count_vertices();
    Graph::ShortestPathResult<G> res(N);
    res.dist[n] = 0;
    if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::BFS>) {
        std::basic_string<bool> seen(N, false);
        std::vector<size_t> q(N);
        size_t push = 0, pop = 0;
        q[push++] = n;
        seen[n] = true;
        while (push != pop) {
            size_t node = q[pop++];
            for (size_t next : g[node]) {
                if (seen[next]) continue;
                res.dist[next] = res.dist[node] + 1;
                res.prev[next] = node;
                q[push++] = next;
                seen[next] = true;
            }
        }
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::DPonDAG>) {
        std::vector<size_t> indeg(N);
        std::vector<size_t> q(N);
        size_t push = 0, pop = 0;
        q[push++] = n;
        std::basic_string<bool> seen(N, false);
        seen[n] = true;
        while (push != pop) {
            size_t node = q[pop++];
            for (size_t next : g[node]) {
                ++indeg[next];
                if (seen[next]) continue;
                seen[next] = true;
                q[push++] = next;
            }
        }
        push = 0, pop = 0;
        q[push++] = n;
        while (push != pop) {
            size_t node = q[pop++];
            for (auto [next, cost] : g[node]) {
                if (!indeg[next]) continue;
                if (--indeg[next] == 0) {
                    q[push++] = next;
                    auto d = res.dist[node] + cost;
                    if (d < res.dist[next]) {
                        res.dist[next] = d;
                        res.prev[next] = node;
                    }
                }
            }
        }
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::BFS01>) {
        std::basic_string<bool> seen(N, false);
        std::vector<size_t> q(2 * N);
        size_t front = N, back = N;
        q[back++] = n;
        while (front != back) {
            size_t node = q[front++];
            if (seen[node]) continue;
            seen[node] = true;
            for (auto [next, cost] : g[node]) {
                bool c = static_cast<bool>(cost);
                auto d = res.dist[node] + c;
                if (d < res.dist[next]) {
                    res.dist[next] = d;
                    res.prev[next] = node;
                    if (c) q[back++] = next;
                    else q[--front] = next;
                }
            }
        }
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::Dijkstra>) {
        std::vector<std::pair<typename G::weight_type, size_t>> q;
        q.reserve(N);
        constexpr size_t e = std::numeric_limits<size_t>::max();
        std::vector<size_t> loc(N, e);
        auto prioritize = [&](size_t n) {
            auto tmp = q[loc[n]];
            for (size_t i = loc[n], p; i != 0; i = p) {
                p = (i - 1) >> 1;
                if (q[p].first <= tmp.first) {
                    q[i] = tmp;
                    loc[n] = i;
                    return;
                }
                loc[q[p].second] = i;
                q[i] = q[p];
            }
            q[0] = tmp;
            loc[q[0].second] = 0;
        };
        auto push = [&](size_t n, typename G::weight_type w) {
            loc[n] = q.size();
            q.emplace_back(w, n);
            prioritize(n);
        };
        auto pop = [&]() {
            loc[q[0].second] = e;
            std::swap(q[0], q.back());
            q.pop_back();
            auto tmp = q[0];
            size_t i = 0, m = q.size() >> 1;
            while (i < m) {
                size_t l = (i << 1) + 1, r = (i << 1) + 2;
                if (q[l].first <= q[r].first) {
                    if (tmp.first <= q[l].first) break;
                    loc[q[l].second] = i;
                    q[i] = q[l];
                    i = l;
                } else {
                    if (tmp.first <= q[r].first) break;
                    loc[q[r].second] = i;
                    q[i] = q[r];
                    i = r;
                }
            }
            loc[tmp.second] = i;
            q[i] = tmp;
        };
        push(n, 0);
        while (!q.empty()) {
            auto [d, node] = q[0];
            pop();
            for (auto [next, cost] : g[node]) {
                auto tmp = d + cost;
                if (res.dist[next] <= tmp) continue;
                res.dist[next] = tmp;
                res.prev[next] = node;
                if (loc[next] == e) push(next, tmp);
                else {
                    q[loc[next]].first = tmp;
                    prioritize(next);
                }
            }
        }
        /*
        using node_type = std::pair<typename G::weight_type, size_t>;
        std::vector<node_type> c;
        c.reserve(g.count_vertices());
        std::priority_queue<node_type, std::vector<node_type>, std::greater<node_type>> q(std::greater<node_type>{}, std::move(c));
        q.emplace(0, n);
        while (!q.empty()) {
            auto [d, node] = q.top();
            q.pop();
            if (d > res.dist[node]) continue;
            for (auto [next, cost] : g[node]) {
                if (d + cost >= res.dist[next]) continue;
                q.emplace(d + cost, next);
                res.dist[next] = d + cost;
                res.prev[next] = node;
            }
        }
        */
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::BellmanFord>) {
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::DFSonTree>) {
        std::vector<std::pair<size_t, size_t>> s;
        s.reserve(N);
        s.emplace_back(n, std::numeric_limits<size_t>::max());
        while (!s.empty()) {
            auto [node, prev] = s.back();
            s.pop_back();
            for (auto [next, cost] : g[node]) {
                if (next == prev) continue;
                res.dist[next] = res.dist[node] + cost;
                res.prev[next] = node;
                s.emplace_back(next, node);
            }
        }
    } else if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::SPFA>) {
    } else {
        static_assert(std::conditional_t<false, Algorithm, bool>{}, "ShortestPath / Template parameter 'Algorithm' is invalid.");
    }
    return res;
}
template<class Algorithm, class G> constexpr std::vector<Graph::ShortestPathResult<G>> ShortestPath(const G& g) {
    size_t N = g.count_vertices();
    if constexpr (std::is_same_v<Algorithm, Graph::ShortestPath::FloydWarshall>) {
        std::vector<Graph::ShortestPathResult<G>> res(N, Graph::ShortestPathResult<G>(N));
        for (size_t i = 0; i != N; ++i) {
            res[i].dist[i] = 0;
            for (auto [j, w] : g[i]) {
                if (w < res[i].dist[j]) {
                    res[i].dist[j] = w;
                    res[i].prev[j] = i;
                }
            }
        }
        for (size_t k = 0; k != N; ++k) {
            for (size_t i = 0; i != N; ++i) {
                for (size_t j = 0; j != N; ++j) {
                    if (res[i].dist[k] != Graph::ShortestPathResult<G>::inf && res[k].dist[j] != Graph::ShortestPathResult<G>::inf && res[i].dist[j] > res[i].dist[k] + res[k].dist[j]) {
                        res[i].dist[j] = res[i].dist[k] + res[k].dist[j];
                        res[i].prev[j] = res[k].prev[j];
                    }
                }
            }
        }
        return res;
    } else {
        std::vector<Graph::ShortestPathResult<G>> res;
        for (size_t i = 0; i != N; ++i) res.emplace_back(ShortestPath<Algorithm>(g, i));
        return res;
    }
}

template<class UG> constexpr auto MinimumSpanningForest(const UG& g) {
    size_t N = g.count_vertices();
    size_t M = g.count_edges();
    struct result_type {
        UG graph;
        typename UG::weight_type cost;
    } res{ UG(N), 0 };
    std::vector<std::pair<typename UG::weight_type, std::pair<size_t, size_t>>> edges;
    edges.reserve(M);
    for (size_t v = 0; v != N; ++v) {
        for (auto [next, cost] : g[v]) {
            edges.emplace_back(cost, std::pair<size_t, size_t>{ v, next });
        }
    }
    std::sort(edges.begin(), edges.end());
    Graph::dsu uf(N);
    for (auto [cost, tmp] : edges) {
        auto [a, b] = tmp;
        if (uf.merge(a, b)) {
            res.graph.connect(a, b, cost);
            res.cost += cost;
        }
    }
    return res;
}
template<class UG> constexpr auto MinimumSpanningForestCost(const UG& g) {
    size_t N = g.count_vertices();
    size_t M = g.count_edges();
    typename UG::weight_type res{};
    std::vector<std::pair<typename UG::weight_type, std::pair<size_t, size_t>>> edges;
    edges.reserve(M);
    for (size_t v = 0; v != N; ++v) {
        for (auto [next, cost] : g[v]) {
            edges.emplace_back(cost, std::pair<size_t, size_t>{ v, next });
        }
    }
    std::sort(edges.begin(), edges.end());
    Graph::dsu uf(N);
    for (auto [cost, tmp] : edges) {
        auto [a, b] = tmp;
        if (uf.merge(a, b)) res += cost;
    }
    return res;
}

template<class UG> constexpr std::basic_string<bool> BipartiteGraphColoring(const UG& g) {
    std::basic_string<bool> res(g.count_vertices(), false);
    std::basic_string<bool> seen(g.count_vertices(), false);
    std::vector<size_t> s;
    s.reserve(g.count_vertices());
    for (size_t v = 0, n = g.count_vertices(); v != n; ++v) {
        s.push_back(v);
        seen[v] = true;
        while (!s.empty()) {
            auto node = s.back();
            s.pop_back();
            for (size_t next : g[node]) {
                if (seen[next]) {
                    if (res[node] == res[next]) return std::basic_string<bool>{};
                    continue;
                }
                res[next] = !res[node];
                seen[next] = true;
                s.push_back(next);
            }
        }
    }
    return res;
}
template<class UG> constexpr bool isBipartiteGraph(const UG& g) {
    size_t N = g.count_vertices();
    Graph::dsu uf(N * 2);
    for (size_t i = 0; i != N; ++i) {
        for (size_t j : g[i]) {
            uf.merge(i, j + N);
            uf.merge(i + N, j);
        }
    }
    for (size_t i = 0; i != N; ++i) {
        if (uf.root(i) == uf.root(i + N)) return false;
    }
    return true;
}

template<class DG> constexpr ConnectedComponents StronglyConnectedComponentsDecomposition(const DG& g) {
    constexpr size_t e = std::numeric_limits<size_t>::max();
    size_t N = g.count_vertices();
    size_t new_ord = 0, group_num = 0;
    std::vector<size_t> visited, low(N), ord(N, e), ids(N);
    visited.reserve(N);
#ifdef ONLINE_JUDGE
    auto dfs = [&](auto self, size_t v) -> void {
#else
    auto dfs = [&](auto& self, size_t v) -> void {
#endif
        low[v] = ord[v] = new_ord++;
        visited.push_back(v);
        for (size_t to : g[v]) {
            if (ord[to] == e) {
                if (!low[to]) self(self, to);
                low[v] = std::min(low[v], low[to]);
            } else low[v] = std::min(low[v], ord[to]);
        }
        if (low[v] == ord[v]) {
            while (true) {
                size_t u = visited.back();
                visited.pop_back();
                ord[u] = N;
                ids[u] = group_num;
                if (u == v) break;
            }
            ++group_num;
        }
    };
    for (size_t i = 0; i != N; ++i)
        if (ord[i] == e) dfs(dfs, i);
    std::vector<size_t> cnt(group_num);
    for (size_t& x : ids) {
        x = group_num - 1 - x;
        ++cnt[x];
    }
    ConnectedComponents res;
    res.vertex.resize(group_num);
    for (size_t i = 0; i != group_num; ++i) res.vertex[i].resize(cnt[i]);
    for (size_t i = 0; i != N; ++i) res.vertex[ids[i]][--cnt[ids[i]]] = i;
    res.aff = std::move(ids);
    return res;
}

template<class UG = UndirectedGraph<void>> constexpr UG GridtoGraph(const std::vector<std::string>& grid, char c = '#') {
    size_t H = grid.size(), W = grid[0].length();
    UG res(H * W);
    for (size_t i = 0; i != H; ++i) {
        for (size_t j = 0; j != W; ++j) {
            if (grid[i][j] == c) continue;
            if (i != 0 && grid[i - 1][j] != c) res.connect((i - 1) * W + j, i * W + j);
            if (j != 0 && grid[i][j - 1] != c) res.connect(i * W + j, i * W + (j - 1));
        }
    }
    return res;
}
#endif

#if defined(INCLUDE_HEAP) || defined(INCLUDE_ALL)
template<class T, class Compare = std::less<T>> class BinomialHeap {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;

public:
    class BinomialTree {
        friend class BinomialHeap;
        std::unique_ptr<value_type> val_;
        std::vector<BinomialTree> children_;
        BinomialTree() {}
        BinomialTree(const value_type& v) : val_(new value_type(v)) {}
        BinomialTree(value_type&& v) : val_(new value_type(std::move(v))) {}
        size_type degree() const noexcept { return children_.size(); }

    public:
        BinomialTree(const BinomialTree&) = delete;
        BinomialTree(BinomialTree&&) = default;
        BinomialTree& operator=(const BinomialTree&) = delete;
        BinomialTree& operator=(BinomialTree&&) = default;
        constexpr explicit operator bool() const noexcept { return bool(val_); }
        const value_type& value() const { return *val_; }
    };

private:
    Compare comp;
    BinomialTree* top_el = nullptr;
    std::vector<BinomialTree> trees_;

public:
    BinomialHeap() : comp(Compare()) {}
    explicit BinomialHeap(const Compare& comp_) : comp(comp_) {}
    template<class InputIterator> BinomialHeap(InputIterator first, InputIterator last, const Compare& comp_ = Compare()) : comp(comp_) {
        for (auto itr = first; itr != last; ++itr) push(*itr);
    }
    BinomialHeap(const BinomialHeap& x) = default;
    BinomialHeap(BinomialHeap&& y) = default;
    BinomialHeap(std::initializer_list<value_type> init, const Compare& comp_ = Compare()) : BinomialHeap(init.begin(), init.end(), comp_) {}
    void merge(BinomialTree&& p) {
        size_type deg = p.degree();
        if (trees_.size() <= deg) {
            while (deg > trees_.size()) trees_.emplace_back(BinomialTree());
            trees_.emplace_back(std::move(p));
        } else {
            do {
                BinomialTree& cur = trees_[deg];
                if (!cur) {
                    cur = std::move(p);
                    return;
                }
                if (comp(*p.val_, *cur.val_)) {
                    p.children_.emplace_back(std::move(cur));
                } else {
                    cur.children_.emplace_back(std::move(p));
                    p = std::move(cur);
                }
            } while (++deg < trees_.size());
            trees_.emplace_back(std::move(p));
        }
    }
    void merge(BinomialHeap&& p) {
        for (BinomialTree& t : p.trees_) merge(std::move(t));
    }
    void push(const value_type& v) {
        top_el = nullptr;
        merge(BinomialTree(v));
    }
    void push(value_type&& v) {
        top_el = nullptr;
        merge(BinomialTree(std::move(v)));
    }
    const_reference top() {
        if (top_el != nullptr) return *top_el->val_;
        for (BinomialTree& t : trees_)
            if (t && (top_el == nullptr || comp(*t.val_, *top_el->val_))) top_el = &t;
        if (top_el == nullptr) throw std::runtime_error("BinomialHeap::top / There is no element.");
        return *top_el->val_;
    }
    void pop() {
        top();
        top_el->val_.reset();
        BinomialHeap top_ch(comp);
        top_ch.trees_ = std::move(top_el->children_);
        top_el = nullptr;
        merge(std::move(top_ch));
    }
};
#endif

#if defined(INCLUDE_PERSISTENTDEQUE)
template<class T> class PersistentStack {
    struct Node {
        T value;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> head = nullptr;
    size_t data_size = 0;
    PersistentStack(Node* init, size_t init_size) : head(init), data_size(init_size) {}
    PersistentStack(std::shared_ptr<Node> init, size_t init_size) : head(init), data_size(init_size) {}

public:
    PersistentStack() {}
    PersistentStack(const PersistentStack<T>& init) : head(init.head), data_size(init.size) {}
    PersistentStack(PersistentStack<T>&& init) : head(init.head), data_size(init.size) {}
    bool empty() { return head == nullptr; }
    PersistentStack<T> pop() {
        if (head == nullptr) return PersistentStack();
        return PersistentStack(head->next, data_size - 1);
    }
    PersistentStack<T> push(const T& x) { return PersistentStack(new Node({ x, head }), data_size + 1); }
    size_t size() { return data_size; }
    void swap(PersistentStack<T>& x) { head.swap(x.head); }
    friend void swap(PersistentStack<T>& a, PersistentStack<T>& b) { a.swap(b); }
    T top() {
        if (head == nullptr) throw std::runtime_error("This stack is empty.");
        return head->value;
    }
    PersistentStack<T>& operator=(const PersistentStack<T>& a) {
        head = a.head;
        data_size = a.data_size;
        return *this;
    }
    PersistentStack<T>& operator=(PersistentStack<T>&& a) {
        head = a.head;
        data_size = a.data_size;
        return *this;
    }
};
template<class T> class PersistentQueue {
    struct Node {
        T value;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> head = nullptr, tail = nullptr;
    size_t data_size = 0;
    PersistentQueue(Node* init) : head(init), tail(init), data_size(1) {}
    PersistentQueue(Node* init_head, Node* init_tail, size_t init_size) : head(init_head), tail(init_tail), data_size(init_size) {}
    PersistentQueue(std::shared_ptr<Node> init_head, std::shared_ptr<Node> init_tail, size_t init_size) : head(init_head), tail(init_tail), data_size(init_size) {}

public:
    PersistentQueue() {}
    PersistentQueue(const PersistentQueue<T>& init) : head(init.head), tail(init.tail), data_size(init.data_size) {}
    PersistentQueue(PersistentQueue<T>&& init) : head(init.head), tail(init.tail), data_size(init.data_size) {}
    bool empty() { return data_size == 0; }
    PersistentQueue<T> pop() {
        if (data_size == 0) return PersistentQueue();
        return PersistentQueue(head, tail->next, data_size - 1);
    }
    PersistentQueue<T> push(const T& x) {
        if (data_size == 0) return PersistentQueue(new Node({ x, nullptr }));
        return PersistantQueue();
    }
};
#endif

#if defined(INCLUDE_MODINT) || defined(INCLUDE_ALL)
template<class T> class ModintTraits : public T {
    using base_type = T;
public:
    using value_type = std::decay_t<decltype(base_type::mod())>;
    using modint_type = ModintTraits;
    constexpr static bool is_staticmod = !requires { base_type::set_mod(0); };
    constexpr ModintTraits() noexcept : T() {}
    template<class U> constexpr ModintTraits(U x) noexcept { operator=(x); }
    constexpr explicit operator value_type() const noexcept { return val(); }
    constexpr static void set_mod(value_type x) {
        static_assert(!is_staticmod, "ModintTraits::set_mod / Mod must be dynamic.");
        if (x <= 1) throw std::runtime_error("ModintTraits::set_mod / Mod must be at least 2.");
        if (x == mod()) return;
        base_type::set_mod(x);
    }
    constexpr value_type val() const noexcept { return base_type::val(); }
    constexpr static value_type mod() noexcept { return base_type::mod(); }
    template<class U> constexpr modint_type& operator=(U x) noexcept {
        static_assert(std::is_integral_v<U>, "ModintTraits::operator= / Only integer types can be assigned.");
        if constexpr (std::is_unsigned_v<U>) {
            if constexpr (std::is_same_v<U, unsigned long long> || std::is_same_v<U, unsigned long>) base_type::assign(static_cast<std::uint64_t>(x));
            else base_type::assign(static_cast<std::uint32_t>(x));
        } else {
            if (x < 0) {
                if constexpr (std::is_same_v<U, long long> || std::is_same_v<U, long>) base_type::assign(static_cast<std::uint64_t>(-x));
                else base_type::assign(static_cast<std::uint32_t>(-x));
                base_type::neg();
            } else {
                if constexpr (std::is_same_v<U, long long> || std::is_same_v<U, long>) base_type::assign(static_cast<std::uint64_t>(x));
                else base_type::assign(static_cast<std::uint32_t>(x));
            }
        }
        return *this;
    }
    constexpr static modint_type raw(value_type x) noexcept {
        modint_type res;
        res.rawassign(x);
        return res;
    }
    template<class Istream> friend Istream& operator>>(Istream& ist, modint_type& x) {
        value_type n;
        ist >> n;
        x = n;
        return ist;
    }
    template<class Ostream> friend Ostream& operator<<(Ostream& ost, modint_type x) { return ost << x.val(); }
    constexpr modint_type inv() const {
        value_type a = 1, b = 0, x = val(), y = mod();
        if (x == 0) throw std::runtime_error("ModintTraits::inv / Zero division is not possible.");
        while (true) {
            if (x <= 1) {
                if (x == 0) [[unlikely]]
                    break;
                else return modint_type::raw(a);
            }
            b += a * (y / x);
            y %= x;
            if (y <= 1) {
                if (y == 0) [[unlikely]]
                    break;
                else return modint_type::raw(mod() - b);
            }
            a += b * (x / y);
            x %= y;
        }
        throw std::runtime_error("ModintTraits::inv / Cannot calculate inverse element.");
    }
    constexpr modint_type pow(uint64_t e) const noexcept {
        modint_type res = modint_type::raw(1), pow = *this;
        while (e) {
            modint_type tmp = pow * pow;
            if (e & 1) res *= pow;
            pow = tmp;
            e >>= 1;
        }
        return res;
    }
    constexpr modint_type operator+() const noexcept { return *this; }
    constexpr modint_type operator-() const noexcept {
        modint_type res = *this;
        res.neg();
        return res;
    }
    constexpr modint_type& operator++() noexcept {
        base_type::inc();
        return *this;
    }
    constexpr modint_type& operator--() noexcept {
        base_type::dec();
        return *this;
    }
    constexpr modint_type operator++(int) noexcept {
        modint_type copy = *this;
        operator++();
        return copy;
    }
    constexpr modint_type operator--(int) noexcept {
        modint_type copy = *this;
        operator--();
        return copy;
    }
    constexpr modint_type& operator+=(modint_type x) noexcept {
        base_type::add(x);
        return *this;
    }
    constexpr modint_type& operator-=(modint_type x) noexcept {
        base_type::sub(x);
        return *this;
    }
    constexpr modint_type& operator*=(modint_type x) noexcept {
        base_type::mul(x);
        return *this;
    }
    constexpr modint_type& operator/=(modint_type x) {
        operator*=(x.inv());
        return *this;
    }
    friend constexpr modint_type operator+(modint_type l, modint_type r) noexcept { return modint_type(l) += r; }
    friend constexpr modint_type operator-(modint_type l, modint_type r) noexcept { return modint_type(l) -= r; }
    friend constexpr modint_type operator*(modint_type l, modint_type r) noexcept { return modint_type(l) *= r; }
    friend constexpr modint_type operator/(modint_type l, modint_type r) { return modint_type(l) /= r; }
    friend constexpr bool operator==(modint_type l, modint_type r) noexcept { return l.val() == r.val(); }
    friend constexpr bool operator!=(modint_type l, modint_type r) noexcept { return l.val() != r.val(); }
    constexpr int legendre() const noexcept {
        value_type res = pow((mod() - 1) >> 1).val();
        return (res <= 1 ? static_cast<int>(res) : -1);
    }
    constexpr int jacobi() const noexcept {
        value_type a = val(), n = mod();
        if (a == 1) return 1;
        if (std::gcd(a, n) != 1) return 0;
        int res = 1;
        while (a != 0) {
            while (!(a & 1) && a != 0) {
                a >>= 1;
                if ((n & 0b111) == 3 || (n & 0b111) == 5) res = -res;
            }
            if ((a & 0b11) == 3 || (n & 0b11) == 3) res = -res;
            std::swap(a, n);
            a %= n;
        }
        if (n != 1) return 0;
        return res;
    }
    constexpr modint_type sqrt() const noexcept {
        const value_type vl = val(), md = mod();
        if (vl <= 1) return *this;
        auto get_min = [](modint_type x) {
            return x.val() > (mod() >> 1) ? -x : x;
        };
        if ((md & 0b11) == 3) return get_min(pow((md + 1) >> 2));
        else if ((md & 0b111) == 5) {
            modint_type res = pow((md + 3) >> 3);
            if constexpr (is_staticmod) {
                constexpr modint_type p = modint_type::raw(2).pow((md - 1) >> 2);
                res *= p;
            } else if (res * res != *this) res *= modint_type::raw(2).pow((md - 1) >> 2);
            return get_min(res);
        } else {
            value_type Q = md - 1;
            uint32_t S = 0;
            while ((Q & 1) == 0) Q >>= 1, ++S;
            if (std::countr_zero(md - 1) < 6) {
                modint_type z = modint_type::raw(1);
                while (z.legendre() != -1) ++z;
                modint_type t = pow(Q), R = pow((Q + 1) / 2);
                if (t.val() == 1) return R;
                uint32_t M = S;
                modint_type c = z.pow(Q);
                do {
                    modint_type U = t * t;
                    uint32_t i = 1;
                    while (U.val() != 1) U = U * U, ++i;
                    modint_type b = c;
                    for (uint32_t j = 0; j < (M - i - 1); ++j) b *= b;
                    M = i, c = b * b, t *= c, R *= b;
                } while (t.val() != 1);
                return get_min(R);
            } else {
                modint_type a = 1;
                while ((a * a - *this).legendre() != -1) ++a;
                modint_type res1 = modint_type::raw(1), res2, pow1 = a, pow2 = modint_type::raw(1), w = a * a - *this;
                value_type e = (md + 1) / 2;
                while (true) {
                    if (e & 1) {
                        modint_type tmp = res1;
                        res1 = res1 * pow1 + res2 * pow2 * w;
                        res2 = tmp * pow2 + res2 * pow1;
                    }
                    e >>= 1;
                    if (e == 0) return get_min(res1);
                    modint_type tmp = pow1;
                    pow1 = pow1 * pow1 + pow2 * pow2 * w;
                    pow2 *= modint_type::raw(2) * tmp;
                }
            }
        }
    }
};
template<std::uint32_t mod_> class StaticModint32_impl {
    using value_type = std::uint32_t;
    using modint_type = StaticModint32_impl;
    value_type val_ = 0;
protected:
    constexpr StaticModint32_impl() noexcept {}
    constexpr value_type val() const noexcept { return val_; }
    static constexpr value_type mod() noexcept { return mod_; }
    constexpr void assign(std::uint32_t x) noexcept { val_ = x % mod_; }
    constexpr void assign(std::uint64_t x) noexcept { val_ = x % mod_; }
    constexpr void rawassign(value_type x) noexcept { val_ = x; }
    constexpr void neg() noexcept { val_ = (val_ == 0 ? 0 : mod_ - val_); }
    constexpr void inc() noexcept { val_ = (val_ == mod_ - 1 ? 0 : val_ + 1); }
    constexpr void dec() noexcept { val_ = (val_ == 0 ? mod_ - 1 : val_ - 1); }
    constexpr void add(modint_type x) noexcept {
        if (mod_ - val_ > x.val_) val_ += x.val_;
        else val_ = x.val_ - (mod_ - val_);
    }
    constexpr void sub(modint_type x) noexcept {
        if (val_ >= x.val_) val_ -= x.val_;
        else val_ = mod_ - (x.val_ - val_);
    }
    constexpr void mul(modint_type x) noexcept { val_ = static_cast<std::uint64_t>(val_) * x.val_ % mod_; }
};
template<std::uint32_t mod_ = 998244353> using StaticModint32 = ModintTraits<StaticModint32_impl<mod_>>;
template<std::uint64_t mod_> class StaticModint64_impl {
    using value_type = std::uint64_t;
    using modint_type = StaticModint64_impl;
    value_type val_ = 0;
protected:
    constexpr StaticModint64_impl() noexcept {}
    constexpr value_type val() const noexcept { return val_; }
    static constexpr value_type mod() noexcept { return mod_; }
    constexpr void assign(std::uint32_t x) noexcept {
        if constexpr (mod_ < (1ull << 32)) val_ = x % mod_;
        else val_ = x;
    }
    constexpr void assign(std::uint64_t x) noexcept { val_ = x % mod_; }
    constexpr void rawassign(value_type x) noexcept { val_ = x; }
    constexpr void neg() noexcept { val_ = (val_ == 0 ? 0 : mod_ - val_); }
    constexpr void inc() noexcept { val_ = (val_ == mod_ - 1 ? 0 : val_ + 1); }
    constexpr void dec() noexcept { val_ = (val_ == 0 ? mod_ - 1 : val_ - 1); }
    constexpr void add(modint_type x) noexcept {
        if (mod_ - val_ > x.val_) val_ += x.val_;
        else val_ = x.val_ - (mod_ - val_);
    }
    constexpr void sub(modint_type x) noexcept {
        if (val_ >= x.val_) val_ -= x.val_;
        else val_ = mod_ - (x.val_ - val_);
    }
    constexpr void mul(modint_type x) noexcept { val_ = static_cast<__uint128_t>(val_) * x.val_ % mod_; }
};
template<std::uint64_t mod_ = 998244353> using StaticModint64 = ModintTraits<StaticModint64_impl<mod_>>;
template<std::uint64_t mod_ = 998244353> using StaticModint = std::conditional_t<(mod_ < (1ull << 32)), StaticModint32<mod_>, StaticModint64<mod_>>;
template<int id> class DynamicModint32_impl {
    using value_type = std::uint32_t;
    using modint_type = DynamicModint32_impl;
    static inline value_type mod_ = 0;
    static inline std::uint64_t mod64_ = 0;
    static inline __uint128_t L_ = 0;
    value_type val_ = 0;
    value_type reduce(std::uint32_t c) const noexcept {
        std::uint32_t q = (c * L_) >> 96;
        return c - q * mod_;
    }
    value_type reduce(std::uint64_t c) const noexcept {
        std::uint64_t q = (c * L_) >> 96;
        return c - q * mod64_;
    }
protected:
    DynamicModint32_impl() noexcept {}
    static void set_mod(value_type newmod) noexcept {
        mod_ = newmod, mod64_ = newmod;
        L_ = ((__uint128_t(1) << 96) - 1) / mod_ + 1;
    }
    value_type val() const noexcept { return val_; }
    static value_type mod() noexcept { return mod_; }
    void assign(std::uint32_t x) noexcept { val_ = reduce(x); }
    void assign(std::uint64_t x) noexcept { val_ = reduce(x); }
    void rawassign(value_type x) noexcept { val_ = x; }
    void neg() noexcept { val_ = (val_ == 0 ? 0 : mod_ - val_); }
    void inc() noexcept { val_ = (val_ == mod_ - 1 ? 0 : val_ + 1); }
    void dec() noexcept { val_ = (val_ == 0 ? mod_ - 1 : val_ - 1); }
    void add(modint_type x) noexcept {
        if (mod_ - val_ > x.val_) val_ += x.val_;
        else val_ = x.val_ - (mod_ - val_);
    }
    void sub(modint_type x) noexcept {
        if (val_ >= x.val_) val_ -= x.val_;
        else val_ = mod_ - (x.val_ - val_);
    }
    void mul(modint_type x) noexcept { val_ = reduce(static_cast<std::uint64_t>(val_) * x.val_); }
};
template<int id = 0> using DynamicModint32 = ModintTraits<DynamicModint32_impl<id>>;
template<int id> class DynamicModint64_impl {
    using value_type = std::uint64_t;
    using modint_type = DynamicModint64_impl;
    static inline value_type mod_ = 0;
    static inline __uint128_t M_ = 0;
    value_type val_ = 0;
protected:
    DynamicModint64_impl() noexcept {}
    static void set_mod(value_type newmod) noexcept {
        mod_ = newmod;
        M_ = std::numeric_limits<__uint128_t>::max() / mod_ + std::has_single_bit(mod_);
    }
    value_type val() const noexcept { return val_; }
    static value_type mod() noexcept { return mod_; }
    void assign(std::uint64_t x) noexcept { val_ = x % mod_; }
    void rawassign(value_type x) noexcept { val_ = x; }
    void neg() noexcept { val_ = (val_ == 0 ? 0 : mod_ - val_); }
    void inc() noexcept { val_ = (val_ == mod_ - 1 ? 0 : val_ + 1); }
    void dec() noexcept { val_ = (val_ == 0 ? mod_ - 1 : val_ - 1); }
    void add(modint_type x) noexcept {
        if (mod_ - val_ > x.val_) val_ += x.val_;
        else val_ = x.val_ - (mod_ - val_);
    }
    void sub(modint_type x) noexcept {
        if (val_ >= x.val_) val_ -= x.val_;
        else val_ = mod_ - (x.val_ - val_);
    }
    void mul(modint_type x) noexcept {
        const std::uint64_t a = (((M_ * val_) >> 64) * x.val_) >> 64;
        const std::uint64_t b = val_ * x.val_;
        const std::uint64_t c = a * mod_;
        const std::uint64_t d = b - c;
        const bool e = d < mod_;
        const std::uint64_t f = d - mod_;
        val_ = e ? d : f;
    }
};
template<int id = 0> using DynamicModint64 = ModintTraits<DynamicModint64_impl<id>>;
template<class Modint> class ModManager {
    Modint::value_type prev;
public:
    ModManager() { prev = Modint::mod(); }
    ~ModManager() {
        if (prev != 0) Modint::set_mod(prev);
    }
    void set_mod(Modint::value_type newmod) { Modint::set_mod(newmod); }
};
template<class Modint> class SwitchModint;
template<uint32_t mod> class SwitchModint<StaticModint32<mod>> {
public:
    using modint_type = StaticModint32<mod>;
    using value_type = typename modint_type::value_type;
};
template<uint64_t mod> class SwitchModint<StaticModint64<mod>> {
public:
    using modint_type = StaticModint64<mod>;
    using value_type = typename modint_type::value_type;
};
template<int id> class SwitchModint<DynamicModint32<id>> {
public:
    using modint_type = DynamicModint32<id>;
    using value_type = typename modint_type::value_type;
    SwitchModint(value_type mod) { modint_type::set_mod(mod); }
};
template<int id> class SwitchModint<DynamicModint64<id>> {
public:
    using modint_type = DynamicModint64<id>;
    using value_type = typename modint_type::value_type;
    SwitchModint(value_type mod) { modint_type::set_mod(mod); }
};
#endif

#if defined(INCLUDE_RANDOM) || defined(INCLUDE_ALL)
constexpr uint32_t mwc(uint32_t a, uint32_t b) noexcept {
    a = 36969 * (a & 65535) + (a >> 16);
    b = 18000 * (b & 65535) + (b >> 16);
    return (a << 16) + (b & 65535);
}
constexpr uint32_t splitmax(uint32_t n) noexcept {
    n += 0x9e3779b9;
    n = (n ^ (n >> 15)) * 0x85ebca6b;
    n = (n ^ (n >> 13)) * 0xc2b2ae35;
    return (n ^ (n >> 16));
}
constexpr uint64_t splitmax(uint64_t n) noexcept {
    n += 0x9e3779b97f4a7c15;
    n = (n ^ (n >> 30)) * 0xbf58476d1ce4e5b9;
    n = (n ^ (n >> 27)) * 0x94d049bb133111eb;
    return n ^ (n >> 31);
}
#if __cplusplus >= 202001U
consteval uint64_t Randomnum(std::source_location loc = std::source_location::current()) noexcept {
    auto string_hash_ = [](const char* s) {
        const char* last = s + strlen(s);
        uint64_t res = 0;
        while (s != last) {
            uint64_t tmp = 0;
            for (size_t i = 0; i < 16 && s != last; ++i) tmp = tmp << 4 | *(s++);
            res ^= splitmax(tmp);
        }
        return res;
    };
    return splitmax(splitmax(static_cast<uint64_t>(loc.column()) << 32 | loc.line()) ^ string_hash_(loc.file_name()) ^ string_hash_(__TIME__));
}
#endif
//https://ja.wikipedia.org/wiki/Xorshift
class xorshift64 {
    using value_type = uint64_t;
    value_type val;
public:
    using result_type = uint64_t;
    static constexpr size_t word_size = sizeof(result_type) * 8;
    static constexpr value_type default_seed = 0xcafef00dd15ea5e5;
    constexpr xorshift64() : xorshift64(default_seed) {}
    constexpr explicit xorshift64(value_type value) : val(value) {}
    constexpr result_type operator()() {
        val ^= val << 7;
        val ^= val >> 9;
        return val;
    };
    constexpr void discard(unsigned long long z) {
        for (unsigned long long i = 0; i < z; ++i) operator()();
    }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    static constexpr result_type min() { return 1; }
    constexpr void seed(value_type value = default_seed) { val = value; }
    constexpr bool operator==(xorshift64 x) { return val == x.val; }
};
//https://twitter.com/rho__o/status/1734784410808160661
class pcg32 {
    using value_type = uint64_t;
    value_type val;
public:
    using result_type = uint32_t;
    static constexpr size_t word_size = sizeof(result_type) * 8;
    static constexpr value_type default_seed = 0xcafef00dd15ea5e5;
    constexpr pcg32() : pcg32(default_seed) {}
    constexpr explicit pcg32(value_type value) : val(value) {}
    constexpr result_type operator()() {
        uint64_t x = val;
        x ^= x >> 22;
        val *= 0xcafef00dd15ea5e5;
        return (x >> (22 + (x >> 61)));
    };
    constexpr void discard(unsigned long long z) {
        for (unsigned long long i = 0; i < z; ++i) operator()();
    }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    static constexpr result_type min() { return 0; }
    constexpr void seed(value_type value = default_seed) { val = value; }
    constexpr bool operator==(pcg32 x) { return val == x.val; }
};
//https://twitter.com/rho__o/status/1734786100873564174
class lcgs32 {
    using value_type = uint64_t;
    value_type val;
public:
    using result_type = uint32_t;
    static constexpr size_t word_size = sizeof(result_type) * 8;
    static constexpr value_type default_seed = 0xcafef00dd15ea5e5;
    constexpr lcgs32() : lcgs32(default_seed) {}
    constexpr explicit lcgs32(value_type value) : val(value) {}
    constexpr result_type operator()() {
        uint64_t x = val;
        val *= 0xcafef00dd15ea5e5;
        return (x >> 32);
    };
    constexpr void discard(unsigned long long z) {
        for (unsigned long long i = 0; i < z; ++i) operator()();
    }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    static constexpr result_type min() { return 0; }
    constexpr void seed(value_type value = default_seed) { val = value; }
    constexpr bool operator==(lcgs32 x) { return val == x.val; }
};
//https://www.pcg-random.org/posts/bounded-rands.html
template<class URBG> constexpr uint32_t randi32(URBG& g, uint32_t max) {
    return (static_cast<std::uint64_t>(g() & 4294967295) * max) >> 32;
}
template<class URBG> constexpr uint32_t randi32(URBG& g, uint32_t min, uint32_t max) {
    return static_cast<std::uint32_t>((static_cast<std::uint64_t>(g() & 4294967295) * (max - min)) >> 32) + min;
}
template<class URBG> constexpr uint64_t randi64(URBG& g, uint64_t max) {
    return (static_cast<__uint128_t>(g()) * max) >> 64;
}
template<class URBG> constexpr uint64_t randi64(URBG& g, uint64_t min, uint64_t max) {
    return static_cast<uint64_t>((static_cast<__uint128_t>(g()) * (max - min)) >> 64) + min;
}
//https://speakerdeck.com/hole/rand01?slide=31
template<class URBG> constexpr float canocicaled(URBG& g) {
    return std::bit_cast<float>((127u << 23) | (static_cast<std::uint32_t>(g()) & 0x7fffff)) - 1.0f;
}
template<class URBG> constexpr float randf32(URBG& g, float max) {
    return canocicaled(g) * max;
}
template<class URBG> constexpr float randf64(URBG& g, float min, float max) {
    return canocicaled(g) * (max - min) + min;
}
#endif

#if defined(INCLUDE_NUMERIC) || defined(INCLUDE_ALL)
constexpr uint32_t isqrt32(const uint32_t n) {
    return std::sqrt((long double) n);
}
//https://zenn.dev/mizar/articles/791698ea860581#%E5%B9%B3%E6%96%B9%E6%95%B0%E3%81%AE%E5%88%A4%E5%AE%9A
constexpr uint64_t isqrt64(const uint64_t n) {
    if (n <= 1) [[unlikely]]
        return n;
    const int k = 32 - std::countl_zero(n - 1) / 2;
    uint64_t s = 1ull << k;
    uint64_t t = (s + (n >> k)) / 2;
    while (t < s) {
        s = t;
        t = (s + (n / s)) / 2;
    }
    return s;
}
//https://lpha-z.hatenablog.com/entry/2020/05/24/231500
template<class T> constexpr T BinaryGCD(T x, T y) {
    if (x == 0 || y == 0) [[unlikely]]
        return x | y;
    const int n = std::countr_zero(x);
    const int m = std::countr_zero(y);
    const int l = n < m ? n : m;
    x >>= n;
    y >>= m;
    T s;
    int t;
    while (x != y) {
        s = y < x ? x - y : y - x;
        t = std::countr_zero(s);
        y = y < x ? y : x;
        x = s >> t;
    }
    return x << l;
}
template<bool trial_division = true> bool isPrime32(const std::uint32_t x) {
    if constexpr (trial_division) {
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 || x % 11 == 0 || x % 13 == 0 || x % 17 == 0 || x % 19 == 0 || x % 23 == 0 || x % 29 == 0 || x % 31 == 0 || x % 37 == 0 || x % 41 == 0 || x % 43 == 0) return x <= 43 && (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 || x == 23 || x == 29 || x == 31 || x == 37 || x == 41 || x == 43);
        if (x < 47 * 47) return (x > 1);
    } else {
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return x <= 7 && (x == 2 || x == 3 || x == 5 || x == 7);
        if (x < 11 * 11) return (x > 1);
    }
    //https://www.techneon.com/download/is.prime.32.base.data
    const static std::uint16_t bases[] = { 1216, 1836,  8885,  4564, 10978, 5228, 15613, 13941, 1553, 173,   3615, 3144, 10065, 9259,  233,  2362, 6244,  6431, 10863, 5920, 6408, 6841, 22124, 2290,  45597, 6935,  4835, 7652, 1051, 445,  5807, 842,  1534, 22140, 1282, 1733, 347,   6311,  14081, 11157, 186,  703,  9862,  15490, 1720, 17816, 10433, 49185, 2535, 9158,  2143,  2840,  664,  29074, 24924, 1035, 41482, 1065,  10189, 8417,  130,  4551,  5159,  48886,
                                           786,  1938,  1013,  2139, 7171,  2143, 16873, 188,   5555, 42007, 1045, 3891, 2853,  23642, 148,  3585, 3027,  280,  3101,  9918, 6452, 2716, 855,   990,   1925,  13557, 1063, 6916, 4965, 4380, 587,  3214, 1808, 1036,  6356, 8191, 6783,  14424, 6929,  1002,  840,  422,  44215, 7753,  5799, 3415,  231,   2013,  8895, 2081,  883,   3855,  5577, 876,   3574,  1925, 1192,  865,   7376,  12254, 5952, 2516,  20463, 186,
                                           5411, 35353, 50898, 1084, 2127,  4305, 115,   7821,  1265, 16169, 1705, 1857, 24938, 220,   3650, 1057, 482,   1690, 2718,  4309, 7496, 1515, 7972,  3763,  10954, 2817,  3430, 1423, 714,  6734, 328,  2581, 2580, 10047, 2797, 155,  5951,  3817,  54850, 2173,  1318, 246,  1807,  2958,  2697, 337,   4871,  2439,  736,  37112, 1226,  527,   7531, 5418,  7242,  2421, 16135, 7015,  8432,  2605,  5638, 5161,  11515, 14949,
                                           748,  5003,  9048,  4679, 1915,  7652, 9657,  660,   3054, 15469, 2910, 775,  14106, 1749,  136,  2673, 61814, 5633, 1244,  2567, 4989, 1637, 1273,  11423, 7974,  7509,  6061, 531,  6608, 1088, 1627, 160,  6416, 11350, 921,  306,  18117, 1238,  463,   1722,  996,  3866, 6576,  6055,  130,  24080, 7331,  3922,  8632, 2706,  24108, 32374, 4237, 15302, 287,   2296, 1220,  20922, 3350,  2089,  562,  11745, 163,   11951 };
    using mint = DynamicModint32<-1>;
    mint::set_mod(x);
    const std::uint32_t h = x * 0xad625b89;
    std::uint32_t d = x - 1;
    mint cur = bases[h >> 24];
    int s = std::countr_zero(d);
    d >>= s;
    cur = cur.pow(d);
    if (cur.val() == 1) return true;
    while (--s) {
        if (cur.val() == x - 1) return true;
        cur *= cur;
    }
    return cur.val() == x - 1;
}
template<bool trial_division = true, bool hashing = false> bool isPrime64(const std::uint64_t x) {
    if (x < 4294967296) return isPrime32<trial_division>(x);
    if constexpr (trial_division) {
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 || x % 11 == 0 || x % 13 == 0 || x % 17 == 0 || x % 19 == 0 || x % 23 == 0 || x % 29 == 0 || x % 31 == 0 || x % 37 == 0 || x % 41 == 0 || x % 43 == 0) return false;
    } else {
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;
    }
    using mint = DynamicModint64<-1>;
    mint::set_mod(x);
    std::uint64_t d = x - 1;
    const int s = std::countr_zero(d);
    d >>= s;
    if constexpr (!hashing) {
        auto test = [&](std::uint64_t a) -> bool {
            mint cur = mint(a).pow(d);
            if (cur.val() <= 1) return true;
            int i = s;
            while (--i) {
                if (cur.val() == x - 1) return true;
                cur *= cur;
            }
            return cur.val() == x - 1;
        };
        //http://miller-rabin.appspot.com/
        if (x < 585226005592931977ull) {
            if (x < 7999252175582851ull) {
                if (x < 350269456337ull) return test(4230279247111683200ull) && test(14694767155120705706ull) && test(16641139526367750375ull);
                else if (x < 55245642489451ull) return test(2ull) && test(141889084524735ull) && test(1199124725622454117ull) && test(11096072698276303650ull);
                else return test(2ull) && test(4130806001517ull) && test(149795463772692060ull) && test(186635894390467037ull) && test(3967304179347715805ull);
            } else return test(2ull) && test(123635709730000ull) && test(9233062284813009ull) && test(43835965440333360ull) && test(761179012939631437ull) && test(1263739024124850375ull);
        } else return test(2ull) && test(325ull) && test(9375ull) && test(28178ull) && test(450775ull) && test(9780504ull) && test(1795265022ull);
    } else {
        //https://www.techneon.com/download/is.prime.64.base.data
        const static std::array<std::uint16_t, 16384> bases = []() {
            std::string data = R"***(03
<rtBB'NE9O"e[5pH;7/Cl6#iX9aItF.rfH74.Z8l^6\"\l0u$-3RI'4W7q#<ZT415;0"T$o$m=l9M=I$KsEK>%+7**qX7mjD;S-oLAtoT(RXa4q+`fNGOJ=1"Ak/cX3Yuo=UP#/<:QJd^ZhC%6[u!'>sar690=X0D+,iACU?iQNb267m/Eg2l.6/LW$^,3q)pCE4*)su3p'YmZp)#mEKu0=SE0$\4q-&`Wl\AX7SBjUg0TML+HB\e'<4h=]Zj/FmmW%Ji2Y"B3H3lKP@C23'Qb\p=Bo@l(utDRA@>mXTc&JidEr*C&uSX",ECV&:)WB,lZ[q,2m_fs+cEr*EQ%H+p0CMfKQB8GoriDY)#2^@MipLcZb*B/AoAb5Zbf1loh3jF7aCiO81j2HTSiUaq;n:^+tm6t>tU1[cOjC9?8URs^"_klB>=D,5nqfBqmgJ%GU]Q0;nTUf!UP62?X;FBg!oo1GA`4"frLIsA_!.mZSBemHf$D).Mo
0pqbg10>$7BGrT3o:2u)cT9`6#Rg]"!C1X"/k4%d$N1SuhTbuo8^1\)q/mc9EInr#-KcAM7inN2rb`R5lYi\s37cW43&P4"#Yr^c'ND9bnr9_TU\7JCRo@39t")p\D4?C5i^Kb#eq9.--5472rPd;OFiP>V46D*6Ob)TH'&ZWfNAWVqQ+A8rTNFu8c+c8K9j/M6jL1"'tXf[jonhH-8:HDR4]E]`/Jb=1O5SL`M[%_iG$=:\2_9piRVfQrIj6P4K*j)'%-f1hY29mqjUGlHruLT8[/9Ld#@9$)2C:9nkl<;@,4=M<-536^ugf>$@r%Ve9WG<=n&2KM2a4cVL63L]&/,^Qp<;\c(ZfW@rqa#gdKdj)OaZc/IPWLqqb%fTk'LNq\-YY5O@lEWDM>\m#3fScg8rHj<o%Vb8lc34'TTPq$H8`#6C)40(Ump:XDXVJHJE>F%EkPAn3@Y*W,r8bV_kIl3s^)"31fIN^dK#g)20Va0=g8]#8kZ:
"*BoC1cqk!PHroEcp-h)1II95jC(sCOFB/M2h^K$Vb32)Q!j6_76o$m..^\sV'\>q<F95c@E&8A+]JMB.`qD2`HLKW#n$]c%IGGSWJIX7K.52jUsLQjAjisX%%00RK_l8CJ.q+5Ds05e1c5h#op3q79%:_E3-fn<rZq+R!D2$(,\HCiV,n)j+9:Lqo;J/_#D1\AidS^G"74hZ#F[6^*QCq6k"V;77fB'=!sj&J1BepPoX,@L:0q_=LQoKF;mo^i>EYOSkJmAB12@$T\'`ThUm>l/"^`q\@CX#J?Yn'l,.o7HSAEHZ+&9CWXjd\\t3mS)+'m]SgRSPO.5(@0lM+3r3j'"TF`G$41b-T"?LR]YRA>OE>nPO#^Do1-*Xldq:@lSa"0itsB/1[VTP*]=LV.=>Q=^>>?3]f4SYEdZ:>^@!bSn&?lp\6WDMD^ScR`Xg[2>WI?7WdCh9l,cd`Vt4iZqk[YAiob,kUhY6J!\XhQH"$U2]Al\Yq">
Eq!q400%7\FghPXk?4l5@*SG;m(6CIP'BuW$P?_5>b,gJ:iI6kJgg2($lL^<]HGlMqjG0OL/jd0KJdrREBFCRp2g%Y$qTALBrSt_JKH0;Y\^:S8arG->YNX?G474:Uf^POO%OU9=jo>W)'PD-_*_5QDE%_TAJq<H:tGQm[DmAeWka$9,&WSX>+q6WKcA8l^0jaZ!^hJ;+uL6;0E9db$j-/8DI.]Zk,]5[^.D"*qS*fJ%i\nZKlos/R-9pbLW3K5rfr&VWmnM?N(e9h"mV8Cp^E9-)W`:Wa&`;,C/<2e?>>.dW-,)redof],aDj139QmXA,,F;Ul8efJ9GmBg%LbcV+IJ8lB&%FhIFkcF256(>)nJSWM(UetT`J'n$)3i`](U:J"mJeppjMoqJmG:gcWI"_nm6&%+mp?m4OVV5OFDUOGHp:F^>)N_I_953ZiH[iZ1NFmshTfFOLKL8Om!\]rZj`iEkoDZ\nnO*9/6cWM0hsOZ1Sc:,DT&
_"oa*[%\'=Yfe?@cgi*B]$37aFnUjKnXK?r@FA>"109cj:-#lJQ=U&?FB:J:M/aLHYtj/@aF\j,"Es/n,(R%D4H[,isGn$Mfa3D1(W;"[iO^p'_(GE*KPCJ]AfR%UkY]0eX$`f3<@q5-)X%'OT_:Dq02C<>oR<3EQO;kJ!'$=fll"P*/*4[%N`lse2=^WgtLB6d5;4mYa*li5`LkFc1U8oU$RF7SoHmIjrsjpRfBg$>+jq1%fdp=D38\G*nqDqi8*l@'HHACmd[$uVeKKQ^O3,f\/QMjbK8[7Z;-fj5Y+T=&jul9t,+ED"d1Fa(J_D3s(&WH+;;6WD`ufr3AT<sp3!>$ZKo%,LQaHbd.85M3Aq-ZZLVrCo)U>moFsPq<Kan]A,]5HUOWh,h3*_k1?/+bl_@2gL"BaU]cg+,K:7:[J9cWtWsc'"fj61^fd,i7(mZ4KM#SoRD:e:.=@Ed*n]c%RkZ3Eh@>50"$CHCO$sCF_eKT.uj;Th<Z
Rphe!Yqkp5G^mT!^YQK]ITN#8(K4RIo%#f#6)VQuq+BDgU@P9$s-el"q;1m0oDlH8hrj(-+#AbTr;h+;$r,MOkB9quK7IGUGT"7rS/G-_G;`3B2Nr6jq5N9'#;&u&.H;>#<H<UX^A5,h._q&ac'lAqVC^%Vm]21lC:d7I-&YKoBNSU.:(#&4`tA^S_<T>@EQC.S2YShXTC=5I-S?Iu[M=B"*eW$_&Xf'g,hTM;nfHbBbMW@=FbkUJ=1EP?WJqXBm0/toFgrN>J"]b,7fGO(D6M:VQ2WUEF3Zg5T*'Y\QQ.JEG+V/1-ac'ZjsUb&)'2sDJ9]QVFM[Z<q!^Z%giNjO+)&ZbbB>(&L,Zd1#jDWWu/T1V;<*kfaa=,Q3sAC=eZ7/%#E,M[1IG\u_jcoGc8Rs:n:9K#BCbaA1uN3(Ia;4]IZ%^jc167HAF.t<0ubSqYjs)ZIg&f/fqg\1VVbk,SYZUTl_j/DR1+3t7r1G?F9OnoBd\L`.6MO6
k,E*'[.W;#;\QTsAW=mJX4CYJL+Ae.Y_;hPj;)qt)\Jo\s`e!i)h4\QFbF5'QQobJ\%p,WHW,^_IiCG]ip;TQ_>YMJkXOq6X_!1M$$S]8*#E>?e]AoX$Xc5XC6SPAPF-g,DIB4ngUN_-\Z[p8<uiVZbu``k-UC\Oj^kYo#2?95!5N-k'mL\gP<YK9[jVO1ESZX--<Zc2CF&G$9D$[?3Ai#Jg=<qBEJl5(u.enaW"7\+nYl3u^objfTm*HEN7HeX=U:)CKtG@QRY?bWD1&TW1UmFdZ#r!rF0N/M;]DNPrebt#iJ5J]=+lb:F*af-ZA/,tb"./CI8>tL%*YOFngdmpZTCJtu*4Ni5j.E=V8NY/b';0BJ/jS]r3aXBSN`[n^;XWX0IJ,M;%n]iPWep<e`AjX.Sj5WBQFQU]22#-SF(Bgh+;#NA@*cX-7ZWAJd"RVW.O,QW^i,./h"r%jus"c)5kFJL*T,b?=@(3i=O*JBB<6&FFGC+dfYPD
B[?5(*1Q=K9>6$A?pU+uYhi\ICqmapbZmcl+eht\)tdLSDdbI_A/DUXSH)r'BiW9:ANF8qY4/uU<ocJ[8;J,E=1pF6&>W@:lVe+khZrkTt#Y08$:e]hOsR(/JAZ_eh$0C@nYbNM$'di1HQFK\D#A(1gX9qtimhk;dDl\VAK."7-JmI^ABATiiY!APq.ajN;QE\j9<^YA2Uiud=GU,2Cebu!*9c!?;CN7<4E>;o/`s'J+Y-2WLqaRgRQC5cI%cHKe8Um6tAW&JAM,CaB76ju[EeIL=j\DP$=l5L,]n=.N-0!W-JD;sm=+S)4s8TD""%9g<V4I(3JQa!mbh!!&HSlG5u=9u-rLTbX#X@hE1g%RffSk?:JF0'd+N&a,8mJS--IJNL,<:5rOIBQrTZ_TI:'7,(%-V,lhotN<tk]MOhb9nAI!k>F>nbk5MVcgL1G>4&];tst(o/YjcI=0g&cGk`cm;dnY>+Zo+hO0`s.>'6I;[);E4:3`Z*R%
(kZJlDH4Ob"XjglQ6G*Cu<'`$W\RGbp-<2Y2uNEGeY7`e)DpTDmShjS1PG>g!f?o:Tk?&QOh<U3mn@C_R<#N9s#>Jca=_,fF=BhS@Cf,&ckJA^'<#1@53*K`:.NHKB``g`=?`Uk4AP7V"N7>peceoiFfe^K`G?JG,#/qN*ZjJhN%+>p2EFQU,T=Din:,hCG5Sa6IYKuK@qVe57=YD9j8GnDn!<qXgP$;+^lK@gYl7W$/.FGf68j-c@P5>hEVF?\r=hTN%39H(b_S%BrcE[5J;4P1t%r?2[^?D6O8?*ik:F(ab.;3#a6r-+FT7CBp]A*VV6RDJc0gl\\Jd/CYLni;UD55"9W@Cbto.UrfJEA[@S1O0iAQVc6g2$pcQ'tN=a]o8$)Tld?SE`4dO9oepQ&]CC1##Yi4'<`LnGuaEK]O5$OV-<GXY$PKLG#.m,.$KiWL2!^\gWn]+(>\o.XHcjY_/\VhLtnBMCH3#n-"'Do`/Sl6NpK4CbC6
T&'R,ggp@%`nid:N!5<Tp`Yc[I);O?X-ZKl(ccZSED]8*=*`<=7s7pl&S`Upmj(C3KTR\fSshij0srp.U_rCg8#]S`023ToY[]tW+No-N@#g["8d3ukB^Z;R7L[<($ed[sYUGqgDRf"LXX*L#.5/Li>crJ#Y:j853LR%Ed4e"*gEP48><`OJ&_c7"05-EY6tLSf\gF>"#?Fa/XH$d$HPB@])up9;LcbP,X/2s\5r+XPEM9OO+<2mX=V7o?,Tcf;>7fNVG0DR[@)qjs36`5`1_Isp4CpJc?a-%p/hU@Qa0O\"D[mGT_$_IJ3'5S-NHcZL=>(I#R%=YD*`Mt9+#R&+);G+H;/j?OpBlth".)d^0hpJ"riq+2TA)W*!Qd2Pb.)#LMG0o\*"i2b2ko^8nGd?`f`j"_u@l6.*Z?4>i=a.>#;Bij2jRb8Eb.reO6Nu=8TBBJ%I%)#qrFs_D0p/C-L'Ur#B$uT@H$!iJ^2qQqRo"MNtm:8A;=t<
g2'!u/gbYMVp*"arQC3nk#,4g-o@/^!#^GY3jGe)euZFmmM;Tp&<R@s>=FIg)TQf>WKc$.9llR]]qNs&c"f-`2Aj+sQ?O1bG`NVY;nm#>qu&^,_("*EPqisB7GL%Y*R<d@*XT>cp]Lt';[N._&Og"U[_Eb:hF7q9$OEdht>BIM,L`W+0&#$6thN-N@TBc6Y`s5JB^a-sM?eOn<=eP3pRp:DEuC-;,kl.J,(`lmN)=?8>lTp-(c)P\qnT>o4O*4d;6q]4D1:&EID`Fh1e_&h:rL322ua!uF:k1Na_m4ILKDg!V>H2,BoD<q1NcG^`m8bWD^h#'C&,aRDQFY?tccc(u:f.NcVZnoql@X*A6RL[mRX]f@pc?V(8X-#?Y`0[Pdds^M^7%fV(6?ThQ=YjHJ@T/k3%j!ju2[1%pUBYWi)Ih1a'Z5U1/'!'rYBHfQhr]f;:CHCIY+BWGX&n2,R>.!pSc/>c]`pNqld%b-iC>H>AZb`QkLb:,EK,
DC]XW34]U5Ngs533I<LV&mY05\I^+V8%G]35&gZqXR,+dMV?59F9,YF)$T4-="QY_foD;IXkQ0nJHVg^G.3S@M@mZ[1[Ih*Lg:+q?M>H+[t1A8o.\>n7j.7F3uVmE_`g!gET)JkX>IIjA.Q:u;?5h8b*>K0M)6`)5rpHj<%A$O1fYf<HAa<G#9o/kV;`p;[Bbbaps6S$.?7--0#ms@i%`i6D'8!VCrnm,J0ib;t<I<bP0QWlU\Q1:JSMXCAAY1T;GO49W?;R^G\rhT"dcc5h#dMY4qZ>0EO3-hh1d]-r21<H?(ogtS4\JOr%=3H+WI5/(uU))#3jLoCb,b.ZqnL;Sf(9IK%lG#!JO7<2>4N,/G?8JZ!X<&p1qm+<Ap!nCL@Rt"?j0ir?B?+l^^CuME^:m@cP8B@oSs:[33ht5=>KQ7U$R0^f3AXYk9c5e:fJVe9K)<m?47Y2Xi?"%hhRnV8h&c%*N]>9dV"#mE`OoOgm([AML2j+*A0s
^kGB*Oj]p125O&12`)8kiNrOM@IL"F6m7RFUo%%ZnXU?a'C(7dY_`ViG_lqO#OjjC*)`HfJp?J+GrDN[n8rOj&@CYIj8CHQj*4$3>R\nq,1J,'`S=`3I+b<2))2Vtl`=$HEDLRn7\m*9h4cuutb?Y^WM4?eDPY==aYheR?t]GJ??o1n]&VY>S=H_<rJQ_QRI1td,?.Ap6Rr1d%:2#4VPa/ujKXUEBAKdMcHaZ=#kp?V\"q"F2B',G),G-TcD]EfY+il(^PLM0$c#,`^4[IW4LangjbMm&532g+I800tP<9>M=JU[1UFYZu02A,6F)YHV,g<mI]Y;gueHmThbnZe*(.n*`F8K>4=`JRf]&c^MfYY)c0bY5O2%>hsYA:lV"]N?TA*Ab(dkoUa\^c:[kkZQ$3F+7/8lqY8\;NCfO*j^%L"ess?0NO?n>+#7'2a`kb(6eC>#m:sU`IfmutRT]LaGhin`glV3)H,YV@oXH,NIqnqn[-g*P%6O
-"mpgpcd)STT6bKIgXP'qC_d1HLW4V03MoD=/esh)j$X#S@q;V/3&q]RR)WTJJ;\\?[FH;_9erj?$];f@(GD-Z3Q/?LqIST@q=k=U]Md;QN$PIl26g*1HFm#f7;SB0ue9YnK^Kl"3-YlN0_Zr32CSUjgGO<]/LoGI4j(#3[V_r]_Gl=>;6c:,EjfJ)&:10Epe;J++lXufJAEBpb^Ca+Y3ApFQrA!T#T_T"3IGfICOmnCQ)R=bnG'i"J</.Rq>NA^BW0s<Mqsg_0%GYm&7jsBZA7mN?NFgma];qK!\BC4?]gpu<mjU<Np[b?o^.u?0OZDTjl)sL-@3to%iH0PM(BdX]I!PHqG`5VAm?Cq9d(S%rC@>0`g@r&2-OI=hR5)N!Z4.I<1XLUbg&.82=%gm9HQOg6pUKoN8`;?8OS*FWh_.O!`8,b^B"r6D8&)Cbd1qg#"/jBnQV<iP.GX;S.b3Xe9JteLdHIphaUA`8jERo_07<:<SaUW`ICa
1]Ia^8jXhX1YNP,/#=@)>f@c)5i\M2r5%!*atRe\o14hfH_Y4Hq-^L>tL4W1PL^><40gidL)Aa&UGNH07?cb0)I)S@o/p!2BVj!/O?he&u!p6f8opO-$2os;!`E2V`Tj]m-V7;^BJdo'X^qh^Bh;1%tujpa14Ft[=q]LFkS1Q?M`\GX#$Q>H5=>#^\U^I&r+[4-Rj40)'p8\`5j7I3a];,<-Witr3O0A$m'b?(5j3V10c:8kb')7-^DlU%u9H?StmReF5h505JWa'L%15&0d]=42;.(Yt\ErOlj)!M&l4XH2Sbm/7h#L4>5+=4u7+Z?RO;H>ee69Gb*drEE:jgm>N8V0Vc/Ge#ApfeoQ'5pMrG$tEj+Nl'N1-L7ej/O_Stj/2n/B9j#eRI6'jV/gbQ78@eD8tUKOff-4s)iSUb"W)MZff)d9207ECEpL?=c7[Ocms9$Sd#p^"J&[qJkWeR.Z=AUFcd4Lcof6SGi^6d5e&JZ\^GE3[*m;
Uih-@FV5DeZTI,Q!pbY_PG7DS+)V*"4n50lX^g/\)0-"on7:Me8TY7'0W&?J+PbI<JsQ?^HPgk/sVG@$Ib2j:_rCSSJc:Hp?C3u>TRO.V7a[SX]QgX\2*fpu!960dO'ihTKK[!LYdU\@pffX/*=MS4).#qrFN4(bP!>+2N1V=kRU7eOD-5j5YKWm:8'dI2ZT>YRmf2oE:hX!b0)hlh3']]&Q>E\DEr]^FfKjn&3gIPb1-H,7n7*-#0;Xc*/lK@N?AYf?COAp'ebaOH8nEr7f$?:.q`T4Pk_h%qnLUrZITl?H$u_C;1N`4]3K\b5$$S6bsjbK^?P7p"(1h(^_CXcl+nIlruZg2<;8[:Rs#BBuc"b'[NZ2arH7l$0)k),?I5.;)'&k$Em/N]hYB[1h%7eMU19jiTdcI<f/4j_mWD*RB#qr0l.PqX_q)l>3rh+>$ENd$kLj=23&1?[VNi?On%EG<tD(0H-\Vik;Opkh5FDi@UpMhC6nH3("
d"ZVstd?_IGnGJ]MmFgd.K6McLUs2a9cQJG&g*e#u;3o0GIoCsVV-2/\nUG_6J($F"[<;cZ/qC0-SeGnl0:O+,+Tmc*XQZpL<VB4drh>0cJE1!$"s*ph8!u')'IF!1g)m\Aj/2>)!T-O'n?VKSAFVCudT^BJ1r*M_^a5`*8N`BeLkZ]_-[Y+AD0PH)YMc\`2*[2T`4/M@V>nQgrLq#0J[WXh2I9la$2;*j]lh4qA,u<6Y>+T,kJq"ALpTUHl/s)RE42Lm$B+*mbI:YR9'3Fp1eEkCH^"Jcc+qD%^f:E]NG@pb_(iddjI%5,'s*':f7S6O'9qK'T<'Lfh6[`iS9fV7fs4Qdmr>eJErjRj(N8(p!duNR5m!UN/T)[m>Y>&P0\(I")%95nfJ*Q;S824=oSpJ)bl&d*N;`g#+Z?4D[Pq-)?a\KOKO!1IZ@Ga+0R[o9@CpW-(&(1kEmaCs;Gd04!2kY<TU,J[BGQ4#^Apf9]5Iqk<-AZcCl;c
m2>h&.DRau*;I3g+d's6bim8pmlB;(L^3L?lDX^p"!bufl_(ME^<^<,TrX-':ejRn/\)#d6:)6\4jVGW`8^KuSYGFaWOSJCC-\Z=537ZZR+8/X0uB.YTPU/dOOFhr=nO\M/%^R>a(dk",GNXTDA._P2n`';=U)(j%"SlkN@=%_=lb3#OLA;HCrh_jK^I2oth09F?\M_^6L%q,o/H?q4a0"trJs%M_InKpCsnAS\hpj^])EgkgQ$]T#hi=[2,+oeF'[>bI%2[Or*R;@-Vko7?:=/fi]B<bBNh.kj1jAVW8Ap1&S]pr3jf;6[)q2"Y8iO3f^B,GosRf,oJ'&gR(lGi&c-!Qf>`,p>9ZDN+^HB1%i:@-IV55H.eFlFt$Q'_#h-a9JAM!-k)Ae%sMXUFNbO.NKJpW[\`bpMQ1f<eBg]q_j)Q`RQ-oAoB%3rNV3]@ojU,^EuT%3^erIm,4+?"!RZ]*d6D^NZL<X!t/=cCT90VTifph=;lr6mC
\dWK%;60et8,RnHO#l,'N)(ZtU`lo7)jqpSL9_mP(d2rtLpA2p.Prloe&7Z0enmOq0uI$CoeP6crsd-]3ep@(Q9HFe<oMiKSqI&d+*^$-86[9fGW9=FB`bh7\\DM#Qh^+j'GfP^T7b=_FlZ2)(\+0'Wi(q,;7Zehl(>4#o=Q+nR-B/_G#iW"sV*j?a]8(d3q'&mKRY42=n[O"];oDQeQJftRO?0LrXrBf_kNZq]AK1n.-'/o?AruX&cS4W^RY#F1qo9Y'aC[^SPh`J&qaYM)s>l(@ubu+bG:!oP-]$[>$s"JXnKX3\\\g`X:d`Aupg)d`Bc^agBVTjRb<^g!>YY<]5m[E[Fk:*-Ib,%alO%f8PaQRq$_,5(gmbb^%s&o$#6o.c9Vc)j47UNYknt[2G(mH7g>+n%DkiY.9fH64`M;N3KY]c]MlLE?Wf+28h`SVc_%c0dr?7BE+)QDV;rE#9_B!Nem?F]\r=b7[JiWRf(jlA\_Vah=`^:c
H8Nr$pq<h4)q9Qt^60;=msnBqB0f_tD%62$)<9N&SdW=qJ=0%$g@T8($AIX5cUWXHM-lf`m!l=jCgWU@mfV^e;:T3S"E0q*7aGM@=[/h3a(UHEk$iHG+p?R-KGaB^hr\J$<lT([GIhA6@[M7Xcl-:@BB%@:B6io2(^7n_ms;KKc%Oo--Zgu%o?%0,b%P5cd\(Rs=B4M.;GZ;q6e1GF4E`d,=5\.5j[RlH2lfY9og"srn@R%h4VSPl<0qc%0Aa"9rE1Z@0m)$[Ftkdn[F6RbIbjtEh.l-cJ;d669bO'be!Ja08BLO/cK#J[TKW1C7NSrM[I=@Dg(?8oerQ_ZE!(\[OaCYj%\C1k$AHG^P&5;fs`ZuRHP>I&<ZB4i_Fm8\Dur9Jeb06N;c&;>MDpc71T]b*a,Z95&Z>Lf\CVsSg=43ODI<VdiFmS6Z&0>&@q@l/)dXJu'&Uq1mXrI`Q]Sct590?^(i%"2LD07GPhGPW1t/eG_SE;L6&I`X
;t=&T8ElkA=Mci7i4Z?KW7!gpUE>h46SO3baZHeJmI9OsU1C@Xj]p0!1[qdNi$HtW.GBC_S-Y>*.;csKi1r_'TG^%;h6A5>4r(ApR2IccKLj,EVun4r39l:^R#a$'0B!paXgmG]O$n9of8>/+Pk9KGoA&Z,-mXTaEg)>V*_O`!a`q=FQiG9'<Kq%R!g&OX^e[al\1Zo[s6g:?.12ie*FDHtup&6Jm,nWXfpHC-'2b%-t-eL^%>quo)V?m/[uNlm2=Hc,;oNTa8->MKKcUT;OI\=\/Mc/gGB&@Z-"%E:F)Y7VP[ZE`FD$0roUe/t#&0+I"A)=OhLg/8YoPN`\(kr>D_YFp2&I=aEW`at34rSaV;kH)8Q``_ZukcrtNPj`pM=@[1SpmB8&H[5<iB2?sX4Jofu2+)/>a!$H4@Mn6@^@Ps9"*lL]joW-^rG(g$l%X;*cLQ!Xedoi-C@<)R?[@t"M@UJP3UGm^,=g`"9/2El!e*4\ZN'*g;a0
/0DssT/9e9E,dQC+CQaH=S[t!0mN&]I"0P2KH37TLf_&m"Si+^Hu$!(O:NVLaXYA@><J&%LO+3>B'E*.nDYM@+*5IW^m[pj1:^%,),5FKe#;#SbNWLkhjb%(/4FT"ppi<gL(*a'/n8r5#l2D'q%Y&6;^OoL_'3j#HgF6Qo&m)b[Kq%*?,Xd.DnF6RUh`nG9nm%2`reMtSFlU#)o3t_;O)h1YQe%F_ZmpN]@Ddsn=I01];\?Boms7^[UoGYXgVC!F$O`0;'5#R`Qo:og)T_oT!4STs8!f8uqjF&[uH5[mNk"<+r2R9=WIZ4q6R"%>\0Y4^$IR5+#kAIF5H(+?;$-JOopWIo#@cHaNe4MTZ=oF-KU\_G[b<lN%-)gQIFGTWcq5[Ml(/oK3H5q<=;[2*^:[`_(./,='^*W0\c9,Dbnf<s(<.7P(@VSlLpP`gTd+*Pm+f*3okP\@Q\#.H$Ue1FLok`Ku^%1&^iq\j3T%:jZ?/:E5(p=Z=9R0
sGC\U&[,Jhq-fD,44>=1m8du@CgRA#JQpB-0>YF[)m1A\(Oe\jc&;tR8(P"_(8-WXh1[';L/e"%"3o":nKV"-fXs$ue[89JI?j,ud5c)(*J3F!V[`&]PaZ#?mG$65<;I@kRP:$\n[3:p0D:gC&FAgt'm\Z[ekf\!g'l2::[]h^i;r88*6>p?rU(:BJr4%S'&0f>`?%lbbGXt5"ApTjdRj\0s7du8QJ<s%B93j0pCku7J[MU'ZmG:V=C2u88NaBD8N(6Ts,FC^9sPo`<4$esiEkt:S#hNFaMAn%7M<,S5ia_Tdin(%WGHl;TMTOTrp91nAr?Q'/6[n?ScbD([J9fjX\9B-R"D"Rna_(1;U_te_*@WrnJ@nBe,l/UeWe`e?oAF>U26S.\=`QKB79l=aQQ\iSo96]sXnpa/RF3Ng<=LF_kd4$@1Ec^r+BW$C1X-mV7U@6D$SEe).>LXJ'2>\h7j5FTDoabIO*h%P].B]P;`aHp.W/cabO;I
e-N(QX^1]4kDMm_ou3A>`'`@LmocY\Le@PBXDUiJ6`]GIYVrcROf;@$AOIel-FOsaOIpr#%:WLearEg+Fj:B>E!Ak]:G&\i6iSc$$^]BZbecHK@L+))L%'Y;,A<(mJ/'BX"!^O4Pt`2OL)NFYXQ3PVc'HcSt?6rQ63pn$(d9[?K>r,XiB_5.J1(jd]sGKN[sedm0MF]&1Y]44J%1"Veaa!mV^:5RL,:Qr.0ZG,'-j&`+lfm(uR$#dPc2+N"MHb/lDIds`*OHsDPD#<kGnqZeZf,CW.^DsP/]>(2VY/m<nn3lNcY:dl!^5B7`]?0gI038B*L6Yj5ZhRI!e`.Ec@Ir:AqlI72+6Uh4bEC1.)Y8j&NNZX;[DABjBCnE%>4IraFpY4ZFF(f`-`'.-a@_N9GO5!O/#)%)mHe1ks*GBm+uXTb\5>EP1dN^VrQ5!Pq\8i_#l`$sgWK0(mT>LW9;*0.ZR+a0<a97X:%J>IThfTfD@b0!Bf['UiC(
tH=mGA?;GO.5G(2R/mTP+Y__6$)esnDJ8Mq4qTC"Od\([\%e-M$+F3c7\=ma%TWCZ[E1atj+]R&>)1Z"te.5>H7NdB!hc:RXG`lt2!\AC%&FQ8:_`RKr4H>VnGp$k80-;VN:/GIZ1U(W75/_B+/H8TRR"Ke9fP8(dLDe[TTG;<K7F50!70s5k%7S:rbRd<W*;i=nKXT\8\<eTAcR6ULk(4(8#L,2nuB%+<<?#Xjh,u.,-H^MFO>gLnU^U2%Bj!<[GlDOUf]_5(oQDNS8H@)^_ES^Y!gP_u)H&+N;`s*juTMF#-fch0/[gYLfRDfRb3sT5R7Ya&gMSEp21rj8ZZhOe&2;'5P?#iWsQW%#][$,9\57c^@'W("u_4jH]5=lLYB0LWpHi06nj#S"*h**1b;h6->rWpdTLbfq(XE#"1O1uPQjS5T4H.4kV2@2e5f+FMppU<XUS$Q0nqT;]R9fV>L\6NRWom9^r'_1cb'!Nn5l.,<!_;j\k&]f
\c#,u+^/))4*i7#Yg9dJ<I6LdJDH?N)cIKq?LEp,H9d?,Cn]Dq;.C70:1Z@@KGX%Q>F%p0A%S\Fa28Z;B,)&^0_noQZi%=;\69b-0Tk?Wpi.`WJ+j4f5NnaF0eoW%U-G+1>r0C.L/EL8u7biE#M6:?g(8QjKtkO5.C^UJ3#k/./GN,hW'%Hb5^e\h]6,Oj.thHrlupuh>ANnMJ[)_Sd0n1$42*\%n=Cf=UALbESpgF9kJlaYUraD*BAJ),=>Zdb1D+4qsR@0cZ?S9sn8rm1'i`(]XWUXc^'a\&ioG&P],T#SOpVi?0rrUMX,n5=&GAeLsLSY`aEDAYlr9-Vr^c\rhq:h8<e/FJb'cKnX@`0E)mS4^@>'O&?)B;;&,&*t;SR*OJXPA^[EYKu@$^6^pE'$o'Ce`D=Ys(R`=n\7Q\eBG6/VXOp5T%V6(eq>@hot>d\,b-AUD\G8L4.("Z5*4Aif6j;=V1q,[3KpZ',A3@&(1el*Z;]NFeN3
`-\U=]'q02`oN[AI[Sife87t#.D*;tRQqKEs0EbRArY1r\8Aql=1VW7SUa!+p&;5ST,?[L`FI>;F4B=-"G[!se'?8b;Mb32fWV$fIJWA(MBQn!HkJ$sUL's^^JkV0E'/In^YW>2b&VrpkABBa'-)X<BJb,9#I@tWO!gc#+Z??[K.D"]14ro&8(oMlb80:lL\(XTi0g$]&<pO>XpaZ`-)[jCbVQ+<u:kJf/&CUsD3S*^0D.eVt;U.<d[=SQnmqi:DhqaA+cS%e4o@<,,Mgp.;#2V&aiiqCT279)R%kg84g?aEW:\Kb<)ph,XUN]upsej6g:5$_bkhSlOc4b`S)I_'KFYGFDpX'W\Fo%;ED'?@?^=2MjiW]b$!=SYOh,/W[9I_FU5pZQgbZ0$8sj\o*tQ:*Rc1/.l$@Mq$JRVe.W3n[@kQb0bk<+1""?>1ORP!Aq5Afj6=4j,u1f]%MFa,p6pkh=:&\A^l9O*S5d;$`_`^%\3r0,*0blT]
_2nN0'%A:8cQUrORL]jEjNk7fY_,HU:n_cMMsre&4DglJtqA6#\U6iRG]-O9RQgIAlr*m8;.D3t7XIJjp605@8rfo!nocYB7"2LNJHR,[]Xm)b<!Hf=@=<2nZtCBasUc>Q_'-IM+M59];pkm`&4lSTP5g,8=4r=jIj-:G$D:HVJ;;<+rHE:'2ddh0tZpoJPPM1Z0;AI,@UN/u[=SU%9<C"/c!?(^g^9cqnLl1TSp+5s:^;*23(M_9BL12FMrG?W*%#%jT1cW3gf#g/A2nkt-IalVaD5@\:Q*KM3R*56`PI\6:O-@(Xk4OLk*Vt>G9cfo^U90h'UEod.3GhN*Q=JR4GCYs;l\FiGOm=PA.\N_QNr_YDWrd%TTU`9.KNu$R-+F&<m7n0tHbB;I3?^%(ZI=lqh_2>R&3un&DLG_6.*T&VOrh6,fi]4\tW_!nblr;P]rRB2:dP'7eN<Q^OC0Ck6`QlM'[-_qbDCU:?NA<^IN_]/Q?:#<QP/P
n7!U44(U;+lsg\#B8idRX^s$:s%61q#\YEo)2)J>,sa,PrB]B@qHDXb[pru=N+B>J:/,u7g/lLk+AVcVT>Shr6)Q.6G(IF5ph''GQ=k*RugnI3DFVZ#"=p6RoRFu]tLBB1#Z9`"`b^4Y(MBd^Xu8FhK3V".KT@#<:lj3],CALM<GR9+K/3'.Y,b9E3)F58tTPAuR=L*\rV/H!<LA7DI]b#$m>\Ro"bdh_Bg>ugNl*kCo_47W*P3t%nm2qqWn?<VWF]sO7_^D@S3gdTnt\#RJ]HQt!c=ecd_:sANjP`%D$+1GIu%EkBBc8T&oq`=4VdVfZ2?+h"CS+[H6Ie@_[G%7>mU$^t6pfXWnF3@5nkIbMs:fr.5WUE[:Y%)nA(HO@e>ihDs0AX`YdN>TX>R<CY-H,ldY<?Vk9o?U`75\%nMNd=m5L9,m\s_osT"'\.q#5;+fqR>PY:e(bm&u>b3gAF>a7aXlXf7`14\)!*=L1RHnc"_";e9=J=Hb
rEGI#h]i=,$RRX4@/]$S\l0[&&)C;lc+.doG7r`-.6Xj(\150RKu40`sXUS[\a\t8[faf&L#H^_McXBKPMlCI#c]BAm7l-d>Vrl%b.YE:o]P^0BliH(1TiMr+?R`*4*^SpmcmST8??M<*O?G8nu4/!1?VL&`toL"D+8ZINXO#c*-aDP[rI*9.L+tOE*Ml_-3RC1;pEJ^$q%6gpqa."<<bgX8pl<4/Kce#S[-g\R&3n`e(lM`hc\7Nb@[X1^9W70n0a7'q)]6DHL7Q=MkW?P8b(l*=)Y'[iGF&"et@Vke,lcDASoab,n8`FJ!p32bE8`L_pRgZ#(]TT_P*-04pCq+%Ejf7rB>o%e(:=Hfo`pj:CjIQOn&ttJdERLPLr:N*,8L1T_#GWR3Pl*J/G-PPR%;S:2cU&#*53Mt4oD+@1*@0.qHB(Co\+B%/ke<:rJ*qBt]k/XP4kD7X3*k$=W;9eKKrn"gLKc"d4WuU73=WrrctPeJ7GdM1_7D
S=:$.PtDjRr_M!W]Jm`/NTK'+FbEdl?K1#^LoVu2$l:\=+u@i?R8X^_;j/"BiaBTkI0rQ)^Y@8A+1EUQK&loR"ZZ#Z307fDO.aA".6<e%pSLUE=oVe^Zo47/Pj]!J?4[W6gfI*otY1\>:fNu?W5RI1mkD*0*GO\N%/bscV>bWC7t;<dS^_cR814UOetoJ7(<mt^:(^cBO:;>sb^46teJl\*>/%iZ&Dot)"59=$G1T%T`EVErr0^<IYsZ>8F3emfkC-aXIj^Eo?C4KZfP&'iF#&"=qc<jZrE2j`@oEr<b%euOTga_&[6N1%J14A+;lr'?M8>I)Eqr6M`cE(<Y#@epMUPPZpqkt&BpmiJb%QSYd;D]ZCTDD,D+V8jZO&W@#%B7irRH!?/qVfnNCYKnQml*m#8EmOT6k0+rWPpahpcI)dggqL&P>Lf=i9QWJ.58NdH5:,pMjI4[+1tsnCC@WfdX0XXg5N;]Hru!Us.hTD]+W9D\hV>n@Gja
T,>N&g_cYnL2hm$,6Ym!3([Ism/9V4H`AsRd#kchJIdl.ZKlA)ggir@OZM!4?VRN#d%^Lu]#6u$%CJ*LPDJ,5M34?TuOhSm0IOGu(-2LQjC.<E@IG?l+XJ&`J`[70Do1en^Po8`:"R4*!;W_5Yg+[P91S([bHl[_:\oRV<M4(\-_(t&7[I'_;V*ai@99j)u;q505c&o5j;[X[-]'WfA:gH?Ql3.!I08Wt+7`^1hPen1F>$>\(WA[m4s33ZS#iZkR*V/+7</qFkc4sFLWNu<<01Rp67;u,j@nE!o$UrtOmj\VCtVk!15g3n:V&M;__iL.9cj.GR\rWPt;Lb(ja)GY+8s&&Yk3N0?GK=dnRI4)et`n/m>#aI:F^S[OdVKJ&?N1YB$REbKqbY\YGM,s.?(D:YcCJB\JpI73i7Er_>XE^3M^G'?Xe82cE7bFdH\#9X;o(tr/!r@R^bH*Sqc[4i]6TG%@n"r<upWNJArp=@]Y`:.;RYn\*g)e
8P\8m/#jnWcYQl#`b]sQ:XmP.PK8^2M!!B27%IJ^Y0lq4hCm*b\V>^_qEHeX"p`j5JA(o;!XC)7s>pV6&U6$gLL1PG*a\oC#4''Sr_m:QBhH2Z*^=1+J`FSGTrU3:t2EDuJeFREG&>rho-Si+,$/Gbp^RaSW8<9KgbIS\i,TrN*3WoffuoQa:+!nW?r:"q)*Br@KkX\knUii)e5F4:)!gXqYVeu21]Q.])pWfTcP,>*kF^Mu6lo6Q>^;i\j-\JNG6k'c?i2N6/PF>jo5pkKc*6p1$Co.Q'R:XZ.XT=h;2n)$'/DDdS.Pc(X3o2TBW!haef]<1(+-ber]_SPYl0-]58=bDWmCRgRs6Z1()8:"6"RMsG><_#G5ZTQR5H%$QZ1:/^cArM(lXAk*r("jJ@cj_qU8t)4_[,nNM\XL96cD2P`Q]_=HIEFn"K-n4T1o:X5Cpi5E6`OH:h`?j^kO[H0hq$Y]cf%:k`5";:SV:"WNu<fCl'7Ym[W_
?Dl:'-mnEg]YLNN,`Z0AqQR+^<l\b,MjGW=7fW0FHciB>5jkBO>_WOR.-U7$/<(GO_@VDN>UIK(4i?#3"oFbf'h/VjQ+SWD:=.>Pk%GGBjAGhN)dhkQ"F9MsWO3mOl4B;4bhENBDO-i0D%q3:;c9buQ_Vc^cQKqu?4YQ%Pc`:aTVhaX158n')E7%QQ8lLZIt=XIo.HDC4hS9!Aufu,`?7#c7>bfL[o8>2gimiRMG7M0QHZA,LT\22dK]C.,;-\]J%7WVKLq>H%b#g^hH\mRG..2U,$I.5M9Mtm<ic4h$lU^Uq6M0k8Nntr``XR*pJm]noeZ56,m/G:@.,2V#Lq;9\u-`O?2fhF['52qR@_)<=B:7Kh98oaaIguQ^7g25,\r';3]=ERb48W8Ls]hV7CIB)jVLHpo#gaTh<H/DWakm5g]kHo<,/aSESRJZ<ZHB%)AHWR`>-]X%g$Th%h^6QN;XkO5\SFs`F?h;9Dcftl2qYc>)T<`S+"el
p3NN&jXNO[O"<M$[ppe_PAGlC4,S]gfdaU[91iV"@9OjWe\Z,+sHF#tcDhsN7Wo6]71.5/*t[&2.Dm4q'qql&Ms4!uZ0p.FqfAa0/9(+&A6*%D%SFa`-@*?H#`Y-^6F4qF`Xl6c)D^AcrikXc42KXq[L7nE'EaBEDWH01_VMN^JQ>)?Djl9)8,HPcH3PV0W"BPPEa#BYl_QUQCGE18p#7I9iVi:<lo.0&pbhTM^_WgsE$bLLjZVeJ:/6Q5"8A^U1i\X%R/\cV4D_!&IJ+L>;Nhb`s<mq-SPNV5<C:LNR(Oo@s``oqoRSMP#T06P60B$%&8c5VdgM%q`)pa9B#'_eOXfeCC3hFp/uT(Tjd1NbXIp)A8$Nj:jlHWM"^*5&50'tmV8U[;X*s+pLXX!KMHZO-4Ah^3GoiTFEhH8ThoU,Gj7e9Jd44_l>r0)U\<SrK,Q-9._eF(P?rE'/aB3V>pM+4c@I?Klfmfd.0;;qJO]M02%qMLdamr6O
>j_`bG<?@VU=)#!@d?=_QblE`PIH=G:72GQ5R#l5-<SZT9"3g^r0^W0khNRc"S[&6*:<P2Eu1N-R_?E[S(r8u>fcY,I2-&*WlqTdQ046:-a(r*2qTor,\0,T.S?@q5&K/H(T9o7ee@-l3J6W9>In:,)JgSu;kIY3g@VKk>!Y,Bg_cl@9r\D<Tu*I$43%Ou%7:EfM>o=)mr;56>a^*^6B7!&,T0JqZ])*\Jh]k*S7&)j'qliYmFbPcZPbLGApHW\F(T^a5L4`Yj(5-m1W787P0IC%i2Bm+r.Wp92:Nd0["f<]Jn$QEf<-Ygc[qNb=Z4<qn!I:KpXs/o(Yq/:%/h\]KDEr'l<3GU";I%R[=1:gb<@U@j7oP'm$SA_HgEdCR!6`o:;I%9QPLGM$&G+5f1_S\4s\<TuUs5`HPDr@#AAY*.oWfK^B?(I3A4CWQB@TFS[-*&NU]m;Ilm+a_,b-S@?2*0Rl:I\Q`031RGFU'\RH7/M@?[A41s3D
5MgLA3/1Q(59Df!u[H6E"f3j2\Z[\bK?DuDV]']OF5I`o7e`ei!bIud(Q`>VHF7Tu]%+#b_,eP!mUO?A\Um(!QPqDoZH+J.G_5)T%!'cXPkgifoB=.1M[mM!ZJ_Y"%D\(o/pjSK[6A'O^d?<!KRS85f,GbN3P0W&LjLu;-V9=Er]FgD;/89p\Rj>n.g3G#d']0.JH2O(SP+8(lSH7-9'D+=J/G#G&86oh.o'U)V-4cri:V>3rj^1Yo7dX1ZUoXH0"P<K+RF5(nof2s]kIo:dl(D8'>Aq[%;V\lYO*UC!ec;TYd'3fZ3k69$lq),11+$CeG"iboh;6Lk?cdsLYcRi@Uj)@"jGG0"NY,YZ)Pu:\EDu@,RO\9Z:<>4lu6PtH&qb=8?e5a]1i)0]q2]Cs3-"N?O>!Lh;87G]b*1(bN%X.+3IVcqoIEliP?ZqGC=t&W^Y"bd33t5]&ePBEf1+&^kMI(7JRMj,C"re5$1&*l8Ao6B9Xo`\7>Nk
0(Wa##gfp\n1m.J\O4Re;$Z.4h(QDaEqrtD7^q"Eu!X7boFhBq@K0PWdueKYlT*q6lu20uBl9cBcCW-Yhbn7m_nQ"f+9R[J\08<cd@4R)cbYFhPC_\.#S?+\Vj_OZN%B="CU8faO^]5q`UXj0c7%.E6TTAnuNoE@fNQ:;S*n"0fj&%hH.*j8?0G0Ok[rmk@!4EdP")77E3A`jEujI?FY(n3YOCFjbINM5!ts7&UuF5GKh<,e6g9p="4rb9kekiR%87/kM2A>5ZF4mFl)*%T#`gmUBBf6sK&(uKgi/E3oTqPgX>-k0[mk%I7ja+&Bk46PH*GuQ`VTRB:RmT#D!1L[2e.m5aWgY$l8X@+]3CLLfYn![U,2<3>OE#u1(N5%EEa^<Y[Vi9.pKco(H!q][eT$MW/JXZ;C)obP;5O7b;PFEW[p$[^s.H9oOBKa&9++>ckCUCSncI3'ASXD#-gUoG+7c`jT?=`_P7p1de8#'6($RN[FVMs-eX61
3te\"!QA:NV8q(W)eLT2cf+&/$g]\`MJ:C@E.NjrV2:@aF9f;IIsq\8,Efn/_96M:>=.0M%PAAU-*$20s+;&9[*'C0oXjbN,$rik3]WPS3e#]cG2OBPct@K;M!ch>%Yc5Z*RXT[P+0A`(6TB*0P]7$^JYfVhYEF_l$ES[_CY3]CWr.7YTg^7#_cUP#1__bmO*Dl+[(!bFTT%ioMW?e&r\E^WcJALDoqphZqqoe#!3RO:j003l:3@[YLot\Zs][Ct8dA923[lZ&#\>gY%htcp'eUPp&h9E3.(UtN8GQ$CLb0E$g]`ZI)lR1.kH7`l:ClZ?3IbdlVpf(n)L8]^*p\!PE_Gpi&fAP96SFMVV(>\)'44`s[Onu`u)P_#-Y4#!VhmU\aDkbd"VJcV##N*dMS7BSc7?CL%MObjD6sfneVYFk*cLaRSq'sp*e$D+B<-(k02J*?-_rYEPa?[G\4-=Fc2+!d*`)Nm_/nFs/,lIC5NIAgKh!o]Q&W<
#r]U5'6s(eb`H/Ok;AuBS?%;h#D:!&iF`&=R;T:/IfNZGSmWW-d1ZMqdl'-WCBZ?5A)bWOHNBt`B7/uS\2YIcE@2:FN)r?&2<;+^7?g&Ei>'*74Lee,q+mKCqbT:aRor:<Q0i:CT".J89cBd<QBXX<*',;reCSib=eZ!t6sIm&ACd+p-pXd4P#aZS&M:;6B:-F."d<%r^BaY4d9Fq9e-Ol5qYlJ9pL`7sZ[nOM'Ek9JMQcHOK#W+l?I\#Oe\qmH5@ffFn.-C'd?-=DL^p\qH(akk")Rl:Msrc\54>`SGtWRo"ThmMduELQYs.q9Nb\GpUIrpjW'U<Mjopub43en=V[j[I2c1l#GV=F\q]/T(BTmjD*DBHP&+SXSs&:o.Xii/n93p#SsG/H9HO'q(nbr"8)]lQ\SB6tt*B=>>.@IJT0lJK%pTI(s:dCr;%qq99Sd\s!@Ps3DR2rtLbtnXS%LCrbqRWVC%F]r$c$R9Smp`T]V67d>FQ^$9
lh3Hqg,_P]p$PLLEHBD!m?FqjmuoBS&E6=f^3o_CQDWb'F3s%P_##f[.mZn05,0=tN]s'(OIq/<E=K7$/bomF*4#EI)f8J?@r.!h?rgg<m?9`.-D("M-W&Y\L&>'PqidqIk5?2F!#m%eahABZ)?k/:8<o'rY93."MF.e.Wks%J2ulG_'D>Y3+9n7VDOM)91cD/3\r->8GhNhn7K[?oH_Md=0dlq6[1E.5#calp16>3^o)1!=e-#u$@jcUV^]rfm+T["puFTAB7"VV\F81TkdH6PfYn7;uBa;Z&_l(&;_Yp2hWlfCnach6Wk]rn??m485[j;?Vsrm#uI"PcC[hfX(R%q#.KNK_q@NC4)"D=l&mtfBK:e%,.=L)34!7rAVrJlOP':-%,/#.16#/k@o?bF&W#]\M)GZ)<D@J"L8!LrI-=@c+a._f,aPD0uU+HXS)Ck.diQTE-@k#iJ=>r0PA`XGaeSWd$ugGO,5W^rHr]d;h[S`n4U'5KLN
W#9cQT)e?e^,PLC**Z9$K8hXg[fXELVfnG=]a6$KJqKQSX@CH?YjeL:0q?6T!iU)CX4QX,NU^9B5OS^?2sU#4]#mSD9.1^a`2+NE[#jQL%@ZL7s=aJ1K9[39*b:WUn4'GD@5ruFgV??7M2V<Q%C_sbo/^d]T<L/jB(-I>Fh$_I'E^;\!<eE31_n:.D9^[AueWbOX[?N't3D;a`SSmE)Un@L4D^:&":YMMI?46Q3JqOOfm=,sa;PAfc"[j8Isn?RT]-Tr-O-7?'7npH>RlBFN5)UgK"'/oG]mo>]t8h'.Tli$.9QeEsG/`/nLL#';m6MgHn1/b11fP.f2QBRNa;-qT/Aa,=LQC2IK,h)(;^N@YILs)VS^F6h6FK+Y,?!f88XinS^]%MFo1WT!U18]45Rj-PSWR8`t,]1LYC9h.[hd9TeS<f_ag,mQkU`GqDML@&KaboW"6*@MCm^f)5d6H=QI*lNSm&K`]M50N^PM.`+*.=n!muMNNR=>
0lVjs8/s*n0/<d4&hCs4s9;6;"Fp*W[9*^?Rn:VrXm3`M+Cl@!lrDY^"IIPk&Q0M^]&4eL7'q!Bh>hp%`tmle^dLon<o,(Pgfm-Le>.5df)a!u:<<5r"62I0;5Aa?YDm[S:?-MF!98W@\I8(0W^X1`c>gQ/<Nqn:=*bk6&1b-dOCU!#*9c/EL0Cmh!hd.)Oa*@QmkkFi#[fWRnQ]NUT2l.o/"oV0!.A7KNW(LE-'4j4nK?Yu4`HV;AXg8$p"'YiMiB>-"OdrpSkrTm81QC@:$T%c-plc1*[+#oZdb]W?54iHNC,kPSX4C2NOWX1$L#lTaOUOKD=[j!1aFbo`d.VbfUgU6'Gs)^T^fdL0f4[rb+,h?-f%+:,u-$EmiFS";U"SGR_$!io@o$G$-Mt>4)FTfaWAOT'H]e>H'q=S&S$_eaBcEoE$`r&7CqWFiVl/4smp8-'Vh7QY.-MlX`2):+b:Ef>F04C\.G[qfA"1=KGnbCJq,+Iq:%oQ
0ufps!?\Vp3?`PMRjRaL.Aim.;Ve[()KH0k:b?HgleLHgMW[d1R!kgk-.eLIufb4i5oG6_c68LfuQcnq]c;u[A(cP\lS4+^$fS^Zi0&$/,\\*(a_T#ttP`'bu]7.7FIGs6Ym8gcQ]1Lqm[D5HdkWF^>scgPECH-#$Tftn]]fQl1g*5r0pO.i#aR&<l_q[P1+a6`M2j'dDCZo].lo.-$C45SfdQtIt'7J(A-M/\)S@+%pNA;i;8cLr0rT<i*f>Z7j:a_I;#EQ\Sp-?1K**<;L*7UNk^:/!+cB9eVY(+HsnRsinhjRY#!pUd\R9f.-4Vbu>,@m0eeo760_GHs8H0BRS9lf6D6FuW>s#i(rb4Uh=7hr%SQ:H]U<[X,#Eq1&4WqU"5AkPk#O?[@ec&:_NMZWBW-WLDZ-L7V'l3Ue=bqX*.HjmhPt(MEPID+OCCpfle)AoY;\D-Z^JcZD0=/$m"(%5N7%,(Q[8MAg;<0fM5sR2#UFl>>sMV]%
Dbe#\tK*P3+R)pta+RtkjuW+k0b$/h(d_!POQ;cGhCP<RsZ2\uFcPc(_X4$&Qu`V98`qn-fFgi_t%@fB0gHg62r&p@d$qAjN:aEC)R;9h?QUpU@(9gkT.TA]B+:F#l&??@f17.Z:SUN52D'=Tq@b-]>:cth?T+^9Si0AV'.[u.I*2:L'3]k9j5?'V(sTUYA1WHZ@-H!;9<eB5<:F)O)!P(p`&)SY-i_1.$T$M?J='l1HU$]rXbs/!61&X[rd.4Mb+WK5/T_*b>"1KunV]l8m2q8jRgV^;;*LYV[ALN>R.MWDhQ`#\6l>ens_,0bF%nTsse$]o/@69A.!If29O[:rI.:nN=eN7VQb.$Wh`h<@AHP^=gGWb6_si]BP5Q>NfhKY[p6^44@eqS%tQRm$d17Wor_j#OG(U2!o`hIC2t;1?4WCh])k,LC$Acd%niSda%#9J9XpiSrtqeuL8qOlh;1:=!oO`VQT@,_!K,eE/:,$0s4FqR9ut/PO
VVGu@P;QNHRp,n3L&WbWLc40u(+[T82Y^8P@T$"m#I;dS<cM'JMM*MG4Ie@"d]1MMf6Pj<HT76d:[^fk`WB%E$s#gV:t?%).4q6&Cj,h'bnm;#0[)1lV"s(B*A*03:-8`*VI4^"j8VVR-l2Em<&;)a\?I)Qa-_6_T9q@*CB9@$M^H<\`a<(^3C(clV!eC@^`&(V0LE>+IEAH!)TAr,D$0Bpke5N'']F;q6nC._suhtZ`I/*#+)+8:8nJ!%pgQaWq)['+%W9d>guZTXM5A&Ni@CV0G:i&r5\HM3-]Paa&Fqp\m<:$S;;;m-k&s(8k_g!,n_Hgc:C4JTeTqG50l6eJ:ZhDD+E`I7=bc`[uZ:Mf7>QV3%cPomR/@8C["mS"]8P4D.$]c_URmE$489mlnOnViXa3Q[\gFWBMTU5MFC<f[NI;eP.1S*QEuh[#$,eG&+qT[E<K3`FjkcV1XUl^Vfnl6G74n+]g1,Hf8Y"JAcS@n]BG'_sUV4;+
oJll*nc8Ilg\\";F5^+LSR:n4*K%#B5=5'oHH0g$Z,`n6Brds\I#Tr?%ph>F4B;U^TU$^Uhi0`[dT7Uk>Q?2kU!E:,.SqrO]6^hPNJG#CQ^,kdV=@K,Ph3aTi@jL[3TT(K3tSrTH'N+Vo%"Jjn;G4i\`jGsn506e<"Lu39?P@msUME\r/CA9mf#E(__hBRe,rW`+-Are%=1$>[JT?7">a3O>!Q,u(^pH^ULp)d(5oLdp&c,lJ;O6k:2g>ROiXn:ZB\PM5^oH>Y^^V7)TIXs>^kRkYBY<tcNIe*2T#L7[roO_Ii:X]&N%.@JtUujjL=k!VYqDG2'bC-7DlA\HgMj?RT7_J2+`[prf9p**[MgmG[P%T+uS^WB6ou=F`MoYh_nAR=MR1h(Mb1#2"]+]O?9f2GsMLPn0+fG(`Luk!;n_(nk[-V[+re+?oWs(9q=?-Htp#[Z7=1eGhWAT,P\9P=q++$'a(FX'&J+GJjC]'&0Zk%J<m@X'=^+-
i[?&OY%?=-4K?B6[!Rb7GNA0^Y[S4s^.ffP^:n0cujGZd=L$sq5%0e+F1h@&Im*'E<^2f&"kK2hGG9?,J>B&:*U#dRB.\R,r+OW&5/jk+l;B7+GLHG``pCj/uuo8-B;`POiNPMFT+[,0,p3+`F?_u7<ikU`jT?qfXoab\'qQgpQr\`F8p7tsNtQ?]@q3lp1%l\+YfghV6o<r42Wg?VXKS8cf$k@7:+K!k.8#CsI[T@i=;W-@NI#;eHoItG[856&U_fnC@)h44H,++O8bgn3c@HQ@tkG.H^/_=!GSXS*7n05o/h.=6a#[t9OMN@F:,iJ@9SW(+OCIleEq2")i&b0u8Pq>#2@@J\?1l1p(GDr-7m%_+7I*@`7I_Vdo'Wr7quaHt3gSGht2,5cDaBTl1Z^eJKUWLWe46Wi!t:VJD3LsVAal*FpX78BJBa1L4h<&)4jrL-Hg_4@@CAA=Lnah*K5Ato)+N?8'nBHo>i9q<Gk-]t#\r-25Zs/Q
(2Idgc\B)miU.;,K&GER=pgkIuJFErAN7Ij'ch7qifI@9b&0SXadI(/j3^;iFk)6Q\Qf!uflW+UrAORoHbdf4FV8'PLr,n&7KB5c'R\$IrYfsBS`j_r5<?!REl>9Y.Y[-K`Dh&PV6RRoE3W4CXr*pV!#SaE719$;]M?Cu@3kks7`[Jo?qdphs;^?!'TGiIPo\FQ9#1^QOWp*>\T=S9.X`792TleTm6E_&9O+283K%Z'^Q8:[Q.J)5TOFXNt647$1c83Le_fi54#bGps!=*X0L5>>PghIK?CP,U"T0fo-*Dqd2%WqiRa<Ao03dp-.lV(\.(1\l:U[D*9B0bAMI@IY!`Mt6O2T#gT1=q4TeZ/^6SAj3(+J#FXFT+,\]V0Nd^OF@)I"8ZYG4n[@r02C2BfT]HO@Vq*VHD-e`qQF82EGfj7s2P<BX^\p/-HV4/O&kHN72)UGUKH"Bg$4;dO\7oia>D'm)tr<rl-$2urUo>`<^ms3C>Y\>`!i
,f)@&AfnTW86ci(>5Ia"DTmk2haPuN+d40a3K%3at<c6rTE@(uFd)I>;3*<PgV(_K+AVLg[qG""3Z^VVk2`0%3G,]TGmoO,<$O3lLkrsH6:(JZ(=]nNXQ@q'%/,S*Vn#>dQnrhPLDC[u7gS#J4PlC$05q@D('=>c)"p!+]Srd0,X?6XrYhe%[L;!>Aq1$h-lYEUj)1N:]Fda[@2$P!*3-Hp'4R(Y^a4.NP#jlW%X0PM*q<o_+3g:a)cm!m;eh:7q/+u*UkR30,pV[Kc32r=+^9/g,MCV*$!mOuU,F4S"q6.;lK\348UP7jU>,1hX8(Mrf@`<Q]Z?8)+'gO>(pr]+Y%r*tJW?LQ\dJsc9Y<Of:u`+)=3]9L%Cfo)%K5s8%Nl1`9_m&#^17rq\j>1kE-n*rHD@P1?GQen9s\t-Da&uPPum8)AM!>OKrFlJ>UA=RVK_gJ$.hU]<!^)Qm,[dam4ai0*DMUA6!J,`!fdmJOnNO\$bgN`t4,(<
k":%Nf?ru<KNTlQm7[BIm54B!X!c>a&pZPd]XK.6DhHeI@-`6T@!k"X1a+8$kG/ORbhhjV8<8(&UIIG1]=R_F.)V"f<2;AYXX_rA:g>qp=o9to1.?hS9"`q+FK(Y2c`TC+jL*4p4'Nhq(B@VKPkLub#b[4?I][D*Kh&.SX8l#*Qim]#=2`uO5Dbsf/)1ZCfcUKt0I\)46GpH42'kb(WPf\#^l#4[\EXU*ZG]7/:$g7S,_ruSsuE=;S"S=b[_Od./SQ>:,Zfo/nU0O0;IcHHX./8);.r:p$<VfHfN8U(/sOM.ggMf+"$nApO!]q3e^d\Sm_j$HGPiO#1YmiQ[*TUKCddG4s*6e73>a,T]626RRPYeAYsh<k3,-hZ^&+6d;0O(^%&dnd^VSP=q(3;_Pbm5Ro2Qr@_5IZd@eG"WbE+'Bu$r6'ROfos2oV9YV.6&Y'sHH>t:ZZ7BPQY3\\4#`)cT68NI2JD@#XS$UC+nUP$*2>#'\AUOO-eg
$-O)DK$#dDliJ"Ci\UXC\BEGr"5D0l0>%rX:k^ul\_"'\VK7+*&Jp)p-r8bYET[Pbo:I!]4?T]\e"5:AZpmsgt]@f=#+C<^ITXe4?2[V$E.mQ2rPTLF#OXKE1TXI-7s0UjhZJ+YY'I\SJQ:TA1-/jf-I>t=K6[\P$5#O0qo[E<Dpb>*[=-E%lIQO`mM4[/#$R+&.-W8`"E(BuOUJCTMU-^=V@oEWr-4(?a&bc3Ju_>_6XhgRc>6h(E&'7Vg:53VV8*\r")H$1[eR,[f0Ib`HYlY)dP0RIWUT0au\WBINXE[0J@2,6B%<r8(\45]IoE0bV\M#V4f>"O+f,bFP\Xk[_S(*u>7jC<l6hj2SK-Oog<FOAE&G8[uOB\LOuZ4l<ED[Wlhg$"%qXumNb1KY8OVQt^?DV4bi6k8STp"_/s`9IEuB,#cN1KJ2bOgS=M]C&94:o+s(\-:c>)a%MMbI['5d]Ae3_!oDERSTAZ&r8i;,maP+:CA.;Cl<
mDB5d^<'mJ$:4hc$`c^H_*hnK`8k?E1:PJ-T4R_X=RoEj=pZ$k(fmuKJEQm.Lf"('@si9L#N'-)MQ@Qa18Ff!+Rij!u*\_)3dI^j_&^XnEZ9RZJ[*:9f6/M]HWB_Fra9)A?;D^oBT)IC>U>%m_lO)t8ADMct>R`J5R^7TJ<m?PA2*^1T^oia3;&+E:EMrP\0R=Pu$XZ*=P\iTZD]V=Xtr?mSpS4<:0JbB/5kkcTWrP^q?[DoNJb<:^pP4A$`;])h/A**'*goNKe&P=,_XBUrkT>>R*pR1LFn],+^I+%-)CN.0/cZq(.`r2L[+"O&GQg\))ZhiA<pFE6AkY,,bIt+7NVMTQ)7-f+[1+f9#`\Y<s=mmi#T]>LqX4[=GI9cfSpf9S]Sb")9QR'!&g_q&fI#KMHZe^hl??Cj;+/m9X1[$dpn,#V``Q_2K7g/:7c&ei5IN<HIf@,I\p!K;E7uF\:F:tlPBD'0eQqa+kB(`l/-o]E^iLHAnrdB
6@dj/7[P;V!_bi;=3hs\7I\@,YI]QM6_Y59_WZeGCR>)U3MN^:r=0B9CCT;em\^\GD8Z+#>?p"hL\3mfjhW]3cBr^We@lS#?>-WN+^UE6H5]IT]ELO3WVV!X$#-WD;-n=hK<)&RpG,Ko-ureKD&.mhKfB52D2]BcP^CA!9.1c76;dX6*-&EgZiLU'(P2%7hj??jQe&@mR%QTLl^6f,"B@e8BqSc5-V5LC6neU!>$dDu!1mkr/3f8.!DZ?hlS4Cm.<ZWlG/,qPt/c_QP6cDW)"=KD/nqokrCX(I0:^+\j4*`k;QW/#@dG:GGe4e<[=btcdYUmACJ<9'89DhZ=kR3Cqq2;(H7h_,`4rba0Y1K.Yda?Q#,BP$Sekg_.mHsKRl#@84T-?$TK3[\\s9%iDi(#qgmM*,H?p%u81aJqI81i_6q7ED_\F$or;ku*"nk08BF+%kq2V+((KL2u3U_=(+U!rpP-`jg<lRCsC2NVqA2Z^m]dR,=@_\[G
hmSt^D)^YFoY`B0No5A!d*DcNo`e\(Xb%[9!>BlYJHf2/8I>flt4nu$5n37f`i`AVpu\rY7u3XB'uJB0rEBAU=;n+q\9B<Sjc;]`[P,ldBUr=81ca,@Ss;@Rt!^jRUQS`G3pZSbfC]=?%tL)9!%h5^D!8UZ/,Su0T[g.[Xb=k")V7m?i^hdhNK_O9td:E$6k!<:N4)U2#@0"tgHS7mh4UU^/hdD"MnlNb/;W^FF0PhC>"BsBE(F=@pmG7m*4K_$f+fAO%.A+`'j`(f[3h#&8)`*UtJ;n(S?/pHnA6$Ag&fjp<F(\.C<]iLCG)8OhDT*hIS1i4)!;nZW_Im)8op1m0oi9TU"-@47-,*5SjA7S],],XAPmeULD%4<J#SZSLZh""TLrso(s_<:$]2>dD`Y7ID-]OFR1)U4oN44W2mnh$I2Sfsk[G6RFI$#S4R@Ah+94g&b0@:7q>Y)IJ^56UFDdpf(nb"SckLK(+]i5rm;(L%?tVs6dOfXG
fOR-mZ1it-Od9:l!RUoBjCk@Q0PeRX"CMG)BQH5c,rTiufH)AW&GVe(*'G*L,6CeDg<;gh5fSu:E?G%]%EDkU-6nGa]W"e%S*&Y-PQpYHn9L#,J;\c9^>1YV34Sa7$()?t=sP"rV0eBdhtC22SN+mYmn_l]R)\!>qc`UBB^A+kAU7.Kr&7dh8KBSJ5oNI(TIeI?@sH\X:7h.A^]g9\"&U^_Q0qGWE=.7grCEIkO@^\j%/J&<WHhQ>dPIk#Rnoo+*tce9/EGYTp.K4TpQleItU_]lg/CdND!$$7=:b('3\*C,\\rj^O,>TfZlSE'7?6W)Z0QeRfqK@*KJ4`h!"d=+CeCADW#e3%)DfrB%@JNkNVbMH#s?<J+4OdM]KMeT=;;#dVHq<[Ibn`OCXRangTd2G/+-L[iPnM4dYJ%"@UNK5rH[Hjr_mIhIPb:i`M4jpOA?L;TrddOumHH+32D(q]1[ro#6frfId:p,/P^HZrj!P0;.<k,+.U[r
'HCZI>jjQa+qm[oRk<6m/oEnYEch2*;9#Fuk'4^oJ)\b2M<2s)W<j2*-<dKUr!!THW)?`HHV\Xo"EA%NYX;L3YCf$)E7f+P>0F*Oq[4.7NcZQ^I#BmY/5$&Iq$Du\g<JeMTo>^PQ#a1o'!n,0]7M53=Qs,VB+#P%(C769[+lmCfrS=u??4nDjKiM7XhZ@>C*#_aO9CM.+<Zu2/$`nC,tHoR<9PFOY`7!_"(nUWL&SHflk4"oW_!a"o`TmkDNPH)dVHLM[4fZm!iG;`A4h*+02^3dLaMI`OOH8+seRT2RENaVU5jTOHQgCj((R2!\>';sLLa*+kB/W"jD31EP);?#,AH]s4@^&L&T8tM"M8smhY[RsVfXG5#s01;$"Gc/l;rNG`ks!DtqDl@00HgOdYL@q[76/e7)8$4.<mlinU-=hR&FJ8YVFgC8?i4&Jqi-Y3Ed!99rba)bl*UW)iU[TL,Z]dttC[Em$j%a:/s2_)UVMWhaIYMadDXX
=eqF?O3]oX\;SJYR&bX7_tArE9B*T&UN/b$bEK3F0j3HX.ZdZ\uXnQZsIfCE2m<Nd]4@F$$eT?40BF:V\bc7]T'?LP@_faX2%46DUThP>X,)Ub7l-1U?sp8h'C4,Hp@^J"DHN9pOOc?poPdVk9sp%f`a0*k&BeNQmg7o[gP3J1Ya7;V[4Fr<7D%=<Ngi/#;D>Gfj/*,^n]O@I`)S@`s3I&HkTZGO'f&jdgreA(.f6n*`P>'=><\Ee/)4l61q2''lk)oq^*oi`>I/BJA54fEh"]ChPF0,"1+4hfJL>Crn=#oteDHX3)@rkEVAl&t^0GiN!9pueOSNddnn+F9#.'mdAA.+ZnMkGCRn*Ej7;+f0MB8p>V3\3SV]EUr3];jCQ["elm5?aaR(1uV<DVTYo<(V`r`+Qm7jQiFKLla-Q0FgLqFcDh\os'+jhHR2?t`RV?6'=_=Frs5K9DC#_@i]#%dNef:Lr>$_n?<R6u8*:m'ra]WEe5Mg,qOF
'&pr,/]i4AYG.;t/HNI,4c^@G:^;XpYglq(ih`:k1deCAnKZdHefn+)p9nn/IiYr*=8$`/kfHD0X3GU=;gL\o98m.AegnVhguI&dX)g,R:mg,#oB<:qZgT^]lrf;stq`GEZ&e5CRYmV[S3`-8gTqrOg+X1&>;N'Y->RHus%3MFn)VqTRrM)@b@eA("Tj^tW`rn[I4k""9PVBitOk7e?uKuFG=9l"Cj%=(T?^@NJH';IA'h=^ch\sfBNR5NnrB)VKf&q6/>S@;]UGVMWEG^ccQ\r#_>`nb8JLnP`dO3t8T]TEr9K9DpmTa@X,f6#[fqpoHR?LO?q/q3QH]-_g_Z@)g4fg"/kSW!^G4CO)"Dh?=kl73"<'3TX):Y38]g<b9OZ/TM),Y_tLJa8!)Ft:_*m8V%Nhu@a^3hI%h9?0]YQR=FGQ/'\%qMY7gd^4]A2J^u-1i&)>N\0l&%<mtP"T'p/GFB@#g!f3%:Z"aHq<+N<'Kpu9Z^hA8>gp
=9:]15P/'oj*`iSUBFP2SGe<f9rjl`gEWT-uKS5J&GX.l-1GVO#,g"AB0ZhiYZSlIT5^8AhdZ-5XkS$Pp4oK?PD89MjdOT2WcR-ArSWd]9^NTQe]H4p3_@/_bB'=q#j,Z!qNpCc<uci$WRF6o7lZrZ9r9Y5)\Z8bMpF?_o*1cDsgB544'5;r$HE;91gbP@u_S5d&^T5g:J^WT<uqe<UR*IE$;kjS.i`K-H]a7^QN=Fi?1Zt4Bc2j]?iS&(.6l/t^k@DUE)%(YffI.-qee`<_Jf#]Cgn]A-na4\qH9m5DoRC2886r05Sb\#YEH1*bhEc04$]Db^USm-!sLbUc^8Rg_6L2b@b&*BUhLlIqk6&Vibi66C6BQ6=K4^SKroJpVd^@g&=Y2uK:C97I+H0j&A^LWDhR\B3J:BnS-Y92Pg`L6*Rf+UP,aST=%rXd05LT=>:U[E6Ohu*_<5ATBnp9TI1g$R-Sn=&$[j)a_aG8_ZNqNZI.H>:sDEOQ
Hk]_bPRYg+b'T/c,K3qQm6^Rak$jN1?rig?A1n$2"$AGe4Q?Cu&cm#TNSZaiKE)W6:Ih4E3DcSrQOr(d%N&%4D^Y'ClOd#"a03AOt0:;d\3^%FB8BjaJB9j[Oc5'M?l(C-ItOOg,&`uP6/[)4*.1%H>VhfNV1GmEW)r_2[rnG?%IiO'X0D2M'E68NJ%qpjRtd/JFiG'RaK?qb+\8R,0j-RH[^H]pa,Pb6fHD4jD5+iXgP6cNcPM)D/+LXYX9IXY790,:.iDuN'VO3NlKm\_*om(qS^8aVj"oq+HI-^SJsY6`J&>ap!i?1=GbpENq3=<c7cZ@->BNh#d<0f1blP(tP4[Q:a5],@<<id54p]\#9OcA$PT]\rM:mp!JT[9+[.G.nJ-^&EHA4g;n#M?I\:CV(6LO&+Sqok$;sH7Nd=a*$APT/G:C.RXeJ_k-Pp0"u(#lQ-lB]MY9G9jO)8j%/hX4M4+%s%??d)Ohpc9r5nE-Kt*qjYf?PY'&
0m9J[Bf.N28Ni4p)F'3QcKm.1Y6s&CZT<R5iDXKgAh,j>/LY02ROHq_nH_oco(],l4c%5JgN*igGBAoqhZo:G'm,-7DkTmBg)j&s4pE3\fJU!]&Y6f7<8qI`cQR-E%fMKZ>c.S<-9DN6Ubg"1+U-6t%>SEEE2a7[dSq3XNMc#,t0PB#=$\Q=%-(m\b^FRb;hZi0*\L>6Z`HSteS2dlC9SN'k-r1\+=d?.;N!\'8tG8J3sN]e^j#LQoF1G.K)3`<\`[8YA+]U,=Kp10919GnVt^YX>-hHhg6LM!NLF$4ZnSV@GjN\nCuOJYPJI)eeo1rpuj\pXH"dUTVNFD8o9m/22d[BC4BfWCKDS,PK1F)3u7hO,te?QF[JeA&KmfUU7\hJokk?16pg(uCck[&pb7M0<AMmU)I<kb*CAA,Nmp;]Wtpe!W&Gpt5=>o^RuYVPm#U4mj\9\,+JuMN%NYg/ORmSd\B7)0Chg\[)[\9oIrBfEoi40oD<O0j?
iI7r`\)Uo9Ie3X*j<\!((<??6.Nr6<^\pcW^8aElP7iqYYqI'g'N83-kHbEcbQ-?)G=?ZWg2R`eLb\DK>]c$JF6?_Gith%3,0g$Y^TSb'iuig*'Kh/%q;R$(mFC,k@?S,>QoiB#-AI7Uua$'$lehSfZ%'2u:s7bEpAqsJ8b<^r+uflUir4I^s[gR5n9.aI4@YR7ug+C:bMEb5WBG=oC4&-!e(V:>Jos+&,aoVnf#X?7J8ga6ikj'(IN`gm00^UnJ-3@On]9R5J2[3=pRs(/B*DTp>>@oJ/meY_?1Grk8>c9=+l5KW2k=i'?3s5!T#8!t4Am@eYBB9$+NmP(%RbYR3tbk17n%+`*B`POUlqqfN@f9TUB9r@2(UfN7WbUa_0DDoH3:J]+"O##bq,H$aAF&M=V>taUlPj\58)g[$pqjRNI^:M*q'(oTQG%Y3T#d23C3TO-tpY;%-Pm";.0%.1W[(6'_2IcHfDXdPG*q]c?R&(_RrI_:%W?E
@2o#Z9+(_bDn0+45?[aM0<DYU0ibh"+I(Tp!h:1CB9Vg0/=ZX*n95@(Wq&tuGSc#DZUAFXtWqTf,p//k9GLg-P9]WeNU1r1K,f$$gGVo]?eOuc;j%6Q]@\A5dFP+k$$@INEp6,.3/K^*m[%4$ek5?Gqfk9EcSn2l:$rqVcWA!J:oC5^aD86/>-9_$YBDrdZt14/B]'[G+h>;V.G0MRNcYq`D/V9[%KIFUF:5C>%\rCu[#6%&qm]q7j,]s[(9amO)t$&0c)g2Wluo6O]5KmnA+Ns_)m(_V:?h=c"Ic$1>s8FFDnk'ThVTBtuXnW=MFZK(->U,L9+]e0K*SrU0IAL`%G-04]3<m5EfU!rZJ]_O2V4C[UJA45GrJNIMnDAAXn]+SmC)/&0Xk9Ci^W6,FtE^d1mc;^C/3O;qA1G-h>?d;`kr%N-^Lq-mT92?V!+*nJ.f5r,cq)eUjGgl1<)0G4k#euQt*]3+#X@Kj;[ZlN9Ou3'jfoNT?o;q
.^n+I2mCYKqUS:cZD;nFk:kBZW*aQ`FX>S`hjg[gW4jNNrt*diH5T%eUtH]/%uakM67ro%[SIUbH$3AIVMmIEb3apP^nBZDXK0HtR/$=?F#+0W(74o*?G@0<0e`m$i:581jS$./':\_[(TBsIFJ3</\@Cn'kc.SotkF1/0-.%R7$[j_L@@`"bd0+?AtIDkN4%bIfV[VK#'C!4R`T'atb!GOh_\\,3mMsDTmBK9u@50qd_rESRjQK:)h?b]A,j=%RpnUmH5H((22cZ"=iI;1cSZ8^_.^pH11ik6@bKM7bd2[]J8>/<4o]s2J4loi+IgF;g^<nk5"F>HX[s$+'_-Q:^+g5.^IAnl@0hbJG1-.C[qJTB!uT&7ibFIDC76:on1c:!=DR-<<=Dn!@k5[Hh>%1m7C]0e'W?@i/]fUh>g8ZG'tQ`;Ko@P0Y>FOrfm5r\C6id*9Xfqi1SEi<#Ea7XNM[HqqjmKGQ+j^Fms2UC=jh+)hVc%uJtZ=u
t`_XPf^UnsPZI\6A#*+rngI@_s(B=RqRSl_'O[uF'tkd`hb=A-.7-=o-*8m>K*hV%^rcg63Qfm]h8^Ccc4QkD)JEq-k.r],()q>)55/)JDE!oj%'8OqZBl7Y0d*[JL.QDaSUD@G"^/'[2ed`lEYSM^&#.P557hfi.c2J]aICq3LC`8[m&'9odoofG&*H6i>sES2*E\lVZhj(J*2X1\4,m@='e=mc+IW%\/KgHX7a[C_EVlBe'4Qnp=sR>tho2qq4p_EF@dOT'"2(/'0P2R:E>7eA_CkDoQSffH^HHXhmqGqm(+o6l?>5's_^[OuBg1XX6i2`ZIDNFNd._tQ]oZWa%^acGnlB>3cn4oI-MK0IKUU\E]s_j'/]I@jY*`Z,B[8!Nj;N?buO<m=B8!?/.7m_#Cj_B:@QhP??l4]Uq<+0[8*j=mf=3q7a'?0hBWmiIq46QJ9a3:Z`cfp*IbVWkE;o?ZL+.d36]5KQ?BRerDAhH3!h5#JKV,'i
AKm(\l`RV^BH=SZj4r.]FAHf%/;rqW[WKj:ccp:=>F>;[19Jot^D9l">9T%\D[P227I0u"55n)9J.f`(>H$0=&USVWsN[qR,VTCLb&e?3;V)fH.jNQt)[$'<_&ah&bYo4(eTqg(R,"4WHKo-n5<q]>Psg\6)$0bQRZ43Zg'O7lft[\o2YIett\deAljlk-"r)SC?!:<Z6]6iY:+BO#)N,5$"\D!seg'L&!"'QLdLgF&Xbq50rQ,p-J:X0Xt+,aasBqiNYbi/cgP1Z.aFY=<\R#8c$.q%1Ysq&4[(;EUfE7_Eq/1JS^oEDnX1)t)hFPJeWqCdm$Ze;)*76K]\0nMQISDZAbo7Y]3RC$md.mO+u=_Z.4a&(%6QNVh3eiL*uo53BN;mO;55;=#Gn=L/1GUgNC,kJ-\8Y^,1bnOYlEIk#sEX]-RHUb?M5*^LU$`d/H'5OW<1InkLEh@i$"DX#-],r[PtoUe=Ik.E);mE$%3ZnYV/2CD=]7Zk
\T5d,@AROWX$3K^nE-tb)XPPP#"PEfe4Zh\fqqYZ5mQ6#DST03"/`,^@J/m;()+cM$MkFPaRlWNQ?\([<Y_<$hB`U38o7S06!>Ydi==G-.Xnss.X.;$$VmL,X!mhaUlW[A%`_Bt4[NE[@Tbj7gO[(GWS9&?goE64.%^QAHCnD-9TeMTuY.Ek`jaLS!uBCr+!cUS8Q0/Yi>DSG<a1unP?(ZnfB%]3tZG!ZD!MN;A:I8IU1>YC\l5CLl?5K.WKlc*lLi8&_+d/hid[:+AjA)d>THSggi=ZC&a&s_pt4a\XBG.'ToCic/8dZ-M,g?YDT-ks]EV,rTu@4;!k>ZIE"T!lSe&HMSRkkDJJKJMu`KCm(J14A-*$_JBaYLkl??eP@,^A.N<_GS&LGPY3iWtYDCrHGCsRlcY8[/V5]Su?r)]tWRVd=N'Um.R:QoHaT9`Pl2"S8X;UhS!Qob^#baha'<_5I2.h(kXbG<M#c29Ph7Xq,6GYI>FqFX"1
[,5j^?C]p%X5Lf!KFnKg$hl%<&]e>He@l0=Y4%;RRJ#hD&Ng\8QVl1RLZc?Iq<lrk:V\$ke?4)E.q.VsKcq]t<pUnIQE;-`H&nMKdsfnP-+07.p4NUXKfkKh\0;Y^nC;T.uI^2^2<(0Qt;`7JM$:=`c6,(UT3d%Vcr0557RWS[FMYF/%,W[;J&fq2rgVaG*7abqnAjVe!k>5Zr$3lphm.)!7@hn-XhG4aUqqn#gk<KSK'<]aE<p8/YCd\"@6^FN+X^W/sAnp#au><S\;fX::mVXC,UZ>7&O"('CTaUocr9eb/Z?$!RseI?#"/'^@MoccS(fBh0cd_kgr(4o(TRk36k")jsYpZtT?Un%n-s%p[OYCb..VN7XLbS[Kq`_!U,CeT5[WIM[ON'+%'pr=AQXuA`$W49+/:]6,'W>jsTS&]`9_Z)&nK/]u]l'7T6QYu8%>B)JQZ@4ueeNHHKoG?f`iEXkn'_F[[i[Crd&\=?ep$2eAAPkO2T)B
@\":@k:G'A.)oMQ*m1Q&]m&'Zb3AAq"0Nq>qblH,D\(jsZAYZ8SZib_2XS@.`]p0-k4BD!W=)Q<1&`Q>.)k*lr3bK<6']r9lQbBht_`LcSgfDamhi<o^l4R36G8lGq(BD+7i?ZF9\8u9hSKHY+'.U'-%o@$S:A:NQFgP.%5r:VF$ah!Y(*@UOV,CpT<Sh?9AeIj9=r;G!J>.Z<EhC\8PaQ2cIC=]h/1YH>fFZOrci'!`]n_0V,,9&]UA)mQ1Gng2/p)^BYSp9Ypn!2.)f-V9(4-Aftp0bQ.<V+C$qQ+/374b:;I2jRfB!`cLm[#rk<\bQ:R)dG98l+krTmRc\%r.+ho10D#69]03YDLC<j;-_NP'<+oYj(U6kq?0umJ$WDHJ">]j[P^`WP/=E\I6rSg:A7N3.YAk?)/D.:B'.UfXKEf>#HkVh=$OIpPkU?Lr,&lis.imb"U*-gDna3hoAG5:Nr]hp)2=+OF;<Lf(6,jjLu#F4+dCMI%O
&]<umLRDp/O&j8T];lV_o+B@M3,4Gr[p09Q,OCA)(%,D4XU6l5dQh@dIkq"5d#5obZ^]koCLRbo0&];_(7nh4bnlg0kTok@/lg?&U/\DD_e>Y6>MSibfh=p<`Nek]UYXa8.FY<5T?>BfCUl0d>bjD+@:rnb4WiOjm%#QeLIfB'FoeB.uoKu\CT3]@:P]_EqhFI(k;S`]0<l*HfjSnY=>(-5Be;1@o]LeI,Q$KX\&J&*f\lR/)TI$LBSQFT=7Y7,,L)X79)[9,JIhOV=`f*8c]nd2X@r(JPnT!AVs4mMc`R.cMRM'_/;,I>P6Q$P>Q[u7^FO7$BL(A1Nh`p#huI@>@AQQ$8k1>cSg3=pN!VjtdE\%$/r/R=8pGt68ARf;$l$?Ftj6WEKgQVEJ+M"0X4,/s9%V\tF3?'@qJ)a@PAQ>?27m.^Kn/CS8)I==pmB:^/663l+*RaLj7co'&;p?%."&?10$V9_9oEC)1BMsd%[FSWkkeA^3!1Q.
X)QdDgsqs.1B+ZOhDbr5e&Q,ETkq_WWLn<rHs*k=/M^Ng5th93_#5>*4@Du>)T?MaB^h;;ukEF[lD35t+Qn@(n&X0!UjajW^iApluu98,M;roO#W,I'0B,-'I6BqV7>m57/BCfL<3[W3tc=?R)h8N%Wl?.oUU&\jdU798deJi`/5B"a=#4;Tno*94,?o03Y$%biMqlu-EJ/sLV"MD`@(\;om8b].jYe%V<Nahr6G*R'k>\,<)Fe@s&%pPXSY#P5:#4^*\Ve7$Irq+6l;bh"3hH<-a]+s>E%r92a&R!j'&<9.M4'0[d69l9n1pL6<&YF=?T/A-b<4=*$Q`K4XFN;,h"YIe(pOg6G-`_M1#;Z74+UW_iXAF9)99&+G2'CI]N)h%026SI1N%[EWf,jsV)N\j14rht9sm,*3CUmJ(G3P&S0hoQ$_?P/8[VVN-C\Lilaj8-r2QVg]7_%iZIX6M4dXRiaT`6Xr7T@Y%VS3K.a2qo.mqtRmXoE:
10psi?R@T$OmBD8^eNdfCQWqG$5hLDs4Us*X>:.fM"Z9;j)K'a"ojuY4,LNr8cO4Q`2a6lI`4SEmS0<6^5Zat"7n:-5\#-ro2b>"=j48f&I\kVmpO0"WBp:L,f34;KAQ6O6?mrqt0Ve%gQaKO@gmJZk884W?YOEYGmhTm-*HQpt306CEWlq$-iFiKD@%aW&#D&MTE'+S_'.N4-Rc+O6WSQR="4G[EKXkBWOq.97<H?t#"*"hBP!`$sa-O3BOBi8[f^-+U?puU1t05N^@)*WEI2-q/!<m%TB0ugQ)=>HUpE=pOF0C-fm+147P4-%9<CJ&2rG,28sfnpY>hN\DAPJ)WDq'8ScO''-ZIqGXU(QCcQbR9ndkn,"e8:)a\D>P25O1sA.E51'R#b-+)0rd<4c"h+F4`u,)5M"[Rb0P74/q-hUbrF5fI;HZ&Si\FR@'=4B6#gPdmuP+OS%f>:hu?b;_&>[EDcXF>EL;Bc]ro2KcX.a$0@E&3`"B
,.M/'F_n4QiagRYTZB;nfF*)p%nV#L$1H#4$7D>Lau>OGVNC8>#TNYb^1%)$)q[/GY3O@GnsHK-Dplg6Ks+'b1:REI\]7Xk6YkletLlIbdq]g7%dTZ)0%^CcS"ZL6&fT"!;SpJm.50@W-]8GW-Mq2p'<T7VC8%I,cOPHXm,LU6aReDuJ+o^:\nm(Z-[fTEF@.HCH_,42Pi2BUW\h91nMnbiOQ/+&lG'Vk!G?\^Af(M)?Z\/b$^j-m`cqN>+C`Chii97c?=73C`hgEV/"1frqtUTs['<"]*mH[0sP7Q"%"V>&'J%opB\r?N'UGEiqd.?#+6N>WY@)s^QJ[I6sgGE+*OomV6BHb\/Q099_dSh]PZ'?HRsXn>ZFWSSB$j6<@\7HeRfTT?BoP81h3p<k1j=Y9`gF?k97VHNiSG2HeE>M8H?Kk+6'N$!9dnl>TkaZ?C=aS/RbKbZQ@o3/Il*UhW2lXTD5f&Y_,ZVYjYrJ&(mp<K#]&<A:*9?l
jPM*-ahr4I[/I6VG-a0K<!02ql$bZcoak\HN.mJQuqjZ)/VXRi(OVYKkFc>"lmfn7i&Fjj'!k:O0LZX3?dj80rrF&'p9G3j\Ja1??'h/0#,(o`fc7i_E(<%ZYGjGGZNA`D&!N:9<$dTI'8P!r(t1;,:Y=(NQK;+82`f@-7Xr<<0@Pr#s.)`Pf+'^a@on%M&ED"dSj_lm^IcU/L1IeRl*(]!&RZPhXhG%@@Ni@,c:rk?u0=W"m#BD;#p6hLka\Tou35qQ_^SR9ioCODT(lrU0/0/YJ]=EIJ.)n^6@pHA-dHYk(Dh`h<f^AS/eYuUCu&(;``]PGC4LMJfQj1P6]7^^?`B"pICIHN7`ZW6e4aX"Kq7-=Mu%QW*k9(^`pCIR"F5G'Ku-L8R>ST=8#SZSG`,j`BqS;1l-c>];&<6sq%EUP?IG@O=IWMLXl"BQ,KA&PM*8c=Y?Nm$TUgT-\Oc+)?DY2,h><qEH(0>D7"G$aGrn;^1EB"/Papk.
9-UZLnl[X*M+g$BB08U=60$ed[H02.kaeGAR[c3G,/It_q7>a%btb*)JkjbF0qp/<J\BO5TbK7/ZJms`87[YL`h/Ib&r\shuUQMZ#RoS_okO0@bnEb-)XVtVO(LSE,H7XfQjNm0P/B6fos&PG!9>@A-#MAWLPLa5@_gu=qe2pkVFIG@$[@BLaLeAVZ]S=/'4_c<mSnVqMn(VcEf*a#t8/,PdA;3P-pXcibRN(4XoRLU=0,gVb5R6Sg-K0KUnS'*eo*Dnc9X2.6np0;qJk6:7Er/#\R.U'qiflZ_Ah1aO"9mXa3'.M8+@Dti_AQaGDEO!H=%%!9H_L)t5Z-II:cGj\K1["X7ZaIeR8_m!S)i(nJ_b=UP+o619B=G3Nifg]>`,[#"51+uf0-=.6r*4l?idiqMl(]rGmUdtdHhSu0l^lMU*t3MXl+!n;er(Y@LF;-6rgu\CmJ^kj>!4htC3\m.W2\ee:Zb>b\4V[f@&TE?VuH\.;u(K3hV%
AfjnR[CdmPc[e%$)Pm9K'IVG(?ek@KraCenI=[G&eb0(4-AGPf&c=mot!rE^-J+87B=r@FA93:>@,lFuGRT<GA##pYK"UmgCjX[K'*RZ!(>=fcTBY.1N6,$u24Sa-e+?6o!b`MU\il\88QMpq.Uo(.@QkJh8TQnEdS]O'riA'Kq0fhFIt,+g/aeIUfgiV'6[80eCZG8P6.U=+d+-#qc<4'5B=qd5LN<u*a-p+bC!TfW2N8I-EeG>%D+[t[o_lE#%#H"JD!E8C6>=mXJiIqF!"2eUIO:qSWSPVr.\EE(Os/WV$U'l#b8(XM6)iK&.XE1F(nqka$_e9M7gkOT#7&idf2/<LSFlPK%C6>4KPRJZG(Sc#r^^C=G?R_ISeB4Q,glLt#[e)>3E](2-SfOq^d^pVY0X4\NY5q0aUamLl7>^N5HrAALcm2PjKZDJ83Y0>6UZnRAQK4h$g4SEJc8E64$lU<I<CId39F!p.f8'Q/bCCY%7]i2(%Um\
D)n:&#s(jM#JqDA'Z^5r3?m/5V!g!`ldNSGVS?eOf(cgR01>4HJ(QB'*MfB8qo2JOdGWW+X9.G3CefI(@`<Q7#kD5Xnta%jNTg,63+?Fs\D#-JI6O1Ze/qW)o12E`j'W4IUfKCj@k=2/RaaR?Z<gk.D)I-A)@4QOdQr,T`EkVjk?pkoOF*Af'k.tT5+luW,9\u:b^H]G]ObYLe0ZWcDXLQsoL,H:LTXhf;?GMr5Z:UXcKr!d5`V>Hacn!n76$Vl;&)b`KZDDrU3*8#@)s&A=+Uk_K&<4fp?]=q;apj4^k6hg3#ahq5aqD\#k481lPs!mJWJ6:\X#-kN-+.AB-T$<1\4!W!LH->%3^7:!Hp,GWB;8c>F)*7<A.O4B5eDlIQIfU;3A/a;C>S*&bpqr<RnCpX`VD"j&9)eE$1LjTr?V-ZL3CDW3bLW4_<=3n2fNHAMDoQd$XD[K%-[[uJnRc9ZrTL^h]["`nm?O.7ksB%i:2ZW[l$pR;TL8
uCj-MB8PJ%?14ZG3g4[$p_4j;K\]D+E8k92eE>fV`6hFiCu\C0;af\D9KQ._N6Bpl3Kqsql/abntk2C:1jDV?aLCnSJ:\kWo>gfq`C]ptN]lu)i12f+9\;U0N2WHb;r.^%B#MYDHI53IO=VoQIem0Rt!+gY4*p\9@IpY06=N1>((iY:"Hn'(F<J(Y1`pZ:]f^%[1h,RL"7Zf5oMLEDe(XR[ZqYBI>'_EloaIQ,a&N.2)?Hu+2'
)***";
            /**/
            using t = std::invoke_result_t<decltype(&HuffmanCoding<std::vector<std::uint16_t>>), std::vector<std::uint16_t>>;
            using std::nullopt;
            t tree{ { 14, 0, 0 },       { 8, 0, 0 },        { 4, 0, 0 },        { 6, 0, 0 },        { 1, 0, 0 },       { 7, 0, 0 },       { 0, 0, 0 },         { 13, 0, 0 },        { 11, 0, 0 },        { 5, 0, 0 },        { 2, 0, 0 },         { 15, 0, 0 },        { 10, 0, 0 },       { 9, 0, 0 },         { 3, 0, 0 },        { 12, 0, 0 },
                    { nullopt, 15, 1 }, { nullopt, 0, 12 }, { nullopt, 11, 2 }, { nullopt, 7, 13 }, { nullopt, 8, 3 }, { nullopt, 5, 9 }, { nullopt, 16, 14 }, { nullopt, 17, 18 }, { nullopt, 10, 19 }, { nullopt, 20, 4 }, { nullopt, 21, 22 }, { nullopt, 23, 24 }, { nullopt, 6, 25 }, { nullopt, 26, 27 }, { nullopt, 28, 29 } };
            auto s = Base85Decode(data);
            auto v = HuffmanDecode<std::vector<std::uint16_t>>(s, tree);
            std::array<std::uint16_t, 16384> res;
            for (size_t i = 0; i != v.size(); i += 4) res[i / 4] = v[i] + (v[i + 1] << 4) + (v[i + 2] << 8) + (v[i + 3] << 12);
            return res;
        }();
        mint cur = mint::raw(2).pow(d);
        if (cur.val() > 1) {
            int i = s;
            while (--i) {
                if (cur.val() == x - 1) break;
                cur *= cur;
            }
            if (cur.val() != x - 1) return false;
        }
        const std::uint16_t base = bases[(static_cast<std::uint32_t>(x) * 0xad625b89) >> 18];
        cur = mint::raw(base).pow(d);
        if (cur.val() > 1) {
            int i = s;
            while (--i) {
                if (cur.val() == x - 1) break;
                cur *= cur;
            }
            if (cur.val() != x - 1) return false;
        }
        if (x > (1ull << 49)) return true;
        const static std::uint8_t bases2[] = { 15, 135, 13, 60, 15, 117, 65, 29 };
        cur = mint::raw(bases2[base >> 13]).pow(d);
        if (cur.val() <= 1) return true;
        int i = s;
        while (--i) {
            if (cur.val() == x - 1) return true;
            cur *= cur;
        }
        return cur.val() == x - 1;
    }
}
uint64_t FindFactor(uint64_t x) {
    if (x % 2 == 0) return 2;
    using mint = DynamicModint64<-1>;
    mint::set_mod(x);
    static xorshift64 engine;
    constexpr size_t repeat = 8192;
retry:
    mint r = mint::raw(randi64(engine, 1, x)), a, b = mint::raw(randi64(engine, 1, x));
    size_t k = repeat;
    while (true) {
        for (size_t i = k + 1; --i;) b = b * b + r;
        a = b;
        for (size_t i = 0; i < k; i += repeat) {
            mint mul = mint::raw(1), prev = b;
            for (size_t j = repeat + 1; --j;) mul *= a - (b = b * b + r);
            uint64_t g = BinaryGCD(mul.val(), x);
            if (g == x) {
                mul = mint::raw(1);
                do {
                    mul *= a - (prev = prev * prev + r);
                    g = BinaryGCD(mul.val(), x);
                } while (g == 1);
                if (g == x) goto retry;
            }
            if (g != 1) return g;
        }
        k *= 2;
    }
}
template<bool sort = true, bool trial_division = true, bool hashing = false> std::vector<uint64_t> EnumrateFactors(uint64_t x) {
    std::vector<uint64_t> res;
    if (x == 0) return res;
    if constexpr (trial_division) {
#define DIV(d)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     \
    while (x % d == 0) x /= d, res.push_back(d);
        { DIV(2) DIV(3) DIV(5) DIV(7) DIV(11) DIV(13) DIV(17) DIV(19) DIV(23) DIV(29) DIV(31) DIV(37) DIV(41) DIV(43) }
#undef DIV
    }
    if (x == 1) return res;
    uint64_t tmp1[64];
    uint64_t tmp2[64];
    uint64_t *begin1 = tmp1, *begin2 = tmp2, *end1 = tmp1, *end2 = tmp2;
    *(end1++) = x;
    while (begin1 != end1) {
        for (uint64_t* i = begin1; i != end1; ++i) {
            uint64_t n = *i;
            if (isPrime64<false, hashing>(n)) res.push_back(n);
            else {
                uint64_t g = FindFactor(n);
                *(end2++) = g;
                *(end2++) = n / g;
            }
        }
        uint64_t* tmp = begin1;
        begin1 = begin2;
        end1 = end2;
        begin2 = tmp;
        end2 = tmp;
    }
    if constexpr (sort) std::sort(res.begin(), res.end());
    return res;
}
template<class Modint> class InvTable : SwitchModint<Modint> {
    using mint = Modint;
    std::vector<mint> table;
public:
    using SwitchModint<Modint>::SwitchModint;
    constexpr void init(size_t mx) {
        table.resize(mx);
        table[1] = mint::raw(1);
        if (mx == 1) return;
        auto mod = mint::mod();
        for (size_t i = 2; i != mx; ++i) table[i] = -table[mod % i] * mint::raw(mod / i);
    }
    constexpr mint operator()(size_t n) const noexcept { return table[n]; }
};
template<class Modint> class COMTable_primemod : SwitchModint<Modint> {
    using mint = Modint;
    std::vector<mint> fac, finv;
public:
    using SwitchModint<Modint>::SwitchModint;
    constexpr void init(size_t mx) {
        fac.resize(mx);
        finv.resize(mx);
        fac[0] = finv[0] = mint::raw(1);
        if (mx > 1) fac[1] = finv[1] = mint::raw(1);
        if (mx > 2) {
            for (size_t i = 2; i != mx; ++i) fac[i] = fac[i - 1] * mint::raw(i);
            finv.back() = fac.back().inv();
            for (size_t i = mx - 1; i != 2; --i) finv[i - 1] = finv[i] * mint::raw(i);
        }
    }
    constexpr mint operator()(size_t n, size_t k) const noexcept {
        if (n < k) return 0;
        else return fac[n] * finv[k] * finv[n - k];
    }
};
#if __GNUC__ >= 12
constexpr
#endif
  std::vector<uint32_t>
  generate_primes(uint32_t size) {
    if (size <= 1000) {
        constexpr uint32_t primes[] = { 2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
                                        439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
        return std::vector<uint32_t>(std::begin(primes), std::upper_bound(std::begin(primes), std::end(primes), size));
    }
    const uint32_t flag_size = size / 30 + (size % 30 != 0);
    constexpr uint32_t table1[] = { 0,  1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 19, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 23, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 19, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1,
                                    29, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 19, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 23, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 19, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1, 17, 1, 7, 1, 11, 1, 7, 1, 13, 1, 7, 1, 11, 1, 7, 1 };
    constexpr uint8_t table2[] = { 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 4, 0, 8, 0, 0, 0, 16, 0, 32, 0, 0, 0, 64, 0, 0, 0, 0, 0, 128 };
    std::vector<uint8_t> flag(flag_size, 0xffu);
    flag[0] = 0b11111110u;
    std::vector<uint32_t> primes{ 2, 3, 5 };
#if __GNUC__ >= 12
    double primes_size = std::is_constant_evaluated() ? size / 8 : size / std::log(size);
#else
    double primes_size = size / std::log(size);
#endif
    primes.reserve(static_cast<size_t>(1.1 * primes_size));
    std::vector<uint32_t> sieved(static_cast<size_t>(primes_size));
    uint32_t *first = sieved.data(), *last;
    uint32_t k, l, x, y;
    uint8_t temp;
    for (k = 0; k * k < flag_size; ++k) {
        while (flag[k] != 0) {
            x = 30ull * k + table1[flag[k]];
            uint32_t limit = size / x;
            primes.push_back(x);
            last = first;
            bool smaller = true;
            for (l = k; smaller; ++l) {
                for (temp = flag[l]; temp != 0; temp &= (temp - 1)) {
                    y = 30u * l + table1[temp];
                    if (y > limit) {
                        smaller = false;
                        break;
                    }
                    *(last++) = x * y;
                }
            }
            flag[k] &= (flag[k] - 1);
            for (uint32_t* i = first; i < last; ++i) flag[*i / 30] ^= table2[*i % 30];
        }
    }
    for (; k < flag_size; k++) {
        while (flag[k] != 0) {
            x = 30 * k + table1[flag[k]];
            if (x > size) return primes;
            primes.push_back(x);
            flag[k] &= (flag[k] - 1);
        }
    }
    return primes;
}
#endif

#if defined(INCLUDE_LIS) || defined(INCLUDE_ALL)
template<std::ranges::range T, class Comp = std::less<std::ranges::range_value_t<T>>> constexpr auto LongestIncreasingSubsequence(const T& R, const Comp& c = Comp()) {
    using U = std::ranges::range_value_t<T>;
    std::vector<U> dp(std::ranges::size(R));
    std::vector<size_t> idx(dp.size());
    size_t* i = idx.data();
    U *begin = dp.data(), *last = dp.data();
    for (const U& x : R) {
        U* loc = std::lower_bound(begin, last, x, c);
        *(i++) = loc - begin;
        last += (loc == last);
        *loc = x;
    }
    size_t cnt = last - begin - 1;
    std::vector<size_t> res(last - begin);
    for (size_t i = dp.size(); i != 0;)
        if (idx[--i] == cnt) res[cnt--] = i;
    return res;
}
template<std::ranges::range T, class Comp = std::less<std::ranges::range_value_t<T>>> constexpr std::vector<size_t> LongestIncreasingSubsequenceLength(const T& R, const Comp& c = Comp()) {
    using U = std::ranges::range_value_t<T>;
    std::vector<U> dp(std::ranges::size(R));
    U *begin = dp.data(), *last = dp.data();
    std::vector<size_t> res(dp.size());
    for (size_t i = 0; const U& x : R) {
        U* loc = std::lower_bound(begin, last, x, c);
        last += (loc == last);
        *loc = x;
        res[i++] = last - begin;
    }
    return res;
}
#endif

#if defined(INCLUDE_HASH)
template<class T> struct Hash : std::hash<T> {
    uint64_t operator()(const T& x) const noexcept { return splitmax(static_cast<uint64_t>(std::hash<T>()(x))); }
};
template<class T> struct HashInteger {
    constexpr uint64_t operator()(T x) const noexcept { return splitmax(static_cast<uint64_t>(x)); }
};
template<class T> struct HashRange {
    constexpr uint64_t operator()(const T& x) const noexcept {
        uint64_t res = 14695981039346656037ull;
        for (const auto& e : x) res = (res * 1099511628211ull) ^ Hash<std::remove_const_t<std::remove_reference_t<decltype(e)>>>()(e);
        return splitmax(res);
    }
};
template<> struct Hash<bool> {
    constexpr uint64_t operator()(bool x) const noexcept { return static_cast<uint64_t>(x); }
};
template<> struct Hash<char> : HashInteger<char> {};
template<> struct Hash<unsigned char> : HashInteger<unsigned char> {};
#if ___GNUC__ >= 12
template<> struct Hash<char8_t> : HashInteger<char8_t> {};
#endif
template<> struct Hash<char16_t> : HashInteger<char16_t> {};
template<> struct Hash<char32_t> : HashInteger<char32_t> {};
template<> struct Hash<wchar_t> : HashInteger<wchar_t> {};
template<> struct Hash<short> : HashInteger<short> {};
template<> struct Hash<unsigned short> : HashInteger<unsigned short> {};
template<> struct Hash<int> : HashInteger<int> {};
template<> struct Hash<unsigned int> : HashInteger<unsigned int> {};
template<> struct Hash<long> : HashInteger<long> {};
template<> struct Hash<unsigned long> : HashInteger<unsigned long> {};
template<> struct Hash<long long> : HashInteger<long long> {};
template<> struct Hash<unsigned long long> : HashInteger<unsigned long long> {};
#if __cplusplus
template<> struct Hash<float> {
    constexpr uint64_t operator()(float x) const noexcept { return splitmax(static_cast<uint64_t>(std::bit_cast<uint32_t>(x))); }
};
template<> struct Hash<double> {
    constexpr uint64_t operator()(double x) const noexcept { return splitmax(std::bit_cast<uint64_t>(x)); }
};
#endif
template<class T, class U> struct Hash<std::pair<T, U>> {
    constexpr uint64_t operator()(const std::pair<T, U>& x) const noexcept { return splitmax(((Hash<T>()(x.first) ^ 12638153115695167455ull) * 1099511628211ull) ^ Hash<U>()(x.second)); }
};
template<class... Args> struct Hash<std::tuple<Args...>> {
    constexpr uint64_t operator()(const std::tuple<Args...>& x) { return splitmax(calc_hash_impl<sizeof...(Args)>()(x)); }

private:
    template<size_t idx, size_t Dummy_idx = 0> struct calc_hash_impl {
        uint64_t operator()(const std::tuple<Args...>& x) const noexcept { return (calc_hash_impl<idx - 1>()(x) * 1099511628211ull) ^ Hash<std::remove_const_t<std::remove_reference_t<decltype(std::get<idx - 1>(x))>>>()(std::get<idx - 1>(x)); }
    };
    template<size_t idx> struct calc_hash_impl<0, idx> {
        uint64_t operator()([[maybe_unused]] const std::tuple<Args...>& x) const noexcept { return 14695981039346656037ull; }
    };
};
template<class T, size_t N> struct Hash<T[N]> : HashRange<T[N]> {};
template<class T, size_t N> struct Hash<std::array<T, N>> : HashRange<std::array<T, N>> {};
template<class T> struct Hash<std::vector<T>> : HashRange<std::vector<T>> {};
template<class T> struct Hash<std::deque<T>> : HashRange<std::deque<T>> {};
template<class T> struct Hash<std::list<T>> : HashRange<std::list<T>> {};
template<class T> struct Hash<std::forward_list<T>> : HashRange<std::forward_list<T>> {};
template<class T> struct Hash<std::set<T>> : HashRange<std::set<T>> {};
template<class T> struct Hash<std::multiset<T>> : HashRange<std::multiset<T>> {};
template<class T> struct Hash<std::unordered_set<T>> : HashRange<std::unordered_set<T>> {};
template<class T, class U> struct Hash<std::map<T, U>> : HashRange<std::map<T, U>> {};
template<class T, class U> struct Hash<std::multimap<T, U>> : HashRange<std::multimap<T, U>> {};
template<class T, class U> struct Hash<std::unordered_map<T, U>> : HashRange<std::unordered_map<T, U>> {};
template<class T, class U, class V> struct Hash<std::priority_queue<T, U, V>> {
    uint64_t operator()(std::priority_queue<T, U, V> x) const noexcept {
        uint64_t res = 14695981039346656037ull;
        while (!x.empty()) res = (res * 1099511628211ull) ^ Hash<T>()(x.top()), x.pop();
        return splitmax(res);
    }
};
template<class T, class U> struct Hash<std::stack<T, U>> {
    uint64_t operator()(std::stack<T, U> x) const noexcept {
        uint64_t res = 14695981039346656037ull;
        while (!x.empty()) res = (res * 1099511628211ull) ^ Hash<T>()(x.top()), x.pop();
        return splitmax(res);
    }
};
template<class T, class U> struct Hash<std::queue<T, U>> {
    uint64_t operator()(std::queue<T, U> x) const noexcept {
        uint64_t res = 14695981039346656037ull;
        while (!x.empty()) res = (res * 1099511628211ull) ^ Hash<T>()(x.front()), x.pop();
        return splitmax(res);
    }
};
template<> struct Hash<std::nullptr_t> {
    constexpr uint64_t operator()(std::nullptr_t) const noexcept { return 0; }
};
template<class T> struct Hash<T*> {
    constexpr uint64_t operator()(const T* const x) const noexcept { return splitmax(splitmax((uint64_t) x)); }
};
#endif

#if defined(INCLUDE_STRING) || defined(INCLUDE_ALL)
constexpr std::string unionchar(char a, char b) {
    return { a, b };
}
constexpr bool is_palindrome(const std::string& S) {
    size_t n = S.length();
    for (size_t i = 0; i < (n >> 1); i++)
        if (S[i] != S[n - i - 1]) return false;
    return true;
}
constexpr std::vector<std::string> strsplit(const std::string& s, char c = ' ') {
    std::vector<std::string> res;
    const char* prev = s.data();
    bool f = false;
    for (const char* cur = s.data(); *cur != '\0'; ++cur) {
        if (*cur == c) {
            if (f) {
                res.emplace_back(prev, cur);
                f = false;
            }
        } else if (!f) {
            prev = cur;
            f = true;
        }
    }
    if (s.back() != c) {
        res.emplace_back(prev, s.data() + s.length());
    }
    return res;
}
constexpr bool in_char(const std::string& S, char c) {
    for (char d : S)
        if (c == d) return true;
    return false;
}
constexpr bool in_str(const std::string& S, const std::string& T) {
    if (T.length() > S.length()) return false;
    for (size_t i = 0, n = S.length() - T.length(); i != n; ++i) {
        bool f = true;
        for (size_t j = 0, m = T.length(); j != m; ++j)
            if (S[i + j] != T[j]) {
                f = false;
                break;
            }
        if (f) return true;
    }
    return false;
}
constexpr std::string fill_str(const std::string& S, size_t N, char c = '0', bool dir = true) {
    if (S.length() >= N) return S;
    if (dir) return std::string(N - S.length(), c) + S;
    else return S + std::string(N - S.length(), c);
}
constexpr size_t hamming_distance(const std::string& S, const std::string& T) {
    if (S.length() != T.length()) throw std::runtime_error("hamming_distance / S.length() and T.length() must be the same.");
    size_t res = 0;
    for (size_t i = 0, n = S.length(); i != n; ++i)
        if (S[i] != T[i]) ++res;
    return res;
}
template<class T = int> constexpr T str_to_int(const std::string& s, int base = 10) {
    static_assert(std::is_integral_v<T>, "str_to_int / Result type must be integral.");
    T res{};
    std::from_chars(s.c_str(), s.c_str() + s.length(), res, base);
    return res;
}
template<class T> constexpr std::string int_to_str(T val, int base = 10) {
    static_assert(std::is_integral_v<T>, "int_to_str / Result type must be integral.");
    char buf[sizeof(T) * 8];
    char* last = std::to_chars(buf, buf + sizeof(T) * 8, val, base).ptr;
    return std::string(buf, last);
}
constexpr bool is_capitalized(const std::string& S) {
    if (S.length() == 0) return true;
    if (S[0] < 'A' || S[0] > 'Z') return false;
    for (size_t i = 1, n = S.length(); i < n; ++i) {
        if (S[i] < 'a' || S[i] > 'z') return false;
    }
    return true;
}
constexpr std::string strreplace(const std::string& S, const char before, const char after) {
    std::string res = S;
    for (char& c : res) {
        if (c == before) c = after;
    }
    return res;
}
#endif

#if defined(INCLUDE_GEOMETRY) || defined(INCLUDE_ALL)
double to_rad(double d) {
    return (d / 180.0) * 3.141592653589793;
}
double to_deg(double r) {
    return (r / 3.141592653589793) * 180.0;
}
double sind(double d) {
    return std::sin(to_rad(d));
}
double cosd(double d) {
    return std::cos(to_rad(d));
}
double tand(double d) {
    return std::tan(to_rad(d));
}
double asind(double x) {
    return to_deg(std::asin(x));
}
double acosd(double x) {
    return to_deg(std::acos(x));
}
double atand(double x) {
    return to_deg(std::atan(x));
}
double atan2d(double y, double x) {
    return to_deg(std::atan2(y, x));
}
long double to_rad(long double d) {
    return (d / 180.0) * 3.141592653589793;
}
long double to_deg(long double r) {
    return (r / 3.141592653589793) * 180.0;
}
long double sind(long double d) {
    return std::sin(to_rad(d));
}
long double cosd(long double d) {
    return std::cos(to_rad(d));
}
long double tand(long double d) {
    return std::tan(to_rad(d));
}
long double asind(long double x) {
    return to_deg(std::asin(x));
}
long double acosd(long double x) {
    return to_deg(std::acos(x));
}
long double atand(long double x) {
    return to_deg(std::atan(x));
}
long double atan2d(long double y, long double x) {
    return to_deg(std::atan2(y, x));
}
float hypot_fl(float x1, float y1, float x2, float y2) {
    return std::hypot(x1 - x2, y1 - y2);
}
double hypot_db(double x1, double y1, double x2, double y2) {
    return std::hypot(x1 - x2, y1 - y2);
}
long double hypot_ld(long double x1, long double y1, long double x2, long double y2) {
    return std::hypot(x1 - x2, y1 - y2);
}
template<class T> struct vector2D {
    T x, y;
    constexpr vector2D() : x(0), y(0) {}
    constexpr vector2D(const T& X, const T& Y) : x(X), y(Y) {}
    constexpr T length() { return static_cast<T>(sqrt(static_cast<double>(x * x + y * y))); }
    constexpr double slope() { return atan2(y, x); }
    constexpr vector2D<T>& rorate(double rad) { return *this = vector2D<T>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)); }
    constexpr vector2D<T>& rorate_deg(double deg) {
        double rad = (deg / 180) * 3.141592653589793;
        return *this = vector2D<T>(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    constexpr vector2D<T> operator~() {
        T&& len = length();
        return vector2D<T>(x / len, y / len);
    }
    constexpr vector2D<T>& operator=(const vector2D<T>& v) {
        x = v.x, y = v.y;
        return *this;
    }
    constexpr vector2D<T>& operator+=(const vector2D<T>& v) {
        x += v.x, y += v.y;
        return *this;
    }
    constexpr vector2D<T>& operator-=(const vector2D<T>& v) {
        x -= v.x, y -= v.y;
        return *this;
    }
    constexpr vector2D<T>& operator*=(const T& s) {
        x *= s, y *= s;
        return *this;
    }
    constexpr vector2D<T>& operator/=(const T& s) {
        x /= s, y /= s;
        return *this;
    }
    friend constexpr bool operator==(const vector2D& v1, const vector2D& v2) { return v1.x == v2.x && v1.y == v2.y; }
    friend constexpr bool operator!=(const vector2D& v1, const vector2D& v2) { return v1.x != v2.x || v1.y != v2.y; }
    friend constexpr bool operator<(const vector2D& v1, const vector2D& v2) {
        T &&len1 = v1.length(), len2 = v2.length();
        if (len1 == len2) return v1.slope() < v2.slope();
        else return len1 < len2;
    }
    friend constexpr bool operator>(const vector2D& v1, const vector2D& v2) {
        T &&len1 = v1.length(), len2 = v2.length();
        if (len1 == len2) return v1.slope() > v2.slope();
        else return len1 > len2;
    }
    friend constexpr bool operator<=(const vector2D& v1, const vector2D& v2) { return !(v1 > v2); }
    friend constexpr bool operator>=(const vector2D& v1, const vector2D& v2) { return !(v1 < v2); }
    friend constexpr vector2D<T> operator+(const vector2D<T>& v1, const vector2D<T>& v2) { return vector2D<T>(v1.x + v2.x, v1.y + v2.y); }
    friend constexpr vector2D<T> operator-(const vector2D<T>& v1, const vector2D<T>& v2) { return vector2D<T>(v1.x - v2.x, v1.y - v2.y); }
    friend constexpr vector2D<T> operator*(const vector2D<T>& v, const T& s) { return vector2D<T>(v.x * s, v.y * s); }
    friend constexpr vector2D<T> operator*(const T& s, const vector2D<T>& v) { return vector2D<T>(v.x * s, v.y * s); }
    friend constexpr vector2D<T> operator/(const vector2D<T>& v, const T& s) { return vector2D<int>(v.x / s, v.y / s); }
    friend constexpr T operator^(const vector2D<T>& v1, const vector2D<T>& v2) { return v1.x * v2.x + v1.y * v2.y; }
    friend constexpr T operator*(const vector2D<T>& v1, const vector2D<T>& v2) { return v1.x * v2.y - v1.y * v2.x; }
};
#endif

#if defined(INCLUDE_GCDLCM) || defined(INCLUDE_ALL)
template<class T> constexpr T gcd(const std::vector<T>& v) {
    if (v.empty()) return 1;
    T ans = v[0];
    for (size_t i = 1; i < v.size(); i++) ans = std::gcd(ans, v[i]);
    return ans;
}
template<class T> constexpr T lcm(const std::vector<T>& v) {
    if (v.empty()) return 1;
    T ans = v[0];
    for (size_t i = 1; i < v.size(); i++) ans = std::lcm(ans, v[i]);
    return ans;
}
template<class T> constexpr T extend_gcd(T a, T b, T& x, T& y) {
    T c = 1, d = 0;
    x = 0, y = 1;
    for (T div = a / b; div * b < a; div = a / b) {
        T e = a - b * div, f = c - x * div, g = d - y * div;
        a = b, b = e, c = x, d = y, x = f, y = g;
    }
    return b;
}
#endif

#if defined(INCLUDE_FLOORSUM) || defined(INCLUDE_ALL)
// calc ∑ floor((A × i + B) / M) (0 <= i < N)
template<class T> constexpr T FloorSum(T n, T m, T a, T b) {
    T res = 0;
    while (true) {
        if (m <= a) {
            res += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (m <= b) {
            res += n * (b / m);
            b %= m;
        }
        T last = a * n + b;
        if (last < m) return res;
        n = last / m;
        b = last % m;
        std::swap(m, a);
    }
}
#endif

#if defined(INCLUDE_TIMER) || defined(INCLUDE_ALL)
class timer {
    std::chrono::system_clock::time_point start;

public:
    std::vector<decltype(start - start)> lapped;
    void reset() { start = std::chrono::system_clock::now(); }
    timer() { reset(); }
    auto get() { return std::chrono::system_clock::now() - start; }
    void lap() { lapped.push_back(get()); }
    void clear() { lapped.clear(); }
#if __GNUC__ >= 12
    void print() { std::cout << "##Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(get()) << std::endl; }
    void print_lap() {
        std::cout << "##lap: ";
        for (auto time : lapped) std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(time) << ' ';
        std::cout << std::endl;
    }
#endif
};
#endif

#if __cplusplus < 202001U || defined(ONLINE_JUDGE) || defined(LOCALJUDGE)
template<class... Args> class debug {
public:
    debug([[maybe_unused]] const Args&... x) {}
    debug(const debug&) = delete;
    debug(debug&&) = delete;
};
#else
namespace _debug {
template<class T> void debug_print(const T& x, std::source_location loc) {
    std::string_view type_name = std::source_location::current().function_name();
    type_name.remove_prefix(67);
    type_name.remove_suffix(1);
    std::cerr << "##debug: " << x << " [line: " << loc.line() << " | column: " << loc.column() << " | type: " << (type_name.length() > 40 ? "..." : type_name) << "]\n";
}
template<class Head> void debug_print2(const Head& x) {
    std::cerr << x;
}
template<class Head, class... Tail> void debug_print2(const Head& x, const Tail&... args) {
    std::cerr << x << " / ";
    debug_print2(args...);
}
}  // namespace _debug
template<class... Args> class debug {
public:
    debug(const Args&... x, std::source_location loc = std::source_location::current()) {
        std::flush(std::cout);
        if constexpr (sizeof...(Args) == 1) _debug::debug_print(x..., loc);
        else {
            std::cerr << "##debug: ";
            _debug::debug_print2(x...);
            std::cerr << " [line: " << loc.line() << " | column: " << loc.column() << "]\n";
        }
    }
    debug(const debug&) = delete;
    debug(debug&&) = delete;
};
template<class... Args> debug(const Args&...) -> debug<Args...>;
#endif

using namespace std;
using namespace atcoder;
#define LIBRARIES
#define GLOBAL
#include __FILE__
#undef GLOBAL
#undef LIBRARIES
struct Main : Global {
#if defined(HEURISTIC) && !defined(ONLINE_JUDGE)
    std::ifstream ifs;
    std::ofstream ofs;
    Main(const std::string& ip, const std::string& op) : ifs(ip), ofs(op, std::ios_base::trunc) {}
#else
    std::istream& ifs = std::cin;
    std::ostream& ofs = std::cout;
#endif
    void run();
};
#ifndef LOCALJUDGE
int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
#ifdef ONLINE_JUDGE
    static Main m;
    m.run();
#else
#ifdef HEURISTIC
    auto starttime = std::chrono::system_clock::now();
    static Main m("in.txt", "out.txt");
    m.run();
    std::cerr << "##Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - starttime) << '\n';
#else
    for (size_t i = 0; i != 100; ++i) {
        {
            std::unique_ptr<Main> m(new Main{});
            m->run();
        }
#ifdef INCLUDE_FASTIO
        fout.flush();
#endif
        std::cout << std::flush;
        std::cerr << "##testcase " << i << " finished." << std::endl;
    }
#endif
#endif
    return 0;
}
#endif

//----------------------------------------------------------
#else
// includes
#define INCLUDE_ALL
#define INCLUDE_FASTIO
#endif

//----------------------------------------------------------
#ifdef GLOBAL
struct Global {
    // gloval variables and functions
    u32 A[500000], B[500000];
    u64 C[500000];
    FastDSU<500000> uf;
    u32 e[500000];
};
#endif

//----------------------------------------------------------
#ifndef LIBRARIES
void Main::run() {
    // main routine
    u32 N, M;
    fin >> N >> M;
    for (u32 i = 0; i != M; ++i) {
        u32 c;
        fin >> A[i] >> B[i] >> c;
        C[i] = (u64) i << 32 | c;
    }
    SortUnsigned32(C, M);
    uf.init(N);
    u32 cnt = 0;
    u64 X = 0;
    for (u32 i = 0; i != M; ++i) {
        u32 n = C[i] >> 32;
        u32 c = C[i];
        if (!uf.merge_or_same(A[n], B[n])) {
            X += c;
            e[cnt++] = n;
        }
    }
    fout << X << '\n';
    for (u32 i = 0; i != cnt; ++i) {
        fout << e[i] << ' ';
    }
    fout << '\n';
}
#endif
