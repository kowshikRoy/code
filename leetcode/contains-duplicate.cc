#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto x : nums) {
      if (s.count(x)) return true;
      s.insert(x);
    }
    return false;
  }
};

#include "gtest/gtest.h"

TEST(ContainsDuplicateTest, Test1) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  ASSERT_TRUE(solution.containsDuplicate(nums));
}

TEST(ContainsDuplicateTest, Test2) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  ASSERT_FALSE(solution.containsDuplicate(nums));
}

TEST(ContainsDuplicateTest, Test3) {
  Solution solution;
  vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  ASSERT_TRUE(solution.containsDuplicate(nums));
}