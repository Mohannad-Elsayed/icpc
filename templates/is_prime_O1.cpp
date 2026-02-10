#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

#pragma region fast_is_prime
const int MAXN = 200010;
template<int N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (int i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (int i = 2; i < N; i++) if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
};
template<Sieve<MAXN> s>
struct SieveWrapper {
    static bool get(int n) {
        return s.is_prime[n];
    }
};
bool fast_is_prime(int n) {
    return SieveWrapper<Sieve<MAXN>{}>::get(n);
}
#pragma endregion fast_is_prime


bool slow_is_prime(int n) {
    return (Sieve<MAXN>{}).is_prime[n];
}


const int reps = 10000;
int main() {
    vector<int> numbers(reps);
    for (int i = 0; i < reps; i++) {
        numbers[i] = rand() % MAXN;
    }

    int ans = 0;
    auto t1 = chrono::high_resolution_clock::now();
    auto t2 = chrono::high_resolution_clock::now();

    // for (auto &n : numbers) {
    //     ans += slow_is_prime(n);
    // }
    // auto t2 = chrono::high_resolution_clock::now();
    // cout << "Runtime ans: " << ans << ". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;

    ans = 0;
    t1 = chrono::high_resolution_clock::now();
    for (auto &n : numbers) {
        ans += fast_is_prime(n);
    }
    t2 = chrono::high_resolution_clock::now();
    cout << "Compiletime ans: " << ans << ". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
}