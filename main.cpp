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
    int n; cin >> n;
    vector<int> C(n), A(n);
    for (auto &i : C) cin >> i;
    for (auto &i : A) cin >> i;

    vector<int> dp(n);
    

}