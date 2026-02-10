template<typename A, typename B> string to_string(pair<A,B> p);
template<typename Container>
auto to_string(const Container& c) -> decltype(c.begin(), c.end(), string());
template<typename T, size_t N> 
string to_string(const array<T, N>& a);

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "T" : "F"; }
string to_string(string s) { return "\""+s+"\""; }
template<typename A, typename B> string to_string(pair<A,B> p) {
    return "("+to_string(p.first)+", "+to_string(p.second)+")";
}
string to_string(const char* s) { return string(s); }

template<typename Container>
auto to_string(const Container& c) -> decltype(c.begin(), c.end(), string()) {
    string s="{";
    bool first = true;
    for(const auto& item : c) {
        if(!first) s += ", ";
        s += to_string(item);
        first = false;
    }
    return s+"}";
}

// helper to unpack the tuple
template<std::size_t I = 0, typename... Ts>
typename std::enable_if<I == sizeof...(Ts), void>::type
_tuple_to_string(const std::tuple<Ts...>&, std::string&){}

template<std::size_t I = 0, typename... Ts>
typename std::enable_if<I < sizeof...(Ts), void>::type
_tuple_to_string(const std::tuple<Ts...>& t, std::string& s) {
    if (I) s += ", ";
    s += to_string(std::get<I>(t));
    _tuple_to_string<I + 1>(t, s);
}

// actual overload
template<typename... Ts>
std::string to_string(const std::tuple<Ts...>& t) {
    std::string s = "(";
    _tuple_to_string(t, s);
    return s + ")";
}

template<typename T, size_t N> 
string to_string(const array<T, N>& a) {
    string s="{";
    for(size_t i=0;i<N;i++) s+=(i?", ":"")+to_string(a[i]);
    return s+"}";
}

template<typename T, size_t N> 
string to_string(const T (&a)[N]) {
    string s="{";
    for(size_t i=0;i<N;i++) s+=(i?", ":"")+to_string(a[i]);
    return s+"}";
}

template<size_t N> string to_string(bitset<N> b) {
    return to_string(b.to_string());
}

void debug_out() { cout << "\n"; }

template<typename H, typename... T>
void debug_out(H&& h, T&&... t) {
    cout << " " << to_string(std::forward<H>(h));
    debug_out(std::forward<T>(t)...);
}
#define print(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
