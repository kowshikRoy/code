#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> fr;
    for (auto x : nums) fr[x]++;
    sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (fr[a] == fr[b]) return a > b;
      return fr[a] < fr[b];
    });
    return nums;
  }
};

#include <gtest/gtest.h>

TEST(SortArrayByIncreasingFrequency, Test1) {
  Solution solution;
  vector<int> nums = {1, 1, 2, 2, 2, 3};
  vector<int> expected = {3, 1, 1, 2, 2, 2};
  vector<int> actual = solution.frequencySort(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SortArrayByIncreasingFrequency, Test2) {
  Solution solution;
  vector<int> nums = {2, 3, 1, 3, 2};
  vector<int> expected = {1, 3, 3, 2, 2};
  vector<int> actual = solution.frequencySort(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SortArrayByIncreasingFrequency, Test3) {
  Solution solution;
  vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
  vector<int> expected = {5, -1, 4, 4, -6, -6, 1, 1, 1};
  vector<int> actual = solution.frequencySort(nums);
  ASSERT_EQ(actual, expected);
}
