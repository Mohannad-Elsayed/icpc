#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename K, typename V, typename Comp = less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename Comp = less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template<typename K, typename V, typename Comp = less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename Comp = less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;
//---------------------------------------------------------------------------------

mt19937 rnd(time(nullptr));
struct Treap {
    struct node {
        uint32_t pri = rnd();
        int sz = 1, l = 0, r = 0, val{};
        int64_t sum{};
        bool rev = false;
        node(int x) : sum(val = x) { }
    };
    vector<node> tr;
    Treap() : tr(1, 0) { tr[0].sz = 0; }
    inline void pull(int x) {
        tr[x].sz = tr[tr[x].l].sz + tr[tr[x].r].sz + 1;
        tr[x].sum = tr[tr[x].l].sum + tr[tr[x].r].sum + tr[x].val;
    }
    inline void push(int x) {
        if(tr[x].rev) {
            tr[tr[x].l].rev ^= 1, tr[tr[x].r].rev ^= 1;
            swap(tr[x].l, tr[x].r);
            tr[x].rev = false;
        }
    }
    inline int new_node(int val) {
        tr.emplace_back(val);
        return int(tr.size()) - 1;
    }
    int merge(int lx, int rx) {
        if(!lx || !rx) return rx + lx;
        push(lx), push(rx);
        if(tr[lx].pri < tr[rx].pri) return tr[rx].l = merge(lx, tr[rx].l), pull(rx), rx;
        return tr[lx].r = merge(tr[lx].r, rx), pull(lx), lx;
    }
    void split(int x, int k, int &lx, int &rx) {
        if(!x) return lx = rx = 0, void();
        push(x);
        if(k <= tr[tr[x].l].sz) split(tr[x].l, k, lx, tr[x].l), pull(rx = x);
        else split(tr[x].r, k - tr[tr[x].l].sz - 1, tr[x].r, rx), pull(lx = x);
    }
    array<int, 3> split(int x, int l, int r) {
        int a, b, c;
        split(x, r + 1, b, c);
        split(b, l, a, b);
        return {a, b, c};
    }
};

