/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1636
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (int j = p; j <= x; j++) {
            dp[j] += dp[j - p];
            if (dp[j] > M) dp[j] -= M;
        }
    }
    cout << dp[x] << endl;
}
