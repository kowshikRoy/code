/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1097
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long sum = 0;
    cin >> n;
    int x[n + 1];
    for (int i = 1; i <= n; i++) cin >> x[i], sum += x[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][i] = x[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j    = i + len - 1;
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }
    cout << (sum + dp[1][n]) / 2 << endl;
}
