/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-22
 * Task: 1633
 */

#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) dp[i] += dp[i - j];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout << dp[n] << endl;
}
