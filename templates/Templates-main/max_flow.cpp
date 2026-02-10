class Dinic {
   private:
    struct E {
        int to, rev;
        ll c, oc;
        ll f() { return max(oc - c, 0LL); }
    };
    vector<int> lvl, ptr, q;
    vector<vector<E>> g;
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int &i = ptr[v]; i < g[v].size(); ++i) {
            E &e = g[v][i];
            if (lvl[e.to] == lvl[v] + 1 && e.c)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p;
                    g[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }

   public:
    Dinic(int n) : lvl(n), ptr(n), q(n), g(n) {}
    void add_edge(int u, int v, ll c) { // directed
        g[u].push_back({v, (int)g[v].size(), c, c});
        g[v].push_back({u, (int)g[u].size() - 1, 0, 0});
    }
    ll calc(int s, int t) { // source to destination
        ll flow = 0;
        while (true) {
            fill(lvl.begin(), lvl.end(), 0);
            int qs = 0, qe = 0;
            lvl[q[qe++] = s] = 1;
            while (qs < qe && !lvl[t]) {
                int v = q[qs++];
                for (auto &e : g[v])
                    if (!lvl[e.to] && e.c) lvl[q[qe++] = e.to] = lvl[v] + 1;
            }
            if (!lvl[t]) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        }
        return flow;
    }
    void reset() { // before calling calc again
        for (auto &adj : g)
            for (auto &e : adj) e.c = e.oc;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};