#line 2 "library/template/template.hpp"
#include <bits/stdc++.h>
#line 3 "library/template/macro.hpp"

#define overload3(_1, _2, _3, name, ...) name
#define all1(v) std::begin(v), std::end(v)
#define all2(v, a) std::begin(v), std::begin(v) + a
#define all3(v, a, b) std::begin(v) + a, std::begin(v) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define rall1(v) std::rbegin(v), std::rend(v)
#define rall2(v, a) std::rbegin(v), std::rbegin(v) + a
#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v) + b
#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)
#define elif else if
#define updiv(N, X) (((N) + (X) - 1) / (X))
#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1) / 2)
#define INT(...)     \
    int __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    scan(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    scan(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    scan(__VA_ARGS__)
#define DOU(...)        \
    double __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LD(...)     \
    ld __VA_ARGS__; \
    scan(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#line 3 "library/template/alias.hpp"

using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
constexpr int inf = 1 << 30;
constexpr ll INF = 1LL << 60;
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int mod = 998244353;
constexpr int MOD = 1e9 + 7;
#line 3 "library/template/func.hpp"

template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (auto it = std::begin(v); it != std::end(v);) {
        os << *it << ((++it) != std::end(v) ? " " : "");
    }
    return os;
}
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) {
        is >> in;
    }
    return is;
}
inline void scan() {}
template <class Head, class... Tail>
inline void scan(Head &head, Tail &...tail) {
    std::cin >> head;
    scan(tail...);
}
template <class T>
inline void print(const T &t) { std::cout << t << '\n'; }
template <class Head, class... Tail>
inline void print(const Head &head, const Tail &...tail) {
    std::cout << head << ' ';
    print(tail...);
}
template <class... T>
inline void fin(const T &...a) {
    print(a...);
    exit(0);
}
#line 3 "library/template/util.hpp"

struct IOSetup {
    IOSetup() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
        std::cout.tie(0);
        std::cout << std::fixed << std::setprecision(12);
        std::cerr << std::fixed << std::setprecision(12);
    }
} IOSetup;
#line 3 "library/template/debug.hpp"

#ifdef LOCAL
#include <dump.hpp>
#else
#define debug(...)
#endif
#line 8 "library/template/template.hpp"
using namespace std;
#line 3 "library/data-structure/segment-tree.hpp"

template <class Monoid>
struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    int N;
    Func F;
    Monoid IDENTITY;
    int SIZE_R;
    vector<Monoid> dat;

    /* initialization */
    SegTree() {}
    SegTree(int n, const Func f, const Monoid& identity)
        : N(n), F(f), IDENTITY(identity) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, IDENTITY);
    }
    void init(int n, const Func f, const Monoid& identity) {
        N = n;
        F = f;
        IDENTITY = identity;
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, IDENTITY);
    }

    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    void update(int a, const Monoid& v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* get [a, b), a and b are 0-indexed, O(log N) */
    Monoid get(int a, int b) {
        Monoid vleft = IDENTITY, vright = IDENTITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right;
             left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    Monoid all_get() { return dat[1]; }
    Monoid operator[](int a) { return dat[a + SIZE_R]; }

    int max_right(const function<bool(Monoid)> f, int l = 0) {
        if (l == N) return N;
        l += SIZE_R;
        Monoid sum = IDENTITY;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(F(sum, dat[l]))) {
                while (l < SIZE_R) {
                    l = l * 2;
                    if (f(F(sum, dat[l]))) {
                        sum = F(sum, dat[l]);
                        ++l;
                    }
                }
                return l - SIZE_R;
            }
            sum = F(sum, dat[l]);
            ++l;
        } while ((l & -l) != l);
        return N;
    }

    int min_left(const function<bool(Monoid)> f, int r = -1) {
        if (r == 0) return 0;
        if (r == -1) r = N;
        r += SIZE_R;
        Monoid sum = IDENTITY;
        do {
            --r;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(F(dat[r], sum))) {
                while (r < SIZE_R) {
                    r = r * 2 + 1;
                    if (f(F(dat[r], sum))) {
                        sum = F(dat[r], sum);
                        --r;
                    }
                }
                return r + 1 - SIZE_R;
            }
            sum = F(dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }

    friend ostream& operator<<(ostream& os, SegTree seg) {
        os << "[ ";
        for (int i = 0; i < seg.N; i++) {
            os << seg.get(i, i + 1) << " ";
        }
        os << ']';
        return os;
    }
};
#line 3 "library/others/compress.hpp"

template <typename T>
struct Compress {
    vector<T> xs;

    Compress() {}

    explicit Compress(const vector<T>& vs) { add(vs); }

    explicit Compress(const initializer_list<vector<T>>& vs) { add(vs); }

    void add(const vector<T>& vs) { xs.insert(xs.end(), vs.begin(), vs.end()); }

    void add(const T& x) { xs.push_back(x); }

    void build() {
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
    }

    vector<int> get(const vector<T>& vs) const {
        vector<int> ret;
        transform(all(vs), back_inserter(ret), [&](const T& x) {
            return lower_bound(all(xs), x) - xs.begin();
        });
        return ret;
    }

    int get(const T& x) const { return lower_bound(all(xs), x) - xs.begin(); }

    const T& operator[](int k) const { return xs[k]; }
};
#line 4 "A.cpp"

int main() {
    INT(N);
    vector<int> A(N);
    {
        vector<pii> B(N);
        scan(B);
        sort(all(B), [](const pii& a, const pii& b) {
            return a.second < b.second;
        });

        Compress<int> cp;
        for (int i = 0; i < N; i++) {
            cp.add(B[i].first);
        }
        cp.build();
        for (int i = 0; i < N; i++) {
            A[i] = cp.get(B[i].first);
        }
    }
    SegTree<int> seg(N, [](int a, int b) { return max(a, b); }, 0);

    for (int i = 0; i < N; i++) {
        int x = seg.get(0, A[i]) + 1;
        seg.update(A[i], max(seg[A[i]], x));
    }
    print(seg.get(0, N));
}
