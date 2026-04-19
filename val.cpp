#include "testlib.h"
#include <vector>

using namespace std;

// DSU struct to validate that the edges form a proper tree
struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
    }
    int get(int x) {
        return (p[x] == x) ? x : (p[x] = get(p[x]));
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

const int MAX_T = 10000;
const int MAX_SUM_N = 300000;
const long long MIN_VAL = -1'000'000'000LL;
const long long MAX_VAL = 1'000'000'000LL;
const long long MIN_TS = -100'000'000'000'000LL;
const long long MAX_TS = 100'000'000'000'000LL;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, MAX_T, "t");
    inf.readEoln();

    int sum_n = 0;

    for (int test_case = 1; test_case <= t; test_case++) {
        setTestCase(test_case);

        // Read n and targetSum
        int n = inf.readInt(1, MAX_SUM_N, "n");
        inf.readSpace();
        long long targetSum = inf.readLong(MIN_TS, MAX_TS, "targetSum");
        inf.readEoln();

        // Enforce the global sum of n
        sum_n += n;
        ensuref(sum_n <= MAX_SUM_N, "Sum of n over all test cases exceeds %d", MAX_SUM_N);

        // Read the node values
        for (int i = 1; i <= n; i++) {
            inf.readLong(MIN_VAL, MAX_VAL, "a_i");
            if (i < n) {
                inf.readSpace();
            }
        }
        inf.readEoln();

        // Validate the tree structure using DSU
        DSU dsu(n);
        for (int i = 0; i < n - 1; i++) {
            int u = inf.readInt(1, n, "u");
            inf.readSpace();
            int v = inf.readInt(1, n, "v");
            inf.readEoln();

            ensuref(u != v, "Self-loop found between %d and %d", u, v);
            ensuref(dsu.unite(u, v), "Cycle found or repeated edge between %d and %d", u, v);
        }
    }

    inf.readEof();
    return 0;
}