vector<int> z_algo(string s) {
    vector<int> z(s.size());
    for(int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < s.size() && s[z[i]] == s[z[i] + i])
            z[i]++;
        if(i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}