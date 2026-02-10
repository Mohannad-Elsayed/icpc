constexpr std::string Base64Encode(const std::string& x) {
    std::string res;
    int p = 0;
    for (size_t i = 0; i < x.length(); i += 6) {
        std::string tmp = x.substr(i, 6);
        if (tmp.length() < 6) p = 6 - tmp.length(), tmp += std::string(p, '0');
        int c = std::stoi(tmp, nullptr, 2);
        res.push_back(c < 26 ? 'A' + c : c < 52 ? 'a' + (c - 26) : c < 62 ? '0' + (c - 52) : c == 62 ? '+' : '/');
    }
    while (res.length() % 4 != 0) res.push_back('=');
    res = (char) ('0' + p) + res;
    return res;
}
constexpr std::string Base64Decode(std::string x) {
    std::string res;
    int p = x[0] - '0';
    while (x.back() == '=' || x.back() == '\n') x.pop_back();
    for (size_t i = 1; i != x.length(); ++i) {
        char c = x[i];
        if (c == '\n') continue;
        int n = c == '+' ? 62 : c == '/' ? 63 : c >= 'a' ? c - 'a' + 26 : c >= 'A' ? c - 'A' : c - '0' + 52;
        std::string tmp;
        while (n != 0) {
            tmp.push_back('0' + (n & 1));
            n >>= 1;
        }
        std::reverse(tmp.begin(), tmp.end());
        if (tmp.length() < 6) res += std::string(6 - tmp.length(), '0');
        res += tmp;
    }
    while (p--) res.pop_back();
    return res;
}