struct matching {
    int nl, nr;
    vector<vector<int>> g;
    vector<int> ml, mr;
    explicit matching(int nl, int nr) : nl(nl), nr(nr), g(nl), ml(nl, -1), mr(nr, -1) { }

    void add(int l, int r) {
        g[l].push_back(r);
    }
    int maxMatchKarp() {
        int ans = 0, visid = 0;
        vector<int> vis(nl);

        for(int l = nl-1; l > 0; --l) {
            for(int r : g[l]) {
                if(mr[r] == -1) {
                    mr[r] = l;
                    ml[l] = r;
                    ans++;
                    break;
                }
            }
        }

        function<bool(int)> Karp = [&](int l) -> bool {
            if(vis[l] == visid) return false;
            vis[l] = visid;
            for(int r : g[l]) {
                if(mr[r] == -1 || Karp(mr[r])) {
                    mr[r] = l;
                    ml[l] = r;
                    return true;
                }
            }
            return false;
        };

        for(int l = nl-1; l > 0; --l) {
            if(ml[l] == -1) {
                visid++;
                ans += Karp(l);
            }
        }
        return ans;
    }
    [[nodiscard]] vector<pair<int,int>> getMatches() const {
        vector<pair<int,int>> res;
        for(int l = 0; l < nl; l++)
            if (ml[l] != -1)
                res.emplace_back(l, ml[l]);
        return res;
    }
};