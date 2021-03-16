/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1746
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (a[i]) dp[i][a[1]] = 1;
            else
                for (int k = 1; k <= m; k++) dp[i][k] = 1;
            continue;
        }

        if (a[i])
            dp[i][a[i]] = dp[i - 1][a[i]] +
                          (a[i] > 0 ? dp[i - 1][a[i] - 1] : 0) +
                          (a[i] + 1 <= m ? dp[i - 1][a[i] + 1] : 0);
        else {
            for (int k = 1; k <= m; k++) {
                dp[i][k] = dp[i - 1][k] + (k > 0 ? dp[i - 1][k - 1] : 0) +
                           (k + 1 <= m ? dp[i - 1][k + 1] : 0);
            }
        }
        for (int k = 1; k <= m; k++) dp[i][k] = dp[i][k] % M;
    }
    long long ans = 0;
    for (int k = 1; k <= m; k++) ans = (ans + dp[n][k]) % M;
    cout << ans << endl;
}
