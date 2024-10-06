/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 416
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;

    int t = sum / 2;
    vector<bool> dp(t + 1);
    dp[0] = true;
    for (auto c : nums) {
      for (int i = t; i >= c; i--) dp[i] = dp[i] || dp[i - c];
    }
    return dp[t];
  }
};