template<typename T>
struct sparse{
    int Log, n;
    vector<vector<T>> table;
    function<T(T, T)> merge;
    template<class U>
    explicit sparse(vector<T> arr, U merge) : merge(merge), n((int)arr.size()), Log(__lg(arr.size()) + 1), table(Log, vector<T>(n)) {
        table[0] = arr;
        for(int l = 1; l < Log; l++) {
            for(int i = 0; i + (1 << (l - 1)) < n; i++) {
                table[l][i] = merge(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }
    T query(int l, int r) {
        if(l > r) return {};
        int len = __lg(r - l + 1);
        return merge(table[len][l], table[len][r - (1 << len) + 1]);
    }
};

template<class T>
struct BIT { // 0-based
    int n;
    vector<T> tree;
    explicit BIT(int size) : n(size + 5), tree(n + 1) { }

    void add(int i, T val) {
        for (i++; i <= n; i += i & -i)
            tree[i] += val;
    }

    T query(int i) {
        T sum = 0;
        for (i++; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    T range(int l, int r) {
        if(l > r) return T();
        return query(r) - query(l - 1);
    }

    int lower_bound(T target) {
        if(target <= 0) return 0;
        int pos = 0;
        T sum = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if(pos + i <= n && sum + tree[pos + i] < target) {
                sum += tree[pos + i];
                pos += i;
            }
        }
        return pos;
    }
};

template<typename T>
class BITRange { // 0-based
    int n;
    vector<T> B1, B2;

    void add(vector<T>& bit, int i, T x) {
        for (++i; i <= n; i += i & -i)
            bit[i] += x;
    }

    T query(vector<T>& bit, int i) {
        T res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }

public:
    explicit BITRange(int size) : n(size + 5), B1(n + 2), B2(n + 2) {}

    void add(int l, int r, T x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }
    void add(int i, T x) { add(B2, i, -x); }

    T query(int i) {
        return query(B1, i) * i - query(B2, i);
    }

    T range(int l, int r) {
        if (l > r) return T();
        return query(r) - query(l - 1);
    }
};

class sqrtDecomposition {
public:
    size_t n, z;
    vector<vector<int>> arr;

    explicit sqrtDecomposition(const vector<int> &a) : n(a.size()), z(int(sqrt(a.size())) + 1), arr(z) {
        for(int i = 0; i < n; i++) arr[i / z].push_back(a[i]);
    }

    void rebuild() {
        int tot{};
        vector<int> a(n);
        for(auto &B : arr) {
            for(auto i : B) a[tot++] = i;
            B.clear();
        }
        z = int(sqrt(a.size()) + 1);
        arr.resize(z);
        for(tot = 0; tot < n; tot++) arr[tot / z].push_back(a[tot]);
    }

    void insert(int j, int x) {
        for(int i = 0; i < z; i++) {
            if(j <= arr[i].size()) {
                arr[i].insert(arr[i].begin() + j, x), n++;
                if(arr[i].size() > z * 10) rebuild();
                return;
            }
            j -= int(arr[i].size());
        }
    }

    int erase(int j) {
        for(int i = 0; i < z; i++) {
            if(j < arr[i].size()) {
                int x = arr[i][j];
                for(j++; j < arr[i].size(); j++)
                    arr[i][j - 1] = arr[i][j];
                arr[i].pop_back();
                return n--, x;
            }
            j -= int(arr[i].size());
        }
        return -1;
    }

    int element(int j) {
        for(int i = 0; i < z; j -= int(arr[i++].size()))
            if(j < arr[i].size()) return arr[i][j];
        return -1;
    }

    int count(int l, int r) {
        int j = 0;
        for(int b = 0; b < z; b++) {
            if(j > r) break;
            if(j >= l) {
                if(j + arr[b].size() - 1 <= r) { // take all block
                    j += int(arr[b].size());
                    continue;
                }
                for(int i = 0; i < arr[b].size() && j <= r; j++, i++) /* count i */;
            }
            else if(j + arr[b].size() - 1 >= l) {
                int i = l - j;
                for(j = l; i < arr[b].size() && j <= r; j++, i++) /* count i */;
            }
            else j += int(arr[b].size());
        }
        return 0; // return something
    }
};

void moAlgo() {
    int n, q;
    cin >> n >> q;
    int z = int(sqrt(n)) + 1;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans(q);
    vector<array<int, 2>> qu(q);
    vector<vector<int>> _mo(z);
    for(int i = 0; i < q; i++) {
        cin >> qu[i][0] >> qu[i][1];
        _mo[qu[i][0] / z].push_back(i);
    }

    int curr = 0;
    vector<int> freq(100001), f_f(100001);
    auto add = [&](int i) {
        f_f[++freq[arr[i]]]++;
        curr = max(curr, freq[arr[i]]);
    };
    auto del = [&](int i) {
        if(!--f_f[freq[arr[i]]] && curr == freq[arr[i]])
            curr--;
        --freq[arr[i]];
    };

    int c = 0, l = 0, r = -1;
    for(auto &mo : _mo) {
        if(mo.empty()) continue;
        c? std::sort(mo.begin(), mo.end(), [&](int i, int j){return qu[i][1] < qu[j][1];}):
        std::sort(mo.begin(), mo.end(), [&](int i, int j){return qu[i][1] > qu[j][1];});
        c ^= 1;

        for(int i : mo) {
            while(r < qu[i][1]) add(++r);
            while(l > qu[i][0]) add(--l);
            while(r > qu[i][1]) del(r--);
            while(l < qu[i][0]) del(l++);
            ans[i] = curr;
        }
    }
    for(int i : ans)
        cout << i << '\n';
}

namespace BITSET {
    using T = uint64_t;
    int ctz(T x) { return __builtin_ctzll(x); }
    int popcount(T x) { return __builtin_popcountll(x); }

    const int sz_ = sizeof(T) * 8, shift = __lg(sz_), AND = sz_ - 1;
    const int N = 2e5 + 1, M = (N + AND) >> shift;
    const T rem_ = N % sz_ == 0 ? ~T(0) : (T(1) << (N % sz_)) - 1;

    class Bitset {
        array<T, M> b{};
    public:
        // ===== Basic operations =====
        void set() { for (T &i : b) i = ~T(0); b.back() &= rem_; }
        void reset() { for (T &i : b) i = 0; }
        void flip() { for (T &i : b) i ^= ~T(0); b.back() &= rem_; }

        void set(int i) { b[i >> shift] |= T(1) << (i & AND); }
        void reset(int i) { b[i >> shift] &= ~(T(1) << (i & AND)); }
        void flip(int i) { b[i >> shift] ^= T(1) << (i & AND); }
        bool test(int i) const { return (b[i >> shift] >> (i & AND)) & 1; }

        // shorthand
        bool operator[](int i) const { return test(i); }

        // ===== Queries =====
        bool any() const {
            return any_of(b.begin(), b.end(), [](T x){ return x != 0; });
        }
        bool none() const { return !any(); }
        bool all() const {
            for (int i = 0; i < M - 1; i++) if (~b[i]) return false;
            return b.back() == rem_;
        }
        int count() const {
            int res = 0;
            for (T x : b) res += popcount(x);
            return res;
        }

        // ===== Bitwise ops =====
        Bitset operator|(const Bitset &a) const {
            Bitset res;
            for (int i = 0; i < M; i++) res.b[i] = b[i] | a.b[i];
            return res;
        }
        Bitset operator&(const Bitset &a) const {
            Bitset res;
            for (int i = 0; i < M; i++) res.b[i] = b[i] & a.b[i];
            return res;
        }
        Bitset operator^(const Bitset &a) const {
            Bitset res;
            for (int i = 0; i < M; i++) res.b[i] = b[i] ^ a.b[i];
            return res;
        }
        Bitset operator~() const {
            Bitset res = *this;
            res.flip();
            return res;
        }

        Bitset& operator|=(const Bitset &a) { for (int i = 0; i < M; i++) b[i] |= a.b[i]; return *this; }
        Bitset& operator&=(const Bitset &a) { for (int i = 0; i < M; i++) b[i] &= a.b[i]; return *this; }
        Bitset& operator^=(const Bitset &a) { for (int i = 0; i < M; i++) b[i] ^= a.b[i]; return *this; }

        bool operator==(const Bitset &a) const { return b == a.b; }
        bool operator!=(const Bitset &a) const { return b != a.b; }

        // ===== Shifts =====
        Bitset operator>>(int n) const {
            Bitset res;
            int nxt = n / sz_, sh = n % sz_, sh1 = sz_ - sh;
            for (int blc = 0; blc + nxt < M; blc++) {
                res.b[blc] = b[blc + nxt] >> sh;
                if (sh && blc + nxt + 1 < M)
                    res.b[blc] |= b[blc + nxt + 1] << sh1;
            }
            return res;
        }
        Bitset operator<<(int n) const {
            Bitset res;
            int nxt = n / sz_, sh = n % sz_, sh1 = sz_ - sh;
            for (int blc = M - 1; blc >= nxt; blc--) {
                res.b[blc] = b[blc - nxt] << sh;
                if (sh && blc - nxt - 1 >= 0)
                    res.b[blc] |= b[blc - nxt - 1] >> sh1;
            }
            res.b.back() &= rem_;
            return res;
        }

        // ===== Find methods =====
        int find_first() const {
            for (int i = 0; i < M; i++) if (b[i]) return (i << shift) + ctz(b[i]);
            return -1;
        }
        int find_next(int pos) const {
            ++pos;
            if (pos >= N) return -1;
            int blk = pos >> shift;
            T mask = b[blk] & (~T(0) << (pos & AND));
            if (mask) return (blk << shift) + ctz(mask);
            for (int i = blk + 1; i < M; i++) if (b[i]) return (i << shift) + ctz(b[i]);
            return -1;
        }

        // ===== Debug =====
        void print() const {
            for (int i = 0; i < N; i++) if (test(i)) cout << i << ' ';
        }
    };
}
