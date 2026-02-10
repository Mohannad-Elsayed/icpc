#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 998244353;
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<array<int, 2>>v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [&](array<int, 2>& a1, array<int, 2>& a2) {
        if (a1[0] == a2[0]) return a1[1] > a2[1];
        return a1[0] < a2[0];
    });
    vector<int>ends;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && v[i][0] == v[i - 1][0]) continue;

        auto bs = [&](int val) {
            int l = 0, r = ends.size() - 1;
            int res = -1, m;
            while (l <= r) {
                m = l + r >> 1;
                if (ends[m] >= val) {
                    r = m - 1;
                    res = m;
                }
                else {
                    l = m + 1;
                }
            }
            return res;
        };

        int p = bs(v[i][1]);
        if (p == -1) ends.push_back(v[i][1]);
        else ends[p] = v[i][1];
    }
    cout << ends.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int _ = 1;
    //cin >> _;
    while (_--) solve();

    return 0;
}
