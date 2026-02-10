template<class T>
array<ll, 3> kadane(const vector<T>& arr) {
    ll mx = LLONG_MIN, csum = 0;
    ll s = 0, e = 0, ts = 0, sz = arr.size();
    for (ll i = 0; i < sz; i++) {
        if (csum + arr[i] > arr[i]) {
            csum += arr[i];
        } else {
            csum = arr[i];
            ts = i;
        }
        if (csum > mx) {
            mx = csum;
            s = ts;
            e = i;
        }
    }
    return {mx, s, e};
}