vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

map<int, int> factorlg(int _n){
    map<int, int> fac;
    while(smallest_factor[_n]){
        fac[smallest_factor[_n]]++;
        _n /= smallest_factor[_n];
    }
    return fac;
}

map<ll, int> factor(ll _n){
    map<ll, int> fac;
    for (int i = 0; (ll)primes[i] * primes[i] <= _n; i++)
        while(_n % primes[i] == 0)
            fac[primes[i]]++, _n /= primes[i];
    if (_n != 1)
        fac[_n]++;
    return fac;
}