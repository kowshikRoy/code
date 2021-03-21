#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 22;
int B[N + 1];
int p[N + 1], pos[N + 1], rpos[N + 1];

void update(int x, int v) {
    while (x <= N) B[x] += v, x += x & -x;
}

int findKth(int x) {
    int r = 0;
    x--;
    for (int i = 21; i >= 0; i--) {
        int nxt = r + (1 << i);
        if (nxt >= N) continue;
        if (B[nxt] <= x) r = nxt, x -= B[nxt];
    }
    return r + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int off = 1e6 + 6;
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) pos[i] = off + i, rpos[off + i] = i;
    for (int i = 1; i <= n; i++) update(pos[i], 1);
    for (int i = 1; i <= n; i++) p[i] = -1;
    int front = off;
    bool flag = 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int index = findKth(x);
    }
    for (int i = 1, j = 1; i <= n; i++) {
        if (p[i] == -1) {
            while (pos[j] != -1) j++;
            p[i] = j;
            j++;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", p[i]);
    return 0;
}
