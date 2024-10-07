#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums1.size(); i++)
      for (int j = 0; j < nums2.size(); j++) mp[nums1[i] + nums2[j]]++;

    int ans = 0;
    for (int k = 0; k < nums3.size(); k++) {
      for (int l = 0; l < nums4.size(); l++) {
        int sum = nums3[k] + nums4[l];
        if (mp.count(-sum)) {
          ans += mp[-sum];
        }
      }
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(FourSumCount, Test1) {
  Solution solution;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {-2, -1};
  vector<int> nums3 = {-1, 2};
  vector<int> nums4 = {0, 2};
  int expected = 2;
  int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
  ASSERT_EQ(result, expected);
}

TEST(FourSumCount, Test2) {
  Solution solution;
  vector<int> nums1 = {0};
  vector<int> nums2 = {0};
  vector<int> nums3 = {0};
  vector<int> nums4 = {0};
  int expected = 1;
  int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
  ASSERT_EQ(result, expected);
}

TEST(FourSumCount, Test3) {
  Solution solution;
  vector<int> nums1 = {1, 1, 1, 1};
  vector<int> nums2 = {-1, -1, -1, -1};
  vector<int> nums3 = {-1, -1, -1, -1};
  vector<int> nums4 = {1, 1, 1, 1};
  int expected = 256;
  int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
  ASSERT_EQ(result, expected);
}