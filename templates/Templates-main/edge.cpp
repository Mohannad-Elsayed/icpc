struct edge {
    int f, t, w;
    edge(int _f = -1, int _t = -1, int _w = 0) : f(_f), t(_t), w(_w) {}
    bool operator<(const edge &e) const { return w < e.w; }
    bool operator>(const edge &e) const { return w > e.w; }
};
