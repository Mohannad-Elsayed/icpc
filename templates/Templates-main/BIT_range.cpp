template<typename T>
class BitR { // 0-based
    int n;
    vector<T> f, s;
    void add(vector<T> &a, int i, T val) {
        for(; i < n; i += i & -i)
            a[i] += val;
    }
public:
    BitR(int n) : n(n + 5), f(n + 6), s(n + 6) { }

    void add(int i, T val) {
        add(s, i + 1, -val);
    }

    T query_point(int i) {
        if (!i) return query(0);
        return query(i) - query(i - 1);
    }
    void set(int i, T val) {
        int c = query_point(i);
        add(i, val - c);
    }

    void add(int l, int r, T val) {
        l++, r++;
        add(f, l, val);
        add(f, r + 1, -val);
        add(s, l, val * (l - 1));
        add(s, r + 1, -val * r);
    }

    T query(int ii) {
        ii++;
        T sum = 0;
        int i = ii;
        for(; i > 0; i ^= i & -i)
            sum += f[i];
        sum *= ii;
        i = ii;
        for(; i > 0; i ^= i & -i)
            sum -= s[i];
        return sum;
    }

    T range(int l, int r) {
        return query(r) - query(l - 1);
    }
};