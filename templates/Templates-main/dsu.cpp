struct DSU {
    vector<int> p, sz;
    int n, comps;
    DSU(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n + 10; comps = _n;
        p.resize(n); sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return 0;
        if (sz[u] < sz[v]) swap(u, v);
        p[v] = u; sz[u] += sz[v]; comps--;
        return 1;
    }
    bool same(int u, int v) { return find(u) == find(v); }
    int size(int u) { return sz[find(u)]; }
    int size() { return comps; }
};
