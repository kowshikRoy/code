#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (mp[nums[i]]) ans += mp[nums[i]];
      mp[nums[i]]++;
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(NumberOfGoodPairsTest, Test1) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1, 1, 3};
  int expected = 4;
  int actual = solution.numIdenticalPairs(nums);
  ASSERT_EQ(actual, expected);
}

TEST(NumberOfGoodPairsTest, Test2) {
  Solution solution;
  vector<int> nums = {1, 1, 1, 1};
  int expected = 6;
  int actual = solution.numIdenticalPairs(nums);
  ASSERT_EQ(actual, expected);
}

TEST(NumberOfGoodPairsTest, Test3) {
  Solution solution;
  vector<int> nums = {1, 2, 3};
  int expected = 0;
  int actual = solution.numIdenticalPairs(nums);
  ASSERT_EQ(actual, expected);
}