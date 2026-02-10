template<class T>
struct BIT { // 1-based
    int n;
    vector<T> tree;
    explicit BIT(int size) : n(size), tree(size + 1) { }

    void add(int i, T val) {
        for (; i <= n; i += i & -i)
            tree[i] += val;
    }

    T query_point(int i) {
        if (!i) return query(0);
        return query(i) - query(i - 1);
    }
    void set(int i, T val) {
        int c = query_point(i);
        add(i, val - c);
    }

    T query(int i) {
        T sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    T range(int l, int r) {
        return query(r) - query(l - 1);
    }

    int lower_bound(T target) {
        int i = 0;
        T curr = 0;
        for (int mask = 1 << __lg(n); mask > 0; mask >>= 1) {
            if (i + mask <= n && curr + tree[i + mask] < target) {
                curr += tree[i += mask];
            }
        }
        return i + 1;
    }
};