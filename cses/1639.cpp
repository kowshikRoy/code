/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1639
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, INF));
    for(int i = 0; i <= s.size(); i ++) dp[i][0] = i;
    for(int i = 0; i <= t.size(); i ++) dp[0][i] = i;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            int ret = INF;
            if (s[i - 1] == t[j - 1]) ret = dp[i - 1][j - 1];
            ret      = min(ret, 1 + dp[i][j - 1]);
            ret      = min(ret, 1 + dp[i - 1][j]);
            ret      = min(ret, 1 + dp[i - 1][j - 1]);
            dp[i][j] = ret;
        }
    }
    cout << dp[s.size()][t.size()] << endl;
}
