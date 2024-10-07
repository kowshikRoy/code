#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++) v.push_back({i, nums[i]});
    sort(v.begin(), v.end(), [](auto a, auto b) {
      return (a.second == b.second) ? a.first < b.first : a.second < b.second;
    });
    vector<int> ans(v.size());
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
      while (j < i && v[j].second < v[i].second) j++;
      ans[v[i].first] = j;
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(HowManyNumbersAreSmallerThanTheCurrentNumber, Test1) {
  Solution solution;
  vector<int> nums = {8, 1, 2, 2, 3};
  vector<int> expected = {4, 0, 1, 1, 3};
  vector<int> actual = solution.smallerNumbersThanCurrent(nums);
  ASSERT_EQ(actual, expected);
}

TEST(HowManyNumbersAreSmallerThanTheCurrentNumber, Test2) {
  Solution solution;
  vector<int> nums = {6, 5, 4, 8};
  vector<int> expected = {2, 1, 0, 3};
  vector<int> actual = solution.smallerNumbersThanCurrent(nums);
  ASSERT_EQ(actual, expected);
}

TEST(HowManyNumbersAreSmallerThanTheCurrentNumber, Test3) {
  Solution solution;
  vector<int> nums = {7, 7, 7, 7};
  vector<int> expected = {0, 0, 0, 0};
  vector<int> actual = solution.smallerNumbersThanCurrent(nums);
  ASSERT_EQ(actual, expected);
}
