#include <bits/stdc++.h>
using namespace std;

const int N = 255;
int f[N], pf[N];
int dp[N][N], ptr[N][N];
int vis[N][N];
int CS = 0;

int sum(int i, int j) {
    if (i > j) return 0;
    return pf[j] - (i == 0 ? 0 : pf[i - 1]);
}

int solve(int i, int j) {
    if (i >= j) return 0;
    int &ret = dp[i][j];
    if (vis[i][j] == CS) return ret;
    ret = INT_MAX;
    int pivot = -1;
    solve(i, j - 1);
    solve(i + 1, j);
    for (int k = ptr[i][j - 1]; k <= ptr[i + 1][j]; k++) {
        int val =
            solve(i, k - 1) + solve(k + 1, j) + sum(i, k - 1) + sum(k + 1, j);
        if (val < ret) {
            pivot = k;
            ret = val;
        }
    }
    vis[i][j] = CS;
    ptr[i][j] = pivot;
    return ret;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        CS++;
        for (int i = 0; i < n; i++) ptr[i][i] = i;
        for (int i = 0; i < n; i++) {
            scanf("%d", &f[i]);
            pf[i] = f[i];
            if (i > 0) pf[i] += pf[i - 1];
        }
        cout << solve(0, n - 1) << endl;
    }
}
