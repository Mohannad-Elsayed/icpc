template<typename T>
class rational {
private:
    int ctz_u128(__uint128_t u) {
        uint64_t lo = u, hi = u >> 64;
        int retval[3] = {
            __builtin_ctzll(lo),
            64 + __builtin_ctzll(hi),
            128
        };
        int idx = !lo + ((!hi) & (!lo));
        return retval[idx];
    }

    T hybrid_binary_gcd(T u, T v) {
        if (u < v) { swap(u, v); }
        if (v == 0) { return u; }
        u %= v;
        if (u == 0) { return v; }
        auto zu = ctz_u128(u);
        auto zv = ctz_u128(v);
        auto shift = min(zu, zv);
        u >>= zu;
        v >>= zv;
        do {
            T u_minus_v = u - v;
            if (u > v) { u = v, v = u_minus_v; }
            else {v = v - u; }
            v >>= ctz_u128(u_minus_v);
        } while (v != 0);
        return u << shift;
    }

    T neu, den;
    void reduce() {
        T g = hybrid_binary_gcd(neu, den);
        neu /= g;
        den /= g;
        if (den < 0) {
            neu = -neu;
            den = -den;
        }
    }

public:
    rational() : neu(0), den(1) {}
    rational(T n) : neu(n), den(1) {}
    rational(T n, T d) : neu(n), den(d) { reduce(); }
    rational& operator+=(const rational& r) {
        neu = neu * r.den + r.neu * den;
        den = den * r.den;
        reduce();
        return *this;
    }
    rational operator+(const rational& r) const {
        rational temp = *this;
        temp += r;
        return temp;
    }
    rational& operator-=(const rational& r) {
        neu = neu * r.den - r.neu * den;
        den = den * r.den;
        reduce();
        return *this;
    }
    rational operator-(const rational& r) const {
        rational temp = *this;
        temp -= r;
        return temp;
    }
    rational& operator*=(const rational& r) {
        neu *= r.neu;
        den *= r.den;
        reduce();
        return *this;
    }
    rational operator*(const rational& r) const {
        rational temp = *this;
        temp *= r;
        return temp;
    }
    rational& operator/=(const rational& r) {
        neu *= r.den;
        den *= r.neu;
        reduce();
        return *this;
    }
    rational operator/(const rational& r) const {
        rational temp = *this;
        temp /= r;
        return temp;
    }
    rational operator%(const rational& r) const {
        rational d = *this / r;
        T ip = d.neu / d.den;
        if(d.neu < 0 && d.neu % d.den != 0) ip--;
        return *this - rational(ip, 1) * r;
    }
    std::pair<T, rational> mod() const {
        T ip = neu / den;
        rational frac(neu - ip * den, den);
        return {ip, frac};
    }
    rational abs() const {
        return rational(neu < 0 ? -neu : neu, den < 0 ? -den : den);
    }
    rational& operator+=(const T& n) {
        neu += n * den;
        return *this;
    }
    rational operator+(const T& n) const {
        rational temp = *this;
        temp += n;
        return temp;
    }
    rational& operator-=(const T& n) {
        neu -= n * den;
        return *this;
    }
    rational operator-(const T& n) const {
        rational temp = *this;
        temp -= n;
        return temp;
    }
    rational& operator++() {
        *this += 1;
        return *this;
    }
    rational operator++(int) {
        rational temp = *this;
        ++(*this);
        return temp;
    }
    rational& operator--() {
        *this -= 1;
        return *this;
    }
    rational operator--(int) {
        rational temp = *this;
        --(*this);
        return temp;
    }
    rational operator+() const {
        return *this;
    }
    rational operator-() const {
        return rational(-neu, den);
    }
    bool operator==(const rational& r) const {
        return neu == r.neu && den == r.den;
    }
    bool operator!=(const rational& r) const {
        return !(*this == r);
    }
    bool operator<(const rational& r) const {
        return neu * r.den < den * r.neu;
    }
    bool operator<=(const rational& r) const {
        return neu * r.den <= den * r.neu;
    }
    bool operator>(const rational& r) const {
        return neu * r.den > den * r.neu;
    }
    bool operator>=(const rational& r) const {
        return neu * r.den >= den * r.neu;
    }
    friend std::ostream& operator<<(std::ostream& os, const rational& r) {
        os << r.neu << '/' << r.den;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, rational& r) {
        is >> r.neu >> r.den;
        r.reduce();
        return is;
    }
    friend string to_string(const rational& r) {
        return to_string(r.neu) + " / " + to_string(r.den);
    }
};