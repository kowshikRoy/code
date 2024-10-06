#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    set<tuple<int, int, int, int>> H;
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        long long need = 0LL + target - nums[i] - nums[j];
        for (int p = j + 1, q = nums.size() - 1; p < q;) {
          if (0LL + nums[p] + nums[q] == need) {
            H.insert({nums[i], nums[j], nums[p], nums[q]});
            p++;
            q--;
          } else if (0LL + nums[p] + nums[q] < need) {
            p++;
          } else {
            q--;
          }
        }
      }
    }
    for (auto [a, b, c, d] : H) {
      res.push_back({a, b, c, d});
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(FourSum, Test1) {
  Solution solution;
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> expected = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  vector<vector<int>> result = solution.fourSum(nums, target);
  sort(expected.begin(), expected.end());
  sort(result.begin(), result.end());
  ASSERT_EQ(result, expected);
}

TEST(FourSum, Test2) {
  Solution solution;
  vector<int> nums = {2, 2, 2, 2, 2};
  int target = 8;
  vector<vector<int>> expected = {{2, 2, 2, 2}};
  vector<vector<int>> result = solution.fourSum(nums, target);
  sort(expected.begin(), expected.end());
  sort(result.begin(), result.end());
  ASSERT_EQ(result, expected);
}

TEST(FourSum, Test3) {
  Solution solution;
  vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
  int target = -294967296;
  vector<vector<int>> expected = {};
  vector<vector<int>> result = solution.fourSum(nums, target);
  sort(expected.begin(), expected.end());
  sort(result.begin(), result.end());
  ASSERT_EQ(result, expected);
}
