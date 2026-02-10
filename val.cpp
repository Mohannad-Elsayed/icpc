#include "testlib.h"
#include <string>

using namespace std;
const int N = 300'000;
const int T = 10'000;
const int AI = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read number of test cases
    int t = inf.readInt(1, T, "t");
    inf.readEoln();

    long long sum_n = 0;
    for (int tt = 1; tt <= t; tt++) {
        setTestCase(tt);

        // Read N
        int n = inf.readInt(2, N, "n_" + to_string(tt));
        inf.readEoln();

        vector<int> arr = inf.readInts(n, 1, AI, "ai");
        inf.readEoln();

        for (int i = 1; i < (int) arr.size(); i++) {
            ensuref(arr[i] > arr[i-1], "Array is not strictly increasing. [a_%d = %d, a_%d = %d].", i-1, arr[i-1], i, arr[i]);
        }

        sum_n += n;
        ensuref(sum_n <= N, "Sum of n across all test cases cannot exceed %d.", N);
    }

    inf.readEof();
    return 0;
}