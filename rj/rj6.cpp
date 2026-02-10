#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a){
        cin >> x;
    }

    ll d = 1e9;
    for (int i = 0; i < n - 1 ; i++){
        d = min(d , a[i + 1] - a[i]);
    }

    ll sum = 0;
    for (int i = 0; i < n - 1;i++){

        ll l = 1 , r = 1000, sol = 0;
        while (l <= r){
            ll m = l + (r - l) / 2;

            ll k = m * d + a[i];

            if (k <= a[i + 1]){
                sol = m - 1;
                l = m + 1;
            }
            else r = m - 1;
        }

        sum += sol;
    }

    cout << sum << '\n';
}

int main() {
    fast_cin();

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
