mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct StoerWagner { // n^3, 1-based, undirected
    int n;
    vector<vector<ll>> g;
    vector<ll> dis;
    vector<int> idx;
    vector<bool> vis;
    const ll inf = 1e18;
    StoerWagner() {}
    StoerWagner(int _n) {
        n = _n;
        int ns = _n+10;
        g = vector<vector<ll>>(ns, vector<ll>(ns));
        dis.resize(ns);
        idx.resize(ns);
        vis.resize(ns);
    }
    //undirected edge, multiple edges are merged into one edge
    void add_edge(int u, int v, ll w) {
        if (u != v) {
            g[u][v] += w;
            g[v][u] += w;
        }
    }
    ll mincut() {
        ll ans = inf;
        for (int i = 0; i < n; ++i)
            idx[i] = i + 1;
        shuffle(idx.begin(), idx.begin() + n, rnd);
        int curr_n = n;
        while (curr_n > 1) {
            int t = 1, s = 0;
            for (int i = 1; i < curr_n; ++i) {
                dis[idx[i]] = g[idx[0]][idx[i]];
                if (dis[idx[i]] > dis[idx[t]]) t = i;
            }
            fill(vis.begin(), vis.end(), false);
            vis[idx[0]] = true;
            for (int i = 1; i < curr_n; ++i) {
                if (i == curr_n - 1) {
                    if (ans > dis[idx[t]]) ans = dis[idx[t]];
                    if (ans == 0) return 0;
                    for (int j = 0; j < curr_n; ++j) {
                        g[idx[s]][idx[j]] += g[idx[j]][idx[t]];
                        g[idx[j]][idx[s]] += g[idx[j]][idx[t]];
                    }
                    idx[t] = idx[--curr_n];
                }
                vis[idx[t]] = true;
                s = t;
                t = -1;
                for (int j = 1; j < curr_n; ++j) {
                    if (!vis[idx[j]]) {
                        dis[idx[j]] += g[idx[s]][idx[j]];
                        if (t == -1 || dis[idx[t]] < dis[idx[j]]) t = j;
                    }
                }
            }
        }
        return ans;
    }
};