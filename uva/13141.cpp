/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 13141
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h;
    while (cin >> h) {
        if (!h) break;

        vector<vector<ll>> dp(h + 1, vector<ll>(2, -1));
        function<ll(int lev, int f)> dfs = [&](int lev, int f) -> ll {
            if (lev == h) return 1;
            if (dp[lev][f] != -1) return dp[lev][f];
            return dp[lev][f] = dfs(lev + 1, 1) + (f ? dfs(lev + 1, 0) : 0);
        };

        cout << dfs(1, 0) << endl;
    }
    return 0;
}
