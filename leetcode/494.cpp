/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 494
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int C = 1001, t = 2 * C;
    vector<long long> dp(t);
    dp[C] = 1;
    for (auto c : nums) {
      vector<long long> nxt(t);
      for (int i = c; i < t; i++) nxt[i] += dp[i - c];
      for (int i = 0; i + c < t; i++) nxt[i] += dp[i + c];
      swap(nxt, dp)
    }
    return dp[C + target];
  }
};

int main() {
  vector<int> n = {1, 2, 3};
  int t = 1;
  cout << Solution().findTargetSumWays(n, t) << endl;
}
