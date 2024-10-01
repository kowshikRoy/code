/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-20
 * Task: 1578
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(27, 0));
        function<int(int, int)> rec = [&](int pos, int pre) -> int {
            if (pos == s.size()) return 0;
            int& ans = dp[pos][pre];
            if (ans != -1) return ans;

            // delete
            ans = cost[pos] + rec(pos + 1, pre);

            // not delete
            if (s[pos] != pre) ans = min(ans, rec(pos + 1, s[pos] - 'a'));
        };
        return rec(0, 26);
    }
};
