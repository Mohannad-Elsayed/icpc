istream& operator>>(istream& is, __int128_t& v) {
    string s; is >> s; v = 0;
    for (char c : s) if (isdigit(c)) v = v * 10 + c - '0';
    if (s[0] == '-') v = -v;
    return is;
}
ostream& operator<<(ostream& os, __int128_t v) {
    if (!v) return os << "0";
    if (v < 0) os << '-', v = -v;
    string s;
    while (v) s += '0' + v % 10, v /= 10;
    reverse(s.begin(), s.end());
    return os << s;
}