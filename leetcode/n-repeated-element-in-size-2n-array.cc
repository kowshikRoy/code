#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto x : nums) {
      if (++mp[x] == nums.size() / 2) return x;
    }
    return -1;
  }
};

#include <gtest/gtest.h>

TEST(NRepeatedElementInSize2NArrayTest, Test1) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 3};
  int expected = 3;
  int actual = solution.repeatedNTimes(nums);
  ASSERT_EQ(actual, expected);
}

TEST(NRepeatedElementInSize2NArrayTest, Test2) {
  Solution solution;
  vector<int> nums = {2, 1, 2, 5, 3, 2};
  int expected = 2;
  int actual = solution.repeatedNTimes(nums);
  ASSERT_EQ(actual, expected);
}

TEST(NRepeatedElementInSize2NArrayTest, Test3) {
  Solution solution;
  vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
  int expected = 5;
  int actual = solution.repeatedNTimes(nums);
  ASSERT_EQ(actual, expected);
}
