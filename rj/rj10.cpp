#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
pair<int,int> a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n);
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++) mp[a[i].first].push_back(a[i].second);
    vector<int> v;
    for(auto it:mp){
        auto v1=it.second;
        if(v.size()==0){
            v.push_back(v1[0]);
        }else{
            auto its=upper_bound(v1.begin(),v1.end(),v.back());
            if(its!=v1.end()) v.push_back(*its);
            else{
                if(v.size()>=2){
                    int x=v[(int)v.size()-2];
                    auto it1=upper_bound(v1.begin(),v1.end(),x);
                    if(it1!=v1.end()){
                        v.pop_back();
                        v.push_back(*it1);
                    }
                }else{
                    v[0]=v1[0];
                }
            }
        }
    }
    cout<<v.size();
    return 0;
}