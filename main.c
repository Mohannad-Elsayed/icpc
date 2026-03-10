// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if !defined(mhnd01s) || defined(ONLINE_JUDGE)
#define print(...) ((void)0)
#endif
using ll = long long;
void solve();
signed main() {
#ifdef mhnd01s
    int x = mt19937(random_device()())()%100;printf("%d\n", x);
    freopen("out", "wt", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        if(t) cout << '\n';
    }return 0;
}

void solve() {
    int n, K; cin >> n >> K;
    vector<int> vals(n);
    for (auto &i : vals) cin >> i;
    vector<vector<int>> tree(n);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        tree[--u].push_back(--v);
        // tree[v].push_back(u);
    }

    vector<ll> dp1(n);
    function<void(int, int)> dfs1 = [&](int u, int p) {
        for (int v : tree[u]) if (v ^ p)
            dfs1(v, u);

        sort(tree[u].begin(), tree[u].end(), [&](int i, int j){ return dp1[i] > dp1[j]; });
        print(u, tree[u], p);
        dp1[u] = vals[u];
        if (!tree[u].empty()) dp1[u] += dp1[tree[u].front()];
    };
    dfs1(0, -1);
    print(dp1);

    function<ll(int, int, int, int)> dfs2 = [&](int u, int p, int k, bool taken) -> ll {
        if (k == K) return -1e16; // started an illegal path
        ll ret = taken * vals[u];
        for (int v : tree[u]) if (v ^ p) {
            ret = max(ret, dfs2(v, u, k, 0)); // stop the path or skip the node
            // if taken, take the current node, and increase number of paths only if my parent isn't taken (start a new path)
            ret = max(ret, vals[v] + dfs2(v, u, k + !taken, 1));
        }
        if (!taken) {
            // if my parent isn't taken, maybe I can take the current with maximum of my children, and start a new path
            ll cur = dp1[u], mx = 0;
            if (tree[u].size() > 1) cur += dp1[tree[u][1]];
            for (int i = 2; i < (int)tree[u].size(); i++)
                mx = max(mx, dfs2(tree[u][i], u, k+1, 0));
            cur += mx;
            ret = max(ret, cur);
        }
        print(u, p, k, taken, ret);
        return ret;
    };

    cout << dfs2(0, -1, 0, 0);
}