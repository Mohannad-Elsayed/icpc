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
    int x = mt19937(random_device()())() % 100;
    printf("%d\n", x);
    freopen("out", "wt", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        if (t) cout << '\n';
    }
    return 0;
}


template<class T>
struct BucketList {
    int siz = 0;
    vector<vector<T> > a;
    static constexpr int SPLIT_RATIO = 28;

    void insert(int i, T x) {
        if (siz == 0) {
            siz = 1;
            a = {{x}};
            return;
        }
        siz++;
        for (ll bi = 0; bi < size(a); bi++) {
            auto &bucket = a[bi];
            if (i <= size(bucket)) {
                bucket.insert(begin(bucket) + i, x);
                if (size(bucket) > size(a) * SPLIT_RATIO) {
                    auto L = end(bucket) - size(bucket) / 2, R = end(bucket);
                    a.emplace(begin(a) + bi + 1, L, R);
                    // bucket might be broken
                    a[bi].erase(L, R);
                }
                return;
            }
            i -= size(bucket);
        }
    }

    void erase(int i) {
        siz--;
        for (int bi = 0; bi < size(a); bi++) {
            auto& bucket = a[bi];
            if (i < size(bucket)) {
                bucket.erase(begin(bucket) + i);
                if (bucket.empty()) a.erase(begin(a) + bi);
                return;
            }
            i -= size(bucket);
        }
    }

    T& access(int i) {
        for (auto& bucket : a) {
            if (i < size(bucket)) return bucket[i];
            i -= size(bucket);
        }
        assert(false);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
struct DynArray {
    struct Node {
        T val; int pri, sz;
        Node *l, *r;
        Node(const T& v) : val(v), pri(rng()), sz(1), l(0), r(0) {}
    };

    Node* root = 0;

    static int sz(Node* t) { return t ? t->sz : 0; }
    static void pull(Node* t) { if (t) t->sz = 1 + sz(t->l) + sz(t->r); }

    static void split(Node* t, int k, Node*& l, Node*& r) {
        if (!t) { l = r = 0; return; }
        if (sz(t->l) < k) {
            split(t->r, k - sz(t->l) - 1, t->r, r);
            l = t;
        } else {
            split(t->l, k, l, t->l);
            r = t;
        }
        pull(t);
    }

    static void merge(Node*& t, Node* l, Node* r) {
        if (!l || !r) { t = l ? l : r; return; }
        if (l->pri > r->pri) {
            merge(l->r, l->r, r);
            t = l;
        } else {
            merge(r->l, l, r->l);
            t = r;
        }
        pull(t);
    }

    void insert(int pos, const T& val) {
        Node *l, *r;
        split(root, pos, l, r);
        Node* nd = new Node(val);
        merge(l, l, nd);
        merge(root, l, r);
    }

    void erase(int pos) {
        Node *l, *m, *r;
        split(root, pos, l, m);
        split(m, 1, m, r);
        delete m;
        merge(root, l, r);
    }

    T& access(int pos) {
        Node* t = root;
        while (true) {
            int left = sz(t->l);
            if (pos < left) t = t->l;
            else if (pos == left) return t->val;
            else { pos -= left + 1; t = t->r; }
        }
    }

    int size() { return sz(root); }
};

void solve() {
    int n;
    cin >> n;
    BucketList<int> arr;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        arr.insert(--x, i);
    }
    for (int i = 0; i < n; i++) {
        cout << arr.access(i) << ' ';
    }
}
