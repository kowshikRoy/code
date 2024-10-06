#include "contiguous-array.h"

#include <unordered_map>
#include <vector>

int Solution::findMaxLength(std::vector<int>& nums) {
  std::unordered_map<int, int> dp;
  dp[0] = -1;
  int pre = 0, res = 0;
  for (int i = 0; i < nums.size(); i++) {
    pre += nums[i] == 0 ? -1 : 1;
    if (dp.count(pre)) {
      res = std::max(res, i - dp[pre]);
    } else
      dp[pre] = i;
  }
  return res;
}