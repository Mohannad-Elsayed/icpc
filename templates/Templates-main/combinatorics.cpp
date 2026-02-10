namespace comb {
    const int mod = 1e9 + 7;
    int MXS_ = 1;
    vector<int> fac_(1, 1), inv_(1, 1);
 
    int fp(int b, int p = mod - 2, int MOD = mod) {
        int ans = 1;
        while(p) {
            if(p & 1) ans = int(ans * 1LL * b % MOD);
            b = int(b * 1LL * b % MOD);
            p >>= 1;
        }
        return ans;
    }
 
    void up_(int nw) {
        if (MXS_ > nw) return;
        nw = max(MXS_ << 1, 1 << (__lg(nw) + 1));
        fac_.resize(nw), inv_.resize(nw);
        for(int i = MXS_; i < fac_.size(); i++)
            fac_[i] = int(fac_[i - 1] * 1LL * i % mod);
 
        inv_.back() = fp(fac_.back(), mod - 2);
        for(int i = int(inv_.size()) - 2; i >= MXS_; i--)
            inv_[i] = int(inv_[i + 1] * 1LL * (i + 1) % mod);
        MXS_ = nw;
    }
 
    inline int nCr(int n, int r) {
        if(r < 0 || r > n) return 0;
        up_(n);
        return int(fac_[n] * 1LL * inv_[r] % mod * inv_[n - r] % mod);
    }
    inline int nCr1(int n, int r) {
        if(r < 0 || r > n) return 0;
        r = min(r, n - r);
        up_(r);
        int ans = inv_[r];
        for(int i = n - r + 1; i <= n; i++) {
            ans = int(ans * 1LL * i % mod);
        }
        return ans;
    }
    inline int nPr(int n, int r) {
        if(r < 0 || r > n) return 0;
        up_(n);
        return int(fac_[n] * 1LL * inv_[n - r] % mod);
    }
 
    inline int add(int x, int y) {
        x = y < 0? x + y + mod: x + y;
        return x >= mod? x - mod: x;
    }
    inline int mul(int x, int y) {
        return int(x * 1LL * y % mod);
    }
 
    inline int sub(int x, int y) {
        return ((x - y) % mod + mod) % mod;
    }
 
    inline int Inv(int x) {
        return fp(x, mod - 2);
    }
 
    inline int divide(int a, int b) {
        return mul(a, Inv(b));
    }
 
    inline int catalan(int n) {
        return mul(nCr(2 * n, n), Inv(n + 1));
    }
 
    inline int StarsAndPars(int n, int k) {
        return nCr(n + k - 1, k - 1);
    }
}