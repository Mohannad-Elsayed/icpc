#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;

    map<long long, vector<long long>> kite;
    for(int i=0; i<N; i++){
        long long A,B;
        cin>>A>>B;

        auto itr = kite.find(A);
        if(itr == kite.end()){
            vector<long long> tmp(1,B);
            kite.emplace(A,tmp);
        } else {
            kite[A].push_back(B);
        }
    }
    for(auto &x: kite) sort(x.second.begin(), x.second.end());
    
    vector<long long> LIS;
    long long max_num = 9223372036854775807;
    LIS.push_back(max_num);
    for(auto &x : kite){
        long long tmp;

        auto itr = upper_bound(x.second.begin(), x.second.end(), max_num);
        if(itr == x.second.end()) tmp = x.second[0];
        else                      tmp = x.second[distance(x.second.begin(), itr)];

        auto itr2 = lower_bound(LIS.begin(), LIS.end(), tmp);
        if(itr2 == LIS.end()) {
            LIS.push_back(tmp);
            max_num = tmp;
        } else {
            int ind = distance(LIS.begin(), itr2);
            LIS[ind] = tmp;
            if(ind == LIS.size() - 1) max_num = tmp;
        }
    }
    cout << LIS.size();
}