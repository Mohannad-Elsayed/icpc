struct info {
    ll sum;
    info(ll x) {
        sum = x;
    }
    info() { // default value
        sum = 0;
    }
    friend info operator+(const info &l, const info &r) {
        info ret;
        ret.sum = l.sum + r.sum;
        return ret;
    }
};
template<class info>
class segmentTreeIterative {
    int size;
    vector<info> tree;
    static info defaultVal;
public:
    explicit segmentTreeIterative(int n) : size(n), tree(size << 1, defaultVal) { }

    template<class U>
    explicit segmentTreeIterative(const U &arr) : size(arr.size()), tree(size << 1, defaultVal) {
        for(int i = 0; i < arr.size(); i++)
            tree[i + size] = arr[i];
        for(int i = size - 1; i > 0; i--)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(int i, info v) {
        tree[i += size] = v;
        for(i >>= 1; i; i >>= 1)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    info get(int l, int r) {
        info resL = defaultVal, resR = defaultVal;
        l += size, r += size + 1;
        while(l < r) {
            if(l & 1) resL = resL + tree[l++];
            if(r & 1) resR = tree[--r] + resR;
            l >>= 1, r >>= 1;
        }
        return resL + resR;
    }
};
template<> info segmentTreeIterative<info>::defaultVal = info();