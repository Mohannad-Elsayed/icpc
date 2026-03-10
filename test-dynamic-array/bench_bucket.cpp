#include <bits/stdc++.h>
using namespace std;

template<class T>
struct BucketList {
    int siz = 0;
    vector<vector<T>> a;
    int SR;
    BucketList(int sr) : SR(sr) {}

    void push_back(T x) {
        siz++;
        if (a.empty()) a.emplace_back();
        a.back().push_back(x);
        if ((int)a.back().size() > (int)a.size() * SR) {
            int h = a.back().size() / 2;
            vector<T> nb(a.back().begin() + h, a.back().end());
            a.back().resize(h);
            a.push_back(move(nb));
        }
    }

    void insert(int i, T x) {
        if (siz == 0) { push_back(x); return; }
        siz++;
        for (int bi = 0; bi < (int)a.size(); bi++) {
            if (i <= (int)a[bi].size()) {
                a[bi].insert(a[bi].begin() + i, x);
                if ((int)a[bi].size() > (int)a.size() * SR) {
                    int h = a[bi].size() / 2;
                    vector<T> nb(a[bi].begin() + h, a[bi].end());
                    a[bi].resize(h);
                    a.emplace(a.begin() + bi + 1, move(nb));
                }
                return;
            }
            i -= a[bi].size();
        }
    }

    void erase(int i) {
        siz--;
        for (int bi = 0; bi < (int)a.size(); bi++) {
            if (i < (int)a[bi].size()) {
                a[bi].erase(a[bi].begin() + i);
                if (a[bi].empty()) a.erase(a.begin() + bi);
                return;
            }
            i -= a[bi].size();
        }
    }

    T& access(int i) {
        for (auto& b : a) {
            if (i < (int)b.size()) return b[i];
            i -= b.size();
        }
        __builtin_unreachable();
    }

    int size() { return siz; }
};

int main(int argc, char** argv) {
    int N = atoi(argv[1]), Q = atoi(argv[2]), tt = atoi(argv[3]), sr = atoi(argv[4]);
    BucketList<int> ds(sr);
    int pp = (tt == 1) ? N + Q : N;
    for (int i = 0; i < pp; i++) ds.push_back(i);

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
