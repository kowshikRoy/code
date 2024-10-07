#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> fr;
    for (auto x : nums) fr[x]++;
    int ans = 0;
    for (auto [k, v] : fr) {
      if (fr.count(k + 1)) ans = max(ans, v + fr[k + 1]);
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(LongestHarmoniousSubsequence, Test1) {
  Solution solution;
  vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
  int expected = 5;
  int actual = solution.findLHS(nums);
  ASSERT_EQ(actual, expected);
}

TEST(LongestHarmoniousSubsequence, Test2) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  int expected = 2;
  int actual = solution.findLHS(nums);
  ASSERT_EQ(actual, expected);
}

TEST(LongestHarmoniousSubsequence, Test3) {
  Solution solution;
  vector<int> nums = {1, 1, 1, 1};
  int expected = 0;
  int actual = solution.findLHS(nums);
  ASSERT_EQ(actual, expected);
}