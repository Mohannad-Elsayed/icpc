template<typename T = int>
struct sparse2d {
    int Log, n, m;
    vector<vector<vector<T>>> table;
    function<T(T, T)> merge;

    template<class U>
    explicit sparse2d(const vector<vector<T>>& arr, U merge)
      : merge(merge),
        n((int)arr.size()),
        m((int)arr[0].size()),
        Log(__lg(max(n, m)) + 1)
    {
        table.resize(Log+1);
        for (int k = 0; k <= Log; ++k) {
            int H = n - (1<<k) + 1;
            int W = m - (1<<k) + 1;
            if (H > 0 && W > 0)
                table[k].assign(H, vector<T>(W));
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                table[0][i][j] = arr[i][j];

        for (int k = 1; k <= Log; ++k) {
            int H = n - (1<<k) + 1;
            int W = m - (1<<k) + 1;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    T a = table[k-1][i][j];
                    T b = table[k-1][i + (1<<(k-1))][j];
                    T c = table[k-1][i][j + (1<<(k-1))];
                    T d = table[k-1][i + (1<<(k-1))][j + (1<<(k-1))];
                    table[k][i][j] = merge( merge(a, b), merge(c, d) );
                }
            }
        }
    }

    T query(int x1, int y1, int x2, int y2) {
        int h = x2 - x1 + 1;
        int w = y2 - y1 + 1;
        int k = __lg(min(h, w));
        T a = table[k][x1][y1];
        T b = table[k][x2 - (1<<k) + 1][y1];
        T c = table[k][x1][y2 - (1<<k) + 1];
        T d = table[k][x2 - (1<<k) + 1][y2 - (1<<k) + 1];
        return merge( merge(a, b), merge(c, d) );
    }
};