#include "testlib.h"
#include <set>
#include <algorithm>

using namespace std;

const int MAX_NQ = 200'000;
const int MIN_C = -1000;
const int MAX_C = 1000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Command-line options with random fallbacks
    // Usage: ./gen -n 100000 -q 50000 -minc -500 -maxc 500
    int n = opt<int>("n", rnd.next(1, MAX_NQ));
    int q = opt<int>("q", rnd.next(1, MAX_NQ));
    int min_c = opt<int>("minc", MIN_C);
    int max_c = opt<int>("maxc", MAX_C);

    if (min_c > max_c) {
        swap(min_c, max_c);
    }

    // Mathematical safety: ensure 'n' does not exceed the total possible distinct coordinates
    long long max_distinct_points = 1LL * (max_c - min_c + 1) * (max_c - min_c + 1);
    if (n > max_distinct_points) {
        n = max_distinct_points;
    }

    println(n, q);

    // Generate 'n' distinctly unique student coordinates
    set<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        do {
            x = rnd.next(min_c, max_c);
            y = rnd.next(min_c, max_c);
        } while (points.count({x, y})); // Re-roll if coordinate is already taken

        points.insert({x, y});
        println(x, y);
    }

    // Generate 'q' queries
    for (int i = 0; i < q; i++) {
        int cx = rnd.next(min_c, max_c);
        int cy = rnd.next(min_c, max_c);
        int k = rnd.next(1, n); // k must be between 1 and the actual number of students
        println(cx, cy, k);
    }

    return 0;
}