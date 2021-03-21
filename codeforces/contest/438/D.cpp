#include <bits/stdc++.h>
using namespace std;
#define LL        long long
#define Ulong     unsigned long long
#define REP(i, n) for (long long i = 0; i < n; i++)
#define mp        make_pair
#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define PI        acos(-1.0)
#define EPS       1e-14
#define F         first
#define S         second
#define gc        getchar_unlocked
#define di(x) \
    int x;    \
    input(x)
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
#define lc           ((n) << 1)
#define rc           ((n) << 1 | 1)
#define mid          (b + e) / 2
#define db(x)        cout << #x << " -> " << x << endl
#define nl           cout << endl
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
template <class T> inline void input(T &x) {
    register char c = gc();
    x               = 0;
    int neg         = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = gc())
        ;
    if (c == '-') {
        neg = 1;
        c   = gc();
    }
    for (; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
    if (neg) x = -x;
}

const int N = 4e5 + 5;
using PII   = pair<int, int>;
set<PII> seg[N];
long long sum[N];
int a[N];

void build(int n, int b, int e) {
    if (b == e) {
        sum[n] = a[b];
        seg[n].insert(make_pair(a[b], b));
        return;
    }
    build(lc, b, mid);
    build(rc, mid + 1, e);
    for (int i = b; i <= e; i++)
        sum[n] += a[i], seg[n].insert(make_pair(a[i], i));
}

void update(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
        set<PII>::iterator ptr = seg[n].lower_bound(make_pair(x, -1));
        vector<PII> ins, del;
        while (ptr != seg[n].end()) {
            sum[n] += (ptr->first % x) - ptr->first;
            del.push_back(*ptr);
            a[ptr->second] = ptr->first % x;
            ins.push_back(make_pair(ptr->first % x, ptr->second));
            ptr++;
        }
        for (PII d : del) seg[n].erase(d);
        for (PII i : ins) seg[n].insert(i);
        return;
    }
    update(lc, b, mid, i, j, x);
    update(rc, mid + 1, e, i, j, x);
    sum[n] = sum[lc] + sum[rc];
}

void pointUpdate(int n, int b, int e, int pos, int k) {
    if (b > pos || e < pos) return;
    seg[n].erase(make_pair(a[pos], pos));
    seg[n].insert(make_pair(k, pos));
    sum[n] += k - a[pos];
    if (b == e) {
        a[pos] = k;
        return;
    }
    pointUpdate(lc, b, mid, pos, k);
    pointUpdate(rc, mid + 1, e, pos, k);
}

long long query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return sum[n];
    return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    in2(n, m);
    for (int i = 1; i <= n; i++) in(a[i]);
    while (m--) {
        int t, l, r, x;
        in(t);
        if (t == 1) {
            in2(l, r);
            printf("%lld\n", query(1, 1, n, l, r));
        } else if (t == 2) {
            in3(l, r, x);
            update(1, 1, n, l, r, x);
        } else if (t == 3) {
            in2(l, x);
            pointUpdate(1, 1, n, l, x);
        }
    }

    return 0;
}
