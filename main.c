#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define N 200200

int freq[1000100], arr[N], n, q;
long long Ans[N];
long long cans = 0;

typedef struct Q {
    int l, r, idx;
    unsigned long long ord;   // Hilbert order (64-bit)
} query;

/* Hilbert order (returns unsigned long long).
   pow = number of bits per coordinate; for n <= 200200, pow = 21 is safe */
unsigned long long hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0ULL;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    unsigned long long subSquareSize = 1ULL << (2 * pow - 2);
    unsigned long long ans = (unsigned long long)seg * subSquareSize;
    unsigned long long add = hilbertOrder(nx, ny, pow - 1, nrot);
    if (seg == 1 || seg == 2) ans += add;
    else ans += (subSquareSize - add - 1);
    return ans;
}

/* Stable LSD radix sort for 64-bit keys (8 passes of 8 bits).
   Sorts array `a` of length n in-place using allocated buffer tmp (size n). */
void radix_sort_queries(query *a, int n) {
    if (n <= 1) return;
    query *tmp = (query *)malloc(sizeof(query) * n);
    if (!tmp) return; // fallback: leave unsorted (shouldn't happen in contest).
    const int RAD = 256;
    unsigned int cnt[RAD];
    query *from = a, *to = tmp;

    for (int pass = 0; pass < 8; ++pass) {
        memset(cnt, 0, sizeof(cnt));
        int shift = pass * 8;
        // count
        for (int i = 0; i < n; ++i) {
            unsigned int key = (unsigned int)((from[i].ord >> shift) & 0xFFULL);
            cnt[key]++;
        }
        // prefix sum
        unsigned int sum = 0;
        for (int i = 0; i < RAD; ++i) {
            unsigned int t = cnt[i];
            cnt[i] = sum;
            sum += t;
        }
        // place (stable) -- write to `to`
        for (int i = 0; i < n; ++i) {
            unsigned int key = (unsigned int)((from[i].ord >> shift) & 0xFFULL);
            to[cnt[key]++] = from[i];
        }
        // swap buffers
        query *tmp_p = from;
        from = to;
        to = tmp_p;
    }

    // After 8 passes, `from` points to the sorted array.
    if (from != a) {
        memcpy(a, from, sizeof(query) * n);
    }
    free(tmp);
}

void add(int i) {
    cans -= 1LL * freq[arr[i]] * freq[arr[i]] * arr[i];
    freq[arr[i]]++;
    cans += 1LL * freq[arr[i]] * freq[arr[i]] * arr[i];
}

void rem(int i) {
    cans -= 1LL * freq[arr[i]] * freq[arr[i]] * arr[i];
    freq[arr[i]]--;
    cans += 1LL * freq[arr[i]] * freq[arr[i]] * arr[i];
}

int main() {
    if (scanf("%d%d", &n, &q) != 2) return 0;
    for (int i = 0; i < n; i++) scanf("%d", arr + i);

    query *qr = (query *)malloc(sizeof(query) * q);
    if (!qr) return 1;

    for (int i = 0; i < q; i++) {
        scanf("%d%d", &qr[i].l, &qr[i].r);
        qr[i].l--; qr[i].r--;
        qr[i].idx = i;
        qr[i].ord = hilbertOrder(qr[i].l, qr[i].r, 21, 0);
    }

    // Radix-sort by 64-bit Hilbert key (worst-case linear)
    radix_sort_queries(qr, q);

    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        int ll = qr[i].l;
        int rr = qr[i].r;
        // printf("%d %d %d %d\n", l, r, ll, rr);
        while (l > ll) add(--l);
        while (r < rr) add(++r);
        while (l < ll) rem(l++);
        while (r > rr) rem(r--);
        Ans[qr[i].idx] = cans;
    }

    for (int i = 0; i < q; i++) printf("%lld\n", Ans[i]);

    free(qr);
    return 0;
}
