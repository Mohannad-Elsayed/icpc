#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N=500100,INF=2e18,MOD=1e9+7;
int t,n,k,x,y,z,m,h,j,u,cnt,mi,tt,rr,mx,res,ans,ll,q;
int a[N],b[N],c[N],dp[1100][2100][4];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<array<int, 3>> in(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> in[i][0] >> in[i][1];
        in[i][2] = i;
    }

    sort(in.begin() + 1, in.end(), [&](auto x, auto y) {
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] > y[1];
    });

    vector<int> val{0}, idx{0};
    vector<int> pre(n + 1);

    for (int i = 1; i <= n; i++) {
        auto [x, y, z] = in[i];


        int it = lower_bound(val.begin(), val.end(), y) - val.begin();

        if (it >= (int)val.size()) {
            pre[z] = idx.back();
            val.push_back(y);
            idx.push_back(z);
        } else {
            pre[z] = idx[it - 1];
            val[it] = y;
            idx[it] = z;
        }
    }

    vector<int> ans;
    for (int i = idx.back(); i != 0; i = pre[i]) {
        ans.push_back(i);
    }
    cout << ans.size() << "\n";

    


}