#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		if(n<=2){
			cout << "0" << endl;
			continue;
		}
		int mini=v[1]-v[0];
		for(int i=1;i<n;i++){
			mini=min(mini,v[i]-v[i-1]);
		}
		int s=1,e=mini+1;
		while(s+1<e){
			int mid=(s+e)/2;
			bool ok=1;
			for(int i=1;i<n;i++){
				int gap=v[i]-v[i-1];
				if(gap%mid==0){

				}
				else {
					ok=0;
					break;
				}
			}
			if(ok) {
				s=mid;
			}
			else {
				e=mid;
			}
		}
		int cc=0;
		for(int i=1;i<n;i++){
			int gap=v[i]-v[i-1];
			int cnt=(gap/s)-1;
			cc+=cnt;
		}
		cout << cc << endl;
	}
	return 0;
}