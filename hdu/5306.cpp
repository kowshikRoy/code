#include <bits/stdc++.h>
using namespace std;
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
#define lc           ((n) << 1)
#define rc           ((n) << 1 | 1)
#define mid          (b + e) / 2
#define all(v)       v.begin(), v.end()
template <class T> inline void input(T &x) {
    register char c = getchar();
    x               = 0;
    int neg         = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
        ;
    if (c == '-') {
        neg = 1;
        c   = getchar();
    }
    for (; c > 47 && c < 58; c = getchar()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}

const int N = 1000000;
int a[N];
struct seg {
    long long sum, iMax;
    vector<long long> v;
    vector<long long> pf;
    int lazy;
    bool hasLazy;
} seg[N << 2];

void up(int n) {
    seg[n].sum  = seg[lc].sum + seg[rc].sum;
    seg[n].iMax = max(seg[lc].iMax, seg[rc].iMax);
    merge(all(seg[lc].v), all(seg[rc].v), seg[n].v.begin());
    long long sum = 0;
    for (int i : seg[n].v) {
        sum += i;
        seg[n].pf.push_back(sum);
    }
}

void down(n) { auto &cur = seg[n]; }
void build(int n, int b, int e) {
    if (b == e) {
        seg[n].sum = seg[n].iMax = a[b];
        seg[n].v.push_back(a[b]);
        ;
        seg[n].lazy    = 0;
        seg[n].hasLazy = false;
    }
    build(lc, b, mid);
    build(rc, mid + 1, e);
    up(n);
}

void update(int n, int b, int e, int i, int j, int t) {
    if (b > j || e < i) return;
    down(n);
    if (b >= i && e <= j) { return; }
    update(lc, b, mmid, i, j, t);
    update(rc, mid + 1, e, i, j, t);
    up(n);
}

int main() {
    int t;
    in(t);
    while (t--) {
        int n, m;
        in2(n, m);
        for (int i = 1; i <= n; i++) in(a[i]);
        build(1, 1, n);
        while (m--) {
            int type;
            in(type);
            if (type == 0) {}
            if (type == 1) {}
            if (type == 2) {}
        }
    }
    return 0;
}
