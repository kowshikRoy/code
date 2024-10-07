#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> A, B;
    for (auto x : nums1) A[x]++;
    for (auto x : nums2) B[x]++;
    vector<int> ans;
    for (auto [k, v] : A) {
      if (B.count(k)) {
        int cnt = min(v, B[k]);
        while (cnt--) ans.push_back(k);
      }
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(IntersectionOfTwoArraysII, Test1) {
  Solution solution;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> expected = {2, 2};
  vector<int> actual = solution.intersect(nums1, nums2);
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  ASSERT_EQ(actual, expected);
}

TEST(IntersectionOfTwoArraysII, Test2) {
  Solution solution;
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  vector<int> expected = {4, 9};
  vector<int> actual = solution.intersect(nums1, nums2);
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  ASSERT_EQ(actual, expected);
}