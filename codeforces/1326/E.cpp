#include <bits/stdc++.h>
using namespace std;
#define lc (n << 1)
#define rc (n << 1 | 1)
const int N = 3e5 + 5;

int a[N], b[N];
int T[N << 2];  // Returns the index with maximum value

void build(int n, int b, int e) {
    if (b == e) {
        T[n] = b;
        return;
    }
    int mid = b + e >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    if (a[T[lc]] < a[T[rc]]) T[n] = T[rc];
    else
        T[n] = T[lc];
}

int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return T[n];
    int mid = b + e >> 1;
    int p1 = query(lc, b, mid, i, j);
    int p2 = query(rc, mid + 1, e, i, j);
    if (a[p1] < a[p2]) return p2;
    return p1;
}

void upd(int n, int b, int e, int pos) {
    if (b > pos || e < pos) return;
    if (b == e) {
        a[b] = 0;
        return;
    }
    int mid = b + e >> 1;
    upd(lc, b, mid, pos);
    upd(rc, mid + 1, e, pos);
    if (a[T[lc]] < a[T[rc]]) T[n] = T[rc];
    else
        T[n] = T[lc];
}

int B[N];
int D[N];
void update(int B[], int x, int v) {
    while (x < N) B[x] += v, x += x & -x;
}

int query(int B[], int x) {
    int sum = 0;
    while (x > 0) sum += B[x], x -= x & -x;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++) cin >> b[i];

    int pivot = -1;
    for (int i = 1; i <= n; i++) {
        int q = query(1, 1, n, 1, n);
        int p = b[i];
        if (p > pivot) {
            q = query(1, 1, n, 1, p);
            update(B, p, 1);
            update(D, q, 1);
            upd(1, 1, n, q);
            pivot = p;
        } else {
            int used = query(B, p);
            int deleted = query(D, p);
            if (deleted < used) {
                cout << deleted << " " << used << endl;
                assert(false);
            }

            int R = 0;
            while (query(D, R + 1) <= i) R++;
            cout << i << " " << query(D, R) << endl;
            q = query(1, 1, n, 1, R);
            update(B, p, 1);
            update(D, q, 1);
            upd(1, 1, n, q);
        }
        cout << b[i] << " -> ";
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
