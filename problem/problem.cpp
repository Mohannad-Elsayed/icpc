#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

map<long long, long long> memo_opt[35];
map<long long, long long> memo_truth[35];
struct tototo {
    int n, k;
};
// ---------------------------------------------------------
// SOURCE OF TRUTH: Unbounded DP (Checks EVERY path)
// ---------------------------------------------------------
long long run_truth(long long n, long long k, int level) {
    if (n == 0) return 0;
    if (k == 0) return 1e18;
    if (memo_truth[level].count(n)) return memo_truth[level][n];

    long long max_c = n / k;
    long long ans = 1e18;

    // Loop through ALL possible subtractions, no bounds.
    for (long long c = 0; c <= max_c; ++c) {
        long long rem = n - c * k;
        if (rem == 0) ans = min(ans, c);
        else if (rem > 0) {
            long long sub = run_truth(rem, k / 2, level + 1);
            if (sub < 1e18) ans = min(ans, c + 1 + sub);
        }
    }
    return memo_truth[level][n] = ans;
}

// ---------------------------------------------------------
// YOUR ALGORITHM: Bounded DP (Checks only near 0 and max_c)
// ---------------------------------------------------------
long long run_opt(long long n, long long k, int level) {
    if (n == 0) return 0;
    if (k == 0) return 1e18;
    if (memo_opt[level].count(n)) return memo_opt[level][n];

    long long max_c = n / k;
    long long ans = 1e18;

    for (long long c = max_c; c >= max(0LL, max_c - 3LL); --c) {
        long long rem = n - c * k;
        if (rem == 0) ans = min(ans, c);
        else if (rem > 0) {
            long long sub = run_opt(rem, k / 2, level + 1);
            if (sub < 1e18) ans = min(ans, c + 1 + sub);
        }
    }

    for (long long c = 0; c <= min(max_c, 3LL); ++c) {
        long long rem = n - c * k;
        if (rem == 0) ans = min(ans, c);
        else if (rem > 0) {
            long long sub = run_opt(rem, k / 2, level + 1);
            if (sub < 1e18) ans = min(ans, c + 1 + sub);
        }
    }
    return memo_opt[level][n] = ans;
}

// ---------------------------------------------------------
// FUZZER
// ---------------------------------------------------------
int main() {
    mt19937_64 rng(1337); // Seeded random for reproducibility
    
    // We limit max N and K to 50,000 for the fuzzer so the Unbounded DP 
    // doesn't take too long on cases like n=100000, k=1.
    uniform_int_distribution<long long> dist_val(1, 5000); 
    
    int tests = 100;
    cout << "Running " << tests << " randomized stress tests...\n";

    for (int t = 1; t <= tests; ++t) {
        long long n = dist_val(rng);
        long long k = dist_val(rng);

        // Clear memos
        for (int i = 0; i < 35; ++i) {
            memo_truth[i].clear();
            memo_opt[i].clear();
        }

        long long raw_truth = run_truth(n, k, 0);
        long long raw_opt = run_opt(n, k, 0);

        long long ans_truth = (raw_truth >= 1e18) ? -1 : raw_truth;
        long long ans_opt = (raw_opt >= 1e18) ? -1 : raw_opt;

        if (ans_truth != ans_opt) {
            cout << "\n[MISMATCH CAUGHT]\n";
            cout << "N = " << n << ", K = " << k << "\n";
            cout << "Truth (Unbounded): " << ans_truth << " | Optimized (Bounded): " << ans_opt << "\n";
            return 0;
        }

        if (t % 1000 == 0) cout << "Passed " << t << " / " << tests << " tests...\n";
    }

    cout << "\nSUCCESS: The optimized algorithm is rock solid.\n";
    return 0;
}