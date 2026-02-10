// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if defined(ONLINE_JUDGE)
    #define print(...) ((void)0)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> T rnglr(T l, T r) {return uniform_int_distribution<T>(l, r)(rng);}
void solve();
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // string filename = "";
    // freopen((filename + ".in").c_str(), "r", stdin);
    // freopen((filename + ".out").c_str(), "w", stdout);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {

}