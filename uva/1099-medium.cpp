#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;
int p[16];
int tot[1 << 15];
bool dp[1 << 15][101];
int vis[1 << 15][101];
int cnt = 1;

bool solve(int mask, int x) {
    int y = tot[mask] / x;
    if (!(mask & (mask - 1))) { return tot[mask] == x * y; }
    if (vis[mask][x] == cnt) return dp[mask][x];
    vis[mask][x] = cnt;
    int ret      = false;
    for (int a = (mask - 1) & mask; a; a = (a - 1) & mask) {
        int b = mask ^ a;
        if (tot[a] % x == 0 && solve(a, min(tot[a] / x, x)) &&
            solve(b, min(tot[b] / x, x)))
            return dp[mask][x] = 1;

        if (tot[a] % y == 0 && solve(a, min(tot[a] / y, y)) &&
            solve(b, min(tot[b] / y, y)))
            return dp[mask][x] = 1;
    }
    return dp[mask][x] = 0;
}

int main() {
    int cs = 0;
    while (scanf("%d", &n) == 1 && n) {
        scanf("%d %d", &x, &y);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            sum += p[i];
        }
        for (int i = 0; i < 1 << n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) sum += p[j];
            tot[i] = sum;
        }

        if (sum != x * y) {
            printf("Case %d: No\n", ++cs);
        } else
            printf("Case %d: %s\n", ++cs,
                   solve((1 << n) - 1, min(x, y)) ? "Yes" : "No");
        cnt++;
    }
}
