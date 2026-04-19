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

vector<int> Z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(z[i-l], r-i);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// fast hash
using u64 = uint64_t;
mt19937_64 rng = []{
    u64 time_entropy = chrono::steady_clock::now().time_since_epoch().count();
    u64 memory_entropy = 8273468723;
    seed_seq ss{time_entropy, memory_entropy};
    return mt19937_64(ss);
}();
struct hash61 {
    static const u64 md = (1LL << 61) - 1;
    static u64 step;
    static vector<u64> pw;
    u64 addmod(u64 a, u64 b) const {
        a += b;
        if (a >= md) a -= md;
        return a;
    }

    u64 submod(u64 a, u64 b) const {
        a += md - b;
        if (a >= md) a -= md;
        return a;
    }

    u64 mulmod(u64 a, u64 b) const {
        u64 l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
        u64 l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        u64 ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & md) + (ret >> 61);
        ret = (ret & md) + (ret >> 61);
        return ret - 1;
    }

    void ensure_pw(int sz) const {
        int cur = (int) pw.size();
        if (cur < sz) {
            pw.resize(sz);
            for (int i = cur; i < sz; i++) {
                pw[i] = mulmod(pw[i - 1], step);
            }
        }
    }

    vector<u64> pref, suff;
    int n;

    template<typename T>
    hash61(const T& s) {
        n = (int) s.size();
        ensure_pw(n + 1);
        pref.resize(n + 1);
        suff.resize(n + 1);
        pref[0] = suff[n] = 1;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = addmod(mulmod(suff[i + 1], step), s[i]);
        }
    }

    u64 operator()(const int from, const int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
    }
    
    u64 rev(const int from, const int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(suff[from], mulmod(suff[to + 1], pw[to - from + 1]));
    }
};
u64 hash61::step = (md >> 2) + rng() % (md >> 1);
vector<u64> hash61::pw = vector<uint64_t>(1, 1);

ll solve(int n) {
    vector<string> vs(n);
    for (auto &s : vs) cin >> s;
    
    // vector<hash61> vh;
    // vh.reserve(n+1);
    // for (auto &s : vs) vh.emplace_back(s);
    // ll ret = 0;
    // for (int i = 0; i< n; i++) {
    //     for (int j = i+1; j < n; j++) {
    //         if (vs[i] == vs[j]) {
    //             ret += 2 * vs[i].size() + 2;
    //             continue;
    //         }
    //         int l = 0, r = min(vs[i].size(), vs[j].size()) - 1, mid, ans = -1;
    //         while (l <= r) {
    //             mid = l + r >> 1;
    //             if (vh[i](0, mid) == vh[j](0, mid)) {
    //                 ans = mid;
    //                 l = mid+1;
    //             } else r = mid-1;
    //         }
    //         // cout << i << ' ' << j << ' ' << ans << '\n';
    //         ret += 2ll * (ans+1) + 1;
    //     }
    // }


    return ret;
}

void solve() {
    int n, c = 1; 
    while (cin >> n && n) {
        cout << "Case " << c++ << ": " << solve(n) << '\n';
    }
}