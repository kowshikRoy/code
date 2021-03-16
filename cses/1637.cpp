/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1637
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i + 1;
        int t = i;
        while (t) {
            int x = t % 10;
            t /= 10;
            dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    }
    cout << dp[n] << endl;
}
