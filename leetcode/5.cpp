/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-15
 * Task: 5
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = (int)s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i + 1 < n; i++) dp[i][i + 1] = (s[i] == s[i + 1]);

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int j = i + len - 1;
        dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
      }
    }
    int maxLen = 0, A = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (dp[i][j]) {
          if (j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            A = i;
          }
        }
      }
    }
    return s.substr(A, maxLen);
  }
};
