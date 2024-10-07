#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    vector<int> ans;
    for (auto x : nums2) {
      if (s.count(x)) {
        ans.push_back(x);
        s.erase(x);
      }
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(IntersectionOfTwoArrayTest, Test1) {
  Solution solution;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> expected = {2};
  vector<int> actual = solution.intersection(nums1, nums2);
  ASSERT_EQ(actual, expected);
}

TEST(IntersectionOfTwoArrayTest, Test2) {
  Solution solution;
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  vector<int> expected = {9, 4};
  vector<int> actual = solution.intersection(nums1, nums2);
  ASSERT_EQ(actual, expected);
}