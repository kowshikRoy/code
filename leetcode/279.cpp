/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 279
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1 << 28);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++)
                dp[j] = min(dp[j], 1 + dp[j - i * i]);
        }
        return dp[n];
    }
};
