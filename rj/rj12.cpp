#ifdef _DEBUG
#include"mine.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
#define MOD (998244353)
#define ll		int64_t
#define ull		uint64_t
#define uint	uint32_t
#define rep(i, n) for (int32_t i = 0; i < (n); i++)
#define rep_(i, x, n) for (int32_t i = x; i < (n); i++)
#define chmax(x, y)	(x) = max((x), (y));
#define chmin(x, y)	(x) = min((x), (y));
#define out_y cout << "Yes" << endl;
#define out_n cout << "No" << endl;
#define put(x)	cout << (x);
#define put_(x)	cout << (x) << " ";
#define puts(x)	cout << (x) << endl;
#define mp (make_pair)
#define Dsize 4
int8_t direc[Dsize][2] = { {-1,0},{0,-1},{1,0},{0,1} }; // L,U,R,D
#define popcnt(x) __builtin_popcountll(x)
struct PAI { ll x; ll y;		bool operator<(const PAI& other) const { return ((x != other.x) ? (x < other.x) : (y < other.y)); } }; /* 昇順(0 < 1) */
struct STU { int x; int y; int z;	bool operator<(const STU& other) const { return ((x != other.x) ? (x < other.x) : ((y != other.y) ? (y < other.y) : (z < other.z))); } };

#define INF (INT32_MAX)

int main() {
    int N;
    cin >> N;
    vector<PAI> A(N);

    rep(i, N) {
        cin >> A[i].y >> A[i].x;
    }

    sort(A.begin(), A.end());
    map<ll, int> ma;
    ma[0] = 0;

    for(auto[b,a]:A) {
        auto ite = ma.lower_bound(a);
        if (ite != ma.begin())ite--;
        chmax(ma[a], ite->second + 1);
        ite = ma.end(); ite--;
        chmax(ma[a], ite->second);
    }
    int ans = 0;
    for (auto m : ma)chmax(ans, m.second);
    cout << ans << endl;
}