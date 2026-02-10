// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if !defined(mhnd01s) || defined(ONLINE_JUDGE)
#define print(...) ((void)0)
#endif
using ll = long long;
void solve();
signed main() {
    cin.exceptions(cin.failbit);
#if defined(mhnd01s)
    freopen("z.in", "r", stdin);
    freopen("z.out", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {

}