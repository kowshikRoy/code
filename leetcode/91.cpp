/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-15
 * Task: 91
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dp;

   public:
    int solve(string &s, int i) {
        if (i == s.size()) return 1;
        if (i > s.size()) return 0;

        if (dp[i] != -1) return dp[i];
        int k   = s[i] - '0';
        int ans = 0;
        if (k > 0) ans += solve(s, i + 1);
        if (s[i] != '0' && i + 1 < s.size() &&
            10 * (s[i] - '0') + s[i + 1] - '0' <= 26) {
            ans += solve(s, i + 2);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return solve(s, 0);
    }
};
