#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, long long> dp;
    dp[0] = 1;
    int pre = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      pre += nums[i];
      if (dp.count(pre - k)) ans += dp[pre - k];
      dp[pre]++;
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(SubarraySumEqualsK, Test1) {
  Solution solution;
  vector<int> nums = {1, 1, 1};
  int k = 2;
  int expected = 2;
  int actual = solution.subarraySum(nums, k);
  ASSERT_EQ(actual, expected);
}

TEST(SubarraySumEqualsK, Test2) {
  Solution solution;
  vector<int> nums = {1, 2, 3};
  int k = 3;
  int expected = 2;
  int actual = solution.subarraySum(nums, k);
  ASSERT_EQ(actual, expected);
}