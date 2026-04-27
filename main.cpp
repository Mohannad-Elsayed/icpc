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
    int x = mt19937(random_device()())() % 100;
    printf("%d\n", x);
    freopen("out", "wt", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}

void solve() {
    string s;
    cin >> s;
    s.push_back('$');
    int n = s.size();
    vector<int> p(n), g(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    for (int i = 1; i < n; i++) g[p[i]] = g[p[i-1]] + (s[p[i]] != s[p[i-1]]);

    for (int k = 1; k < n; k <<= 1) {
        for (auto &i : p) i = (i - k + 2 * n) % n;
        vector<int> cnt(n), pos(n), np(n), ng(n);
        for (auto x : g) cnt[x]++;
        for (int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];

        for (int i = 0; i < n; i++)
            np[pos[g[p[i]]]++] = p[i];

        p = np;
        ng[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> now = {g[p[i]], g[(p[i] + k) % n]};
            pair<int, int> prv = {g[p[i-1]], g[(p[i-1] + k) % n]};
            ng[p[i]] = ng[p[i-1]] + (now != prv);
        }
        g = ng;

        if (g[p[n-1]] == n-1) break;
    }

    vector<int> lcp(n);
    for (int i = 0, k = 0; i+1 < n; i++) {
        int j = p[g[i]-1];
        while (s[i + k] == s[j + k]) k++;
        lcp[g[i]] = k;
        k = max(k-1, 0);
    }

    ll ans = 0;
    for (int i = 0; i+1 < n; i++) {
        ans += n-i-1-lcp[g[i]];
    }
    cout << ans;
}
