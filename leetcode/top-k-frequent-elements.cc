#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto x : nums) mp[x]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        pq;
    for (auto [k, v] : mp) pq.push({v, k});
    vector<int> ans;
    while (k--) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(TopKFrequentElements, Test1) {
  Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> expected = {1, 2};
  vector<int> actual = solution.topKFrequent(nums, k);
  ASSERT_EQ(actual, expected);
}

TEST(TopKFrequentElements, Test2) {
  Solution solution;
  vector<int> nums = {1};
  int k = 1;
  vector<int> expected = {1};
  vector<int> actual = solution.topKFrequent(nums, k);
  ASSERT_EQ(actual, expected);
}