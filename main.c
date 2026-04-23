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
int m;
string t, tmp;
int Z(vector<int>& z, const string& s) {
    int n = s.size(), st = z.size(), ans = 0;
    for (int i = 0, l = 0, r = 0; i < n; i++) {
        z.push_back(0);
        if (i < r) z[st + i] = min(z[st + i-l], r-i);
        while (i + z[st + i] < n && s[z[st + i]] == s[i + z[st + i]]) z[st + i]++;
        if (i + z[st + i] > r) {
            l = i;
            r = i + z[st + i];
        }
        ans += z[st + i] >= m;
    }
    return ans;
}

vector<vector<pair<int, string>>> tree;
vector<int> z;
int ans = 0;
void dfs(int u, int p) {
    for (auto &[v, s] : tree[u]) if (v ^ p) {
        ans += Z(z, s);
        dfs(v, u);
        print(u, s, p);
        print(z); cout << "\n";
        int n = s.size();
        while (n--) z.pop_back();
    }
}

int n;
void solve() {
    cin >> n;
    tree.resize(n+1);
    for (int i = 2, u; i <= n; i++) {
        cin >> u >> tmp;
        tree[u].emplace_back(i, tmp);
        tree[i].emplace_back(u, tmp);
    }

    cin >> t;
    m = t.size();
    Z(z, t);

    dfs(1, -1);
    cout << ans;
}