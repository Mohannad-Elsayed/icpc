#include <bits/stdc++.h>
using namespace std;

mt19937 rng_treap(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct DynArray {
    struct Node {
        T val; int pri, sz;
        Node *l, *r;
        Node(const T& v) : val(v), pri(rng_treap()), sz(1), l(0), r(0) {}
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

int main(int argc, char** argv) {
    int N = atoi(argv[1]), Q = atoi(argv[2]), tt = atoi(argv[3]);

    DynArray<int> ds;
    int pp = (tt == 1) ? N + Q : N;
    for (int i = 0; i < pp; i++) ds.insert(ds.size(), i);

    mt19937 rng(42);
    auto t0 = chrono::steady_clock::now();
    int acc = 0;
    for (int i = 0; i < Q; i++) {
        if (tt == 0) {
            ds.insert(rng() % (ds.size() + 1), i);
        } else if (tt == 1) {
            ds.erase(rng() % ds.size());
        } else if (tt == 2) {
            acc += ds.access(rng() % ds.size());
        } else {
            int op = rng() % 3;
            if (op == 0 || ds.size() < 2) ds.insert(rng() % (ds.size() + 1), i);
            else if (op == 1) ds.erase(rng() % ds.size());
            else acc += ds.access(rng() % ds.size());
        }
    }
    auto t1 = chrono::steady_clock::now();
    if (acc == INT_MIN) printf("!");
    printf("%.2f", chrono::duration<double, milli>(t1 - t0).count());
}
