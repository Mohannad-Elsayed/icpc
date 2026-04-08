#include "testlib.h"

using namespace std;

const int N  = 200'000;
const int Q  = 200'000;
const int nXY = -1'000;
const int pXY = 1'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, N, "n"); inf.readSpace();
    int q = inf.readInt(1, Q, "q");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        inf.readInts(2, nXY, pXY, "xy_"+toString(i));
        inf.readEoln();
    }

    for (int i = 0; i < q; i++) {
        inf.readInt(nXY, pXY, "cx_"+toString(i)); inf.readSpace();
        inf.readInt(nXY, pXY, "cy_"+toString(i)); inf.readSpace();
        inf.readInt(1, n, "k_"+toString(i));
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}