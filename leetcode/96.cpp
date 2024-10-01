/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 96
 */

#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);

        function<int(int)> rec = [&](int n) -> int {
            if (n <= 1) return 1;
            if (dp[n] != -1) return dp[n];
            int ans = 0;
            for (int i = 0; i < n; i++) { ans += rec(i) * rec(n - 1 - i); }
            dbg(n, ans);
            return dp[n] = ans;
        };

        return rec(n);
    }
};

int main() {
    Solution().numTrees(3);
}
