/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1635
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
    vector<int> coin(n, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) { cin >> coin[i]; }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coin[j]) {
                dp[i] += dp[i - coin[j]];
                if (dp[i] >= M) dp[i] -= M;
            }
        }
    }
    cout << dp[x] << endl;
}
