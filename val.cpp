#include "testlib.h"

using namespace std;
const int N = 300'000;
const int AI = 300'000;
const int T = 10'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read number of test cases
    int t = inf.readInt(1, T, "t");
    inf.readEoln();

    long long sum_n = 0;
    for (int tt = 1; tt <= t; tt++) {
        setTestCase(tt);

        // Read N
        int n = inf.readInt(1, N, "n_" + to_string(tt));
        inf.readEoln();

        inf.readInts(n, 1, AI, "ai");
        inf.readEoln();

        sum_n += n;
        ensuref(sum_n <= N, "Sum of n across all test cases cannot exceed %d.", N);
    }

    inf.readEof();
    return 0;
}