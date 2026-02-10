#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_diff = 1e9 + 10;

    for (int i = 1; i < n; i++) {
        min_diff = gcd(min_diff, a[i] - a[i - 1]);
    }

    int ans = (a[n - 1] - a[0]) / min_diff + 1 - n;

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
        cout << "\n";
    }

    return 0;
}
