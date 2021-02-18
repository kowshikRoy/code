#include <bits/stdc++.h>
using namespace std;

int n, _cnt = 1;
int vis[4][280][1 << 12], dp[4][280][1 << 12];
int v[3][12];

int solve(int last, int mask) {
    if (mask == 0 && t >= 280)
        return 0;
    if (vis[last][t][mask] == _cnt)
        return dp[last][t][mask];
    int ret = 0;
    for (int i = 0; i < 3 ; i++) {
        if(i == last) continue;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                if (t + v[i][j] <= 280)
                    ret = max(ret, 1 + solve(i, t + v[i][j], mask ^ (1 << j)));
            }
        }
    }
    vis[last][t][mask] = _cnt;
    return dp[last][t][mask] = ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &v[i][j]);
            }
        }
        printf("%d\n", solve(3, 0, (1 << n) - 1));
        _cnt++;
    }
}
