template<class T = int64_t>
class lazySegment {
    struct node {
        node *l, *r;
        T v{}, E{};
        explicit node() : l(nullptr), r(nullptr) { }
        void build() {
            if(!l) l = new node(), r = new node();
        }
    } *root;
    int size;
    inline static void merge(node *x) {
        x->v = x->l->v + x->r->v;
    }
    inline static T merge(const T &v1, const T &v2) {
        return v1 + v2;
    }
    inline static void push(node *x, const int &lx, const int &rx) {
        if(x->E) {
            if(x->l) x->l->E += x->E;
            if(x->r) x->r->E += x->E;
            x->v += x->E * (rx - lx + 1);
            x->E = 0;
        }
    }

    template<class U>
    void build(node *x, int lx, int rx, U &arr) {
        if(lx == rx) return void(x->v = arr[lx]);
        x->build();
        int m = (lx + rx) >> 1;
        build(x->l, lx, m, arr);
        build(x->r, m + 1, rx, arr);
        merge(x);
    }

    T get(node *x, int lx, int rx, int l, int r) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if(lx > r || l > rx) return 0;
        if(lx >= l && rx <= r) return x->v;
        int m = (lx + rx) >> 1;
        return merge(get(x->l, lx, m, l, r), get(x->r, m + 1, rx, l, r));
    }
    void set(node *x, int lx, int rx, int i, T val) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if (i < lx || i > rx) return;
        if(lx == rx) return void(x->v = val);
        int m = (lx + rx) >> 1;
        set(x->l, lx, m, i, val), set(x->r, m + 1, rx, i, val);
        merge(x);
    }
    void Range(node *x, int lx, int rx, int l, int r, T val) {
        if(lx != rx) x->build();
        push(x, lx, rx);
        if(lx > r || l > rx) return;
        if(lx >= l && rx <= r) return x->E = val, push(x, lx, rx);
        int m = (lx + rx) >> 1;
        Range(x->l, lx, m, l, r, val), Range(x->r, m + 1, rx, l, r, val);
        merge(x);
    }
    void del(node *x) {
        if(x){
            del(x->l), del(x->r);
            delete x;
        }
    }
public://based index 0
    explicit lazySegment(int n = 1000000000) : size(n), root(new node()) { }

    template<class U>
    explicit lazySegment(U &arr) : size(int(arr.size()) - 1), root(new node()) {
        build(root, 0, size, arr);
    }
    ~lazySegment(){
        del(root);
    }
    void set(int i, T v) {
        set(root, 0, size, i, v);
    }
    T get(int l, int r) {
        return get(root, 0, size, l, r);
    }
    void Range(int l, int r, T val) {
        Range(root, 0, size, l, r, val);
    }
    void clear() { del(root), root = new node(); }
    void resize(int sz) { size = sz; }
};