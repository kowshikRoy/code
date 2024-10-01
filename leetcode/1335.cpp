/**
 * Author: Repon Kumar Roy
 * Date: 2021-07-01
 * Task: 1335
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = (int)jobs.size();
        if (n < d) return -1;
        const int INF = 1 << 28;

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

        function<int(int, int)> rec = [&](int i, int k) -> int {
            if (i == n) {
                if (k == 0) return 0;
                return INF;
            }
            if (k == 0) return INF;
            if (n - i < k) return INF;
            if (dp[i][k] != -1) return dp[i][k];

            int iM  = 0;
            int ret = INF;
            for (int j = i; j < n; j++) {
                iM  = max(iM, jobs[j]);
                ret = min(ret, iM + rec(j + 1, k - 1));
            }
            return dp[i][k] = ret;
        };

        return rec(0, d);
    }
};
