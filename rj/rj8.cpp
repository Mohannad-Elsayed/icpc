#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <limits>
#include <bitset>


#include <climits>
using namespace std;
#define int int64_t

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

#define all(x) (x).begin(), (x).end()
void printer(vector<int> v){
    cout<<"[";
    for(auto x:v)cout<<x<<",";
    cout<<"]\n";
}

const ll INFLL = (ll)4e18;
const int INF = (int)1e9;
const int MOD = 1'000'000'007;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << "\n"
#else
#define debug(x)
#endif
int bit_length(long long n) {
    return 64 - __builtin_clzll(n);

}


void solve() {
    int n;
    cin >> n;
    int x,y;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(all(a));
    vector<int> res;
    set<int> seen;
    for(int i=0;i<n;i++){
        if(seen.find(a[i].first) != seen.end())continue;
        res.push_back(a[i].second);

        seen.insert(a[i].first);
    }
    int len = 0;
    for(auto cur : res){
        if(cur == INF) continue;
        if(len == 0 ||res[len-1]< cur) res[len++] = cur;
        else *lower_bound(res.begin(), res.begin() + len, cur) = cur;
    }
    cout << len << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
