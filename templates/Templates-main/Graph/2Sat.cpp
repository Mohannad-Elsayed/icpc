// usage: for negating varaibles pass ~x
// -1-2*x transforms ~x into 2*x + 1
struct TwoSat {
    int N;
    vpi edges;

    void init(int _N) {
        N = _N;
    }

    int addVar() { return N++; }

    // x or y, edges will be refined in the end
    void either(int x, int y) {
        x = max(2 * x, -1 - 2 * x);
        y = max(2 * y, -1 - 2 * y);
        edges.pb({x, y});
    }

    void implies(int x, int y) {
        either(~x, y);
    }

    void must(int x) {
        either(x, x);
    }

    void XOR(int x, int y) {
        either(x, y);
        either(~x, ~y);
    }

    // void atMostOne exists in kactl
    vb solve(int _N = -1) {
        if (_N != -1) N = _N;
        SCC scc;
        scc.init(2 * N);
        for (auto e:edges) {
            scc.addEdge(e.F ^ 1, e.S);
            scc.addEdge(e.S ^ 1, e.F);
        }
        scc.gen();
        for (int i = 0; i < 2 * N; ++i) {
            if (scc.compOf[i] == scc.compOf[i ^ 1])return {};
        }
        vvi comps = scc.comps;
        reverse(all(comps));
        vi compOf(2 * N);
        for (int i = 0; i < comps.size(); ++i) {
            for (auto e:comps[i])
                compOf[e] = i;
        }
        vi tmp(comps.size());
        for (int i = 0; i < comps.size(); ++i) {
            if (!tmp[i]) {
                tmp[i] = 1;
                for (auto e:comps[i])
                    tmp[compOf[e ^ 1]] = -1;
            }
        }
        vb ans(N);
        for (int i = 0; i < N; ++i)
            ans[i] = tmp[compOf[2 * i]] == 1;
        return ans;
    }
};
