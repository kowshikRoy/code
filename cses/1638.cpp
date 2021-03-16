/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1638
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
const int M   = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<int>> dp(2, vector<int>(n));

    for (int i = 0; i < n; i++) {
        int cur = i & 1;
        for (int j = 0; j < n; j++) {
            dp[cur][j] = 0;
            if (grid[i][j] == '*') continue;
            if (i == 0 && j == 0) {
                dp[cur][j] = 1;
                continue;
            }
            if (i > 0) dp[cur][j] = dp[cur ^ 1][j];
            if (j > 0) dp[cur][j] += dp[cur][j - 1];
            dp[cur][j] %= M;
        }
    }
    cout << dp[(n - 1) & 1][n - 1] << endl;
}
