/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-20
 * Task: 1043
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = (int)arr.size();

    int dp[n + 1][n + 1][n + 1];
    memset(dp, -1, sizeof dp);

    function<int(int, int, int)> rec = [&](int pos, int m, int taken) -> int {
      if (pos == n) return arr[m] * taken;
      int& ans = dp[pos][m][taken];
      if (ans != -1) return ans;

      ans = 0;
      if (taken) ans = max(ans, arr[m] * taken + rec(pos + 1, n, 0));
      if (taken < k) {
        int nxt_m = m;
        if (m == n || arr[pos] > arr[m]) nxt_m = pos;
        ans = max(ans, rec(pos + 1, nxt_m, taken + 1));
      }

      return ans;
    };
    return rec(0, n, 0);
  }
};
