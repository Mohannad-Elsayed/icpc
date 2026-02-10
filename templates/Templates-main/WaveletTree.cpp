struct WaveletTree {
    int lo, hi;
    WaveletTree *l = nullptr, *r = nullptr;
    std::vector<int> b;

    // Constructor for the main call
    // Takes a vector of integers, and the min/max values in it.
    // The vector should be 1-indexed for the queries to work as a[l...r].
    WaveletTree(std::vector<int>& a, int x, int y) {
        lo = x, hi = y;

        if (lo == hi || a.empty()) return;

        int mid = lo + (hi - lo) / 2;
        
        b.reserve(a.size() + 1);
        b.push_back(0);
        for (int val : a) {
            b.push_back(b.back() + (val <= mid));
        }

        auto pivot = std::stable_partition(a.begin(), a.end(), [mid](int val) {
            return val <= mid;
        });

        std::vector<int> left_half(a.begin(), pivot);
        std::vector<int> right_half(pivot, a.end());

        l = new WaveletTree(left_half, lo, mid);
        r = new WaveletTree(right_half, mid + 1, hi);
    }

    ~WaveletTree() {
        delete l;
        delete r;
    }

    // kth smallest element in [l, r] (1-based)
    int kth(int l_idx, int r_idx, int k) {
        if (l_idx > r_idx) return 0;
        if (lo == hi) return lo;

        int in_left = b[r_idx] - b[l_idx - 1];
        int lb = b[l_idx - 1]; 
        int rb = b[r_idx];     

        if (k <= in_left) return this->l->kth(lb + 1, rb, k);
        return this->r->kth(l_idx - lb, r_idx - rb, k - in_left);
    }

    // count of numbers in [l, r] Less than or equal to k
    int LTE(int l_idx, int r_idx, int k) {
        if (l_idx > r_idx || k < lo) return 0;
        if (hi <= k) return r_idx - l_idx + 1;

        int lb = b[l_idx - 1];
        int rb = b[r_idx];
        return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l_idx - lb, r_idx - rb, k);
    }

    // count of numbers in [l, r] equal to k
    int count(int l_idx, int r_idx, int k) {
        if (l_idx > r_idx || k < lo || k > hi) return 0;
        if (lo == hi) return r_idx - l_idx + 1;

        int mid = lo + (hi - lo) / 2;
        int lb = b[l_idx - 1];
        int rb = b[r_idx];

        if (k <= mid) return this->l->count(lb + 1, rb, k);
        return this->r->count(l_idx - lb, r_idx - rb, k);
    }
};


