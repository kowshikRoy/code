/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-16
 * Task: lexicographic-steps
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        vector<vector<int>> dp(x + 1, vector<int>(y + 1));
        dp[x][y] = 1;
        for (int i = x; i >= 0; i--) {
            for (int j = y; j >= 0; j--) {
                if (i == x && j == y) continue;
                if (i != x) dp[i][j] += dp[i + 1][j];
                if (j != y) dp[i][j] += dp[i][j + 1];
            }
        }
        int i = 0, j = 0;
        string out;
        k++;
        while (true) {
            if (i == x && j == y) break;
            if (i != x && dp[i + 1][j] >= k) {
                out.push_back('H');
                i++;
            } else {
                out.push_back('V');
                if (i != x) k -= dp[i + 1][j];
                j++;
            }
        }
        cout << out << endl;
    }
    return 0;
}
