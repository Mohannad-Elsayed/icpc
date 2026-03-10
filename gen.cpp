#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> make_evils(ll prime, ll n)
{
    vector<ll> ret(n);
    for (ll i = 0; i < n; i++)
        ret[i] = (i + 1) * prime;
    return ret;
}

signed main() {
    auto x = make_evils(20753, 20753);
    cout << "1\n200000 200000\n";
    for (int i = 0; i < 400000; i++)
        cout << x[i%x.size()] << ' ' << 200000 << '\n';
}