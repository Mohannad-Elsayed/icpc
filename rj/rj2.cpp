#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 	998244353;
template<typename T>
void chmax(T& x, const T& y) {
    if (y > x) x = y;
}
template<typename T>
void chmin(T& x, const T& y) {
    if (y < x) x = y;
}
template<typename T>
void mult(T& x, const T& y) {
    x = (x * y) % MOD;
}
template<typename T>
void add(T& x, const T& y) {
    x = ((x + y) % MOD + MOD) % MOD;
}
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sm = INT_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            sm = min(sm, a[i + 1] - a[i]);
        }
        cout << (a[n - 1] - a[0]) / sm - (n - 1) << "\n";
    }
}
