// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#if !defined(mhnd01s) || defined(ONLINE_JUDGE)
#define print(...) ((void)0)
#endif
using ll = long long;
void solve();
signed main() {
#ifdef mhnd01s
    int x = mt19937(random_device()())()%100;printf("%d\n", x);
    freopen("out", "wt", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        if(t) cout << '\n';
    }return 0;
}

using ld = double;
using pt = complex<ld>;
#define X real()
#define Y imag()
#define dot(a, b) (conj(a) * (b)).X
#define cross(a, b) (conj(a) * (b)).Y

pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    return fp + (r-p) * (fq-fp) / (q-p);
}

pt translate(pt p, pt v) { return p + v; }
pt scale(pt p, double factor, pt c = pt(0, 0)) { return c + (p-c) * factor; }
pt rotate(pt p, double alph, pt c = pt(0, 0)) { return c + polar(1.0, alph) * (p - c); }

double angle(pt v, pt w) {
    return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0));
}

bool half(pt p) { // true if in blue half
    assert(p.X != 0 || p.Y != 0);
    return p.Y > 0 || (p.Y == 0 && p.X < 0);
}
void polarSortAround(vector<pt>& points) {
    pt o = pt(0, 0);
    sort(points.begin(), points.end(), [&](pt v, pt w) {
        return make_tuple(half(v-o), 0) <
               make_tuple(half(w-o), cross(v-o, w-o));
    });
}

void solve() {

}
