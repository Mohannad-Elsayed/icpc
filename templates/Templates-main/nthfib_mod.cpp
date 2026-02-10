pair<Mint, Mint> fib (ll n) { // return f_n, f_n+1
    if (n == 0)
        return {Mint(0), Mint(1)};
    auto p = fib(n >> 1);
    Mint c = p.first * (2 * p.second - p.first);
    Mint d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

pair<ll, ll> fib(ll n, ll MOD) { // return f_n, f_n+1
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1, MOD);
    ll c = (p.first * (2 * p.second % MOD - p.first + MOD)) % MOD;
    ll d = (p.first * p.first % MOD + p.second * p.second % MOD) % MOD;
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}