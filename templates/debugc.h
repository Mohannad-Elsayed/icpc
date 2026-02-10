template<typename A, typename B> string to_string(pair<A,B> p);
template<typename Container> auto to_string(const Container& c) 
    -> decltype(c.begin(), c.end(), string());
template<typename T, size_t N> 
    string to_string(const array<T, N>& a);

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "T" : "F"; }
string to_string(string s) { return "\""+s+"\""; }
string to_string(const char* s) { return string(s); }

template<typename Container>
auto to_string(const Container& c) 
    -> decltype(c.begin(), c.end(), string()) {
    string s="{";
    bool first = true;
    for(const auto& item : c) {
        if(!first) s += ", ";
        s += to_string(item);
        first = false;
    }
    return s+"}";
}

template<typename T, size_t N> 
string to_string(const array<T, N>& a) {
    string s="{";
    for(size_t i=0;i<N;i++) s+=(i?", ":"")+to_string(a[i]);
    return s+"}";
}

template<typename A, typename B> string to_string(pair<A,B> p) {
    return "("+to_string(p.first)+", "+to_string(p.second)+")";
}

void debug_out() { cout << "\n"; }
template<typename H, typename... T>
void debug_out(H&& h, T&&... t) {
    cout << " " << to_string(std::forward<H>(h));
    debug_out(std::forward<T>(t)...);
}
#define print(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)