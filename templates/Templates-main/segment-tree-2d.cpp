struct info {
    ll sum;
    info(ll x) {
        sum = x;
    }
    info() { // default value
        sum = 0;
    }
    friend info operator+(const info &l, const info &r) {
        info ret;
        ret.sum = l.sum + r.sum;
        return ret;
    }
};
template<class info>
class segmentTree2d {
    int nx, ny;
    vector<vector<info>> tree;
    static info defaultVal;
  public:
    explicit segmentTree2d(int n, int m)
      : nx(n), ny(m),
        tree((nx<<1), vector<info>(ny<<1, defaultVal))
    {}

    template<class U>
    explicit segmentTree2d(const vector<vector<U>> &a) {
        nx = int(a.size());
        ny = nx? int(a[0].size()) : 0;
        tree.assign((nx<<1), vector<info>(ny<<1, defaultVal));
        for(int i = 0; i < nx; i++){
            for(int j = 0; j < ny; j++)
                tree[i+nx][j+ny] = info(a[i][j]);
            for(int y = ny-1; y > 0; y--)
                tree[i+nx][y] = tree[i+nx][y<<1] + tree[i+nx][y<<1|1];
            
        }

        for(int x = nx-1; x > 0; x--)
            for(int y = 0; y < (ny<<1); y++)
                tree[x][y] = tree[x<<1][y] + tree[x<<1|1][y];
    }

    void set(int i, int j, info v) {
        if(i<0||i>=nx||j<0||j>=ny) return;
        int x = i + nx, y = j + ny;
        tree[x][y] = v;
        for(int yy = y>>1; yy > 0; yy >>= 1)
            tree[x][yy] = tree[x][yy<<1] + tree[x][yy<<1|1];
        for(int xx = x>>1; xx > 0; xx >>= 1) {
            tree[xx][y] = tree[xx<<1][y] + tree[xx<<1|1][y];
            for(int yy = y>>1; yy > 0; yy >>= 1)
                tree[xx][yy] = tree[xx][yy<<1] + tree[xx][yy<<1|1];
        }
    }

    info get(int x1, int y1, int x2, int y2) {
        if(nx==0||ny==0) return defaultVal;
        x1 = max(x1, 0); y1 = max(y1, 0);
        x2 = min(x2, nx-1); y2 = min(y2, ny-1);
        if(x1 > x2 || y1 > y2) return defaultVal;

        info resL = defaultVal, resR = defaultVal;
        int l = x1 + nx, r = x2 + nx + 1;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resL = resL + queryY(l++, y1, y2);
            if(r & 1) resR = queryY(--r, y1, y2) + resR;
        }
        return resL + resR;
    }

  private:
    info queryY(int nodeX, int y1, int y2) const {
        info resL = defaultVal, resR = defaultVal;
        int l = y1 + ny, r = y2 + ny + 1;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resL = resL + tree[nodeX][l++];
            if(r & 1) resR = tree[nodeX][--r] + resR;
        }
        return resL + resR;
    }
};

template<class info>
info segmentTree2d<info>::defaultVal = info();