#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      if (mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
      mp[nums[i]] = i;
    }
    return false;
  }
};

#include <gtest/gtest.h>

TEST(ContainsNearbyDuplicateTest, Test1) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  ASSERT_TRUE(solution.containsNearbyDuplicate(nums, k));
}

TEST(ContainsNearbyDuplicateTest, Test2) {
  Solution solution;
  vector<int> nums = {1, 0, 1, 1};
  int k = 1;
  ASSERT_TRUE(solution.containsNearbyDuplicate(nums, k));
}

TEST(ContainsNearbyDuplicateTest, Test3) {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1, 2, 3};
  int k = 2;
  ASSERT_FALSE(solution.containsNearbyDuplicate(nums, k));
}