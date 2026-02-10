struct info {
    int sum, pref, suff, ans, mnelement = -1e4-10;;
    info(int x) {
        sum = pref = suff = x;
//        ans = max<int>(x, 0);
        ans = x; // if empty subarray is not allowed
    }
    info() { // default value
        sum = pref = suff = ans = mnelement;
    }
    friend info operator+(const info &l, const info &r) {
        info ret;
        ret.sum = l.sum + r.sum;
        ret.pref = max(l.pref, l.sum + r.pref);
        ret.suff = max(r.suff, r.sum + l.suff);
        ret.ans = max({l.ans, r.ans, l.suff + r.pref});
        return ret;
    }
};