#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int B[N];
int query(int x) {
    int sum = 0;
    while (x < N) sum += B[x], x += x & -x;
    return sum;
}

void update(int x, int v) {
    while (x) B[x] += v, x -= x & -x;
}
int main() {
    int n, K;
    cin >> n >> K;
    int h[n], u[n];
    int ans = -1;
    int pivot = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < n; j++) cin >> h[j], u[j] = h[j];
        sort(u, u + n);
        int m = unique(u, u + n) - u;
        for (int j = 0; j < n; j++) h[j] = lower_bound(u, u + m, h[j]) - u + 1;
        int c = 0;
        for (int j = 0; j < n; j++) {
            c += query(h[j]);
            update(h[j], 1);
        }
        if (c > ans) {
            ans = c;
            pivot = i + 1;
        }
        memset(B, 0, sizeof B);
    }
    cout << pivot << endl;
}
