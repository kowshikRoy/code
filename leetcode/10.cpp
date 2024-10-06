/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-22
 * Task: 10
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = (int)s.length(), m = (int)p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) dp[i][0] = false;
    if (n == 0) {
      for (int i = 0; i < m; i += 2)
        if (p[i] != '*') return false;
      return m % 2 == 0;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i] == p[j] || p[j] == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p[j] == '*') {
          dp[i + 1][j + 1] = dp[i + 1][j + 1] | dp[i + 1][j - 1];
          if (p[j - 1] == s[i] || p[j - 1] == '.')
            dp[i + 1][j + 1] = dp[i + 1][j + 1] | dp[i][j];

        } else
          dp[i + 1][j + 1] = false;
      }
    }
    return dp[n][m];
  }
};
