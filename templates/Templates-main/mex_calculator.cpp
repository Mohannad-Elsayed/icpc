class mex_calculator {
    map<int, int> count;
    set<int> missing;
public:
    mex_calculator(const vector<int>& arr, int upper_bound) { // n log n
        for (int x : arr)
            count[x]++;
        for (int i = 0; i <= upper_bound + 1; ++i)
            if (count[i] == 0)
                missing.insert(i);
    }
    void insert(int x) { // log
        count[x]++;
        if (count[x] == 1)
            missing.erase(x);
    }
    void remove(int x) { // log
        if (count[x] == 0) return;
        count[x]--;
        if (count[x] == 0)
            missing.insert(x);
    }
    int get_mex() { // 1
        return *missing.begin();
    }
};