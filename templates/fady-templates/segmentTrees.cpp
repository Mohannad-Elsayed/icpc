#include <bits/stdc++.h>
using namespace std;

struct tag {
    int64_t add{}, st{};
    void apply(tag const &p) {
        if(p.st) st = p.st, add = 0;
        else if(st) st += p.add;
        else add += p.add;
    }
};

struct info {
    int64_t sum;
    info(int64_t x) {
        sum = x;
    }
    info() {
        sum = 0;
    }
    void apply(tag const &lz, int lx, int rx) {
        if(lz.st) sum = (rx - lx + 1) * lz.st;
        else if(lz.add) sum += (rx - lx + 1) * lz.add;
    }
    friend info operator+(const info &l, const info &r) {
        info res;
        res.sum = l.sum + r.sum;
        return res;
    }
};

template<class info>
class segmentTreeIterative {
    int size;
    vector<info> tree;
    static info defaultVal;
public:
    explicit segmentTreeIterative(int n) : size(n), tree(size << 1, defaultVal) { }

    template<class U>
    explicit segmentTreeIterative(const U &arr) : size(arr.size()), tree(size << 1, defaultVal) {
        for(int i = 0; i < arr.size(); i++)
            tree[i + size] = arr[i];
        for(int i = size - 1; i > 0; i--)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(int i, info v) {
        tree[i += size] = v;
        for(i >>= 1; i; i >>= 1)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    info get(int l, int r) {
        info resL = defaultVal, resR = defaultVal;
        l += size, r += size + 1;
        while(l < r) {
            if(l & 1) resL = resL + tree[l++];
            if(r & 1) resR = tree[--r] + resR;
            l >>= 1, r >>= 1;
        }
        return resL + resR;
    }
};
template<> info segmentTreeIterative<info>::defaultVal = info();

template<class info, class tag>
class lazySegment {
    int n;
    vector<info> tr;
    vector<tag> lz;
    static info defaultVal;

    inline void push(int x, int lx, int rx) {
        if(lx != rx) lz[x << 1].apply(lz[x]), lz[x << 1 | 1].apply(lz[x]);
        tr[x].apply(lz[x], lx, rx);
        lz[x] = tag();
    }

    template<class U>
    void build(int x, int lx, int rx, U &arr) {
        if(lx == rx) return void(tr[x] = arr[lx]);
        int m = (lx + rx) >> 1;
        build(x << 1, lx, m, arr);
        build(x << 1 | 1, m + 1, rx, arr);
        tr[x] = tr[x << 1] + tr[x << 1 | 1];
    }

    info get(int x, int lx, int rx, int l, int r) {
        push(x, lx, rx);
        if(lx > r || l > rx) return defaultVal;
        if(lx >= l && rx <= r) return tr[x];
        int m = (lx + rx) >> 1;
        return get(x << 1, lx, m, l, r) + get(x << 1 | 1, m + 1, rx, l, r);
    }

    void set(int x, int lx, int rx, int i, info val) {
        push(x, lx, rx);
        if (i < lx || i > rx) return;
        if(lx == rx) return void(tr[x] = val);
        int m = (lx + rx) >> 1;
        set(x << 1, lx, m, i, val), set(x << 1 | 1, m + 1, rx, i, val);
        tr[x] = tr[x << 1] + tr[x << 1 | 1];
    }

    void applyRange(int x, int lx, int rx, int l, int r, tag v) {
        push(x, lx, rx);
        if(lx > r || l > rx) return;
        if(lx >= l && rx <= r) return lz[x] = v, push(x, lx, rx);
        int m = (lx + rx) >> 1;
        applyRange(x << 1, lx, m, l, r, v), applyRange(x << 1 | 1, m + 1, rx, l, r, v);
        tr[x] = tr[x << 1] + tr[x << 1 | 1];
    }
public:
    explicit lazySegment(int _n) : n(_n + 1), tr(4 << __lg(n)), lz(4 << __lg(n)) { }
    template<class U>
    explicit lazySegment(U &arr) : n(int(arr.size())), tr(4 << __lg(n)), lz(4 << __lg(n)) {
        build(1, 0, n - 1, arr);
    }
    void set(int i, info v) {
        set(1, 0, n - 1, i, v);
    }
    void applyRange(int l, int r, tag v) {
        applyRange(1, 0, n - 1, l, r, v);
    }
    info get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};
template<> info lazySegment<info, tag>::defaultVal = info();

template<class info>
class dynamicSegmentTree {
    struct node {
        int l{}, r{};
        info v;
    };
    vector<node> tr;
    int n, root;
    static info defaultVal;

    int new_node() {
        tr.emplace_back();
        return int(tr.size()) - 1;
    }

    info get(int x, int lx, int rx, int l, int r) {
        if(!x || lx > r || l > rx) return defaultVal;
        if(lx >= l && rx <= r) return tr[x].v;
        int m = (lx + rx) >> 1;
        return get(tr[x].l, lx, m, l, r) + get(tr[x].r, m + 1, rx, l, r);
    }

    int set(int x, int lx, int rx, int i, info val) {
        if (i < lx || i > rx) return x;
        if(!x) x = new_node();
        if(lx == rx) return tr[x].v = val, x;
        int m = (lx + rx) >> 1;
        tr[x].l = set(tr[x].l, lx, m, i, val), tr[x].r = set(tr[x].r, m + 1, rx, i, val);
        return tr[x].v = tr[tr[x].l].v + tr[tr[x].r].v, x;
    }
public:
    explicit dynamicSegmentTree(int _n = 1'000'000'000, int expectedOps = 1) : n(_n), tr(1), root(0) { tr.reserve(expectedOps * __lg(n) * 2); }

    void set(int i, info v) {
        root = set(root, 0, n, i, v);
    }
    info get(int l, int r) {
        return get(root, 0, n, l, r);
    }
};
template<> info dynamicSegmentTree<info>::defaultVal = info();

template<class info>
class dynamicPersistentSegmentTree {
    struct node {
        int l{}, r{};
        info v;
    };
    vector<node> tr;
    int n;
    static info defaultVal;

    int clone(int x) {
        tr.emplace_back(tr[x]);
        return int(tr.size()) - 1;
    }
    info get(int x, int lx, int rx, int l, int r) {
        if(!x || lx > r || l > rx) return defaultVal;
        if(lx >= l && rx <= r) return tr[x].v;
        int m = (lx + rx) >> 1;
        return get(tr[x].l, lx, m, l, r) + get(tr[x].r, m + 1, rx, l, r);
    }
    int set(int x, int lx, int rx, int i, info val) {
        if (i < lx || i > rx) return x;
        x = clone(x);
        if(lx == rx) return tr[x].v = val, x;
        int m = (lx + rx) >> 1;
        tr[x].l = set(tr[x].l, lx, m, i, val), tr[x].r = set(tr[x].r, m + 1, rx, i, val);
        return tr[x].v = tr[tr[x].l].v + tr[tr[x].r].v, x;
    }
public:
    explicit dynamicPersistentSegmentTree(int _n = 1'000'000'000, int expectedOps = 1) : n(_n), tr(1) { tr.reserve(expectedOps * __lg(n) * 2); }

    int set(int root, int i, info v) {
        return set(root, 0, n, i, v);
    }
    info get(int root, int l, int r) {
        return get(root, 0, n, l, r);
    }
};
template<> info dynamicPersistentSegmentTree<info>::defaultVal = info();
