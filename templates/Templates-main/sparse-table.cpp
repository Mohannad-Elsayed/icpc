template<typename T>
struct sparse{
    int Log, n;
    vector<vector<T>> table;
    function<T(T, T)> merge;
    template<class U>
    explicit sparse(vector<T> arr, U merge) : 
      merge(merge), 
      n((int)arr.size()), 
      Log(__lg(arr.size()) + 1), 
      table(Log, vector<T>(n)) 
    
    {
        table[0] = arr;
        for(int l = 1; l < Log; l++) {
            for(int i = 0; i + (1 << (l - 1)) < n; i++) {
                table[l][i] = merge(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }
    T query(int l, int r) {
        if(l > r) return {};
        int len = __lg(r - l + 1);
        return merge(table[len][l], table[len][r - (1 << len) + 1]);
    }
};