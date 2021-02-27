/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-22
 * Task: 1653
 */

#include <bits/stdc++.h>
using namespace std;

int n, x;
long long w[22];

int dp[1 << 20];
long long pre[1 << 20], Min[1 << 20];
int solve(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];
    int pivot = -1;
    for (int j = 0; j < n; j++)
        if (mask & (1 << j)) {
            pivot = j;
            break;
        }

    int rm  = mask ^ (1 << pivot);
    int ret = 1 << 20;
    for (int a = rm;; a = (a - 1) & rm) {
        long long sum = w[pivot] + pre[a];
        if ((rm ^ a) && sum + Min[rm ^ a] <= x) {
            if (a == 0) break;
            else
                continue;
        }
        if (sum <= x) ret = min(ret, 1 + solve(rm ^ a));
        if (a == 0) break;
    }
    return dp[mask] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < 1 << n; i++) {
        long long sum = 0, mn = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += w[j];
                mn = min(mn, w[j]);
            }
        }
        pre[i] = sum;
        Min[i] = mn;
    }
    memset(dp, -1, sizeof dp);
    cout << solve((1 << n) - 1) << endl;
}
