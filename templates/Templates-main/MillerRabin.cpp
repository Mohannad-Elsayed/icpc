namespace Primes {
    ll binpower(ll base, ll e, ll mod) {
        ll result = 1;
        base %= mod;
        while (e) {
            if (e & 1)
                result = (__uint128_t)result * base % mod;
            base = (__uint128_t)base * base % mod;
            e >>= 1;
        }
        return result;
    }

    bool check_composite(ll n, ll a, ll d, int s) {
        ll x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (__uint128_t)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };

    bool MillerRabin(long long n) {
        if (n < 2)
            return false;
            
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for (auto a : primes)
            if (n % a == 0)
                return false;
        
        int r = 0;
        long long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }

        for (int a : primes) {
            if (n == a)
                return true;
            if (check_composite(n, a, d, r))
                return false;
        }
        return true;
    }
}