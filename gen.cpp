#include "testlib.h"
#include <vector>

using namespace std;

const int T = 10'000;
const int N = 300'000;

const int MNAI = 1;
const int MXAI = 1'000'000'000;

int main(int argc, char* argv[]) {
    // Initialize the generator with seed from command line arguments
    registerGen(argc, argv, 1);
    // -t -n -mnn -lim
    int t = opt<int>("t", rnd.next(1, T));
    int mnn = opt<int>("mnn", 2);
    int sumn = opt<int>("n", rnd.next(mnn*t, N));
    int ap = opt<int>("ap", 0);
    int mnai = opt<int>("mnai", MNAI);
    int mxai = opt<int>("mxai", MXAI);

    println(t);
    vector<int> parts = rnd.partition(t, sumn, mnn);

    for (int tt = 1; tt <= t; tt++) {
        setTestCase(tt);

        int n = parts[tt-1];

        println(n);
        if (ap) {
            // a_1 = lim - n - 1
            // step = lim/(lim-a_1)
            vector<int> arr(1, rnd.next(1, MXAI-n-1));
            int step = (MXAI-arr.front())/(n-1);
            while ((int) arr.size() < n) {
                arr.emplace_back(arr.back() + step);
            }
            println(arr);
        } else {
            set<int> vals;
            while ((int) vals.size() < n) {
                vals.insert(rnd.next(mnai, mxai));
            }
            println(vals);
        }

    }

    return 0;
}