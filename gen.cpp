#include "testlib.h"
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_SUM_N = 300000;
const long long MIN_VAL = -1'000'000'000LL;
const long long MAX_VAL = 1'000'000'000LL;

// Generates a single testcase based on the specified edge-case type
void generateTestCase(int n, int type) {
    long long targetSum;
    vector<long long> a(n + 1);

    // 1. Generate Values and Target Sum
    if (type == 3) {
        // Edge Case: All nodes are 0, target is 0. Maximizes valid paths.
        targetSum = 0;
        for (int i = 1; i <= n; i++) a[i] = 0;
    } else if (type == 4) {
        // Edge Case: Target is reached exactly at the root
        for (int i = 1; i <= n; i++) a[i] = rnd.next(MIN_VAL, MAX_VAL);
        targetSum = a[1];
    } else if (type == 5) {
        // Edge Case: Small values to force paths to repeatedly cross the targetSum
        targetSum = rnd.next(-5LL, 5LL);
        for (int i = 1; i <= n; i++) a[i] = rnd.next(-2LL, 2LL);
    } else {
        // Standard Case: Purely random
        targetSum = rnd.next(-10'000'000'000'000LL, 10'000'000'000'000LL);
        for (int i = 1; i <= n; i++) a[i] = rnd.next(MIN_VAL, MAX_VAL);
    }

    println(n, targetSum);

    // Print node values
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    if (n == 1) return;

    // 2. Generate Tree Topology
    // We shuffle node labels (2 to n) to prevent predictable structures, keeping root at 1
    vector<int> perm(n + 1);
    perm[1] = 1;
    for (int i = 2; i <= n; i++) perm[i] = i;
    shuffle(perm.begin() + 2, perm.end());

    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; i++) {
        int parent_index;

        if (type == 1) {
            // Edge Case: Line Graph (Max depth, tests recursion limits)
            parent_index = i - 1;
        } else if (type == 2) {
            // Edge Case: Star Graph (Max branching factor)
            parent_index = 1;
        } else {
            // Standard Case: Random Tree
            parent_index = rnd.next(1, i - 1);
        }

        int u = perm[parent_index];
        int v = perm[i];

        // Randomly swap u and v to prevent u always being closer to the root
        if (rnd.next(2)) swap(u, v);
        edges.push_back({u, v});
    }

    // Shuffle the order the edges are printed
    shuffle(edges.begin(), edges.end());

    for (auto edge : edges) {
        println(edge.first, edge.second);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Generator Flags
    int t = opt<int>("t", rnd.next(1, 10)); // Number of test cases
    int sum_n = opt<int>("sumn", MAX_SUM_N); // Total N across all test cases
    int type = opt<int>("type", 0); // Edge case flag (0 by default)

    println(t);

    // Randomly partition 'sum_n' into 't' valid test cases (each n >= 1)
    vector<int> ns(t, 1);
    int remaining = sum_n - t;
    for (int i = 0; i < remaining; i++) {
        ns[rnd.next(t)]++;
    }

    for (int i = 0; i < t; i++) {
        generateTestCase(ns[i], type);
    }

    return 0;
}