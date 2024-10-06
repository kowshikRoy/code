#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    map<char, int> mp;
    for (auto c : text) {
      mp[c]++;
    }
    map<char, int> need;
    string p = "balloon";
    for (char s : p) {
      need[s]++;
    }

    int ans = 1e9;
    for (auto [k, v] : need) {
      ans = min(ans, mp[k] / v);
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(MaximumNumberOfBalloons, Test1) {
  Solution solution;
  ASSERT_EQ(solution.maxNumberOfBalloons("nlaebolko"), 1);
}

TEST(MaximumNumberOfBalloons, Test2) {
  Solution solution;
  ASSERT_EQ(solution.maxNumberOfBalloons("loonbalxballpoon"), 2);
}

TEST(MaximumNumberOfBalloons, Test3) {
  Solution solution;
  ASSERT_EQ(solution.maxNumberOfBalloons("leetcode"), 0);
}
