
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int n = wall.size();
    unordered_map<int, int> mp;
    for (auto& w : wall) {
      int len = 0;
      for (int i = 0; i < w.size(); i++) {
        len += w[i];
        if (i + 1 != w.size()) mp[len]++;
      }
    }
    int ans = n;
    for (auto [k, v] : mp) ans = min(ans, n - v);
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(BrickWall, Test1) {
  Solution solution;
  vector<vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                              {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};
  int expected = 2;
  int actual = solution.leastBricks(wall);
  ASSERT_EQ(actual, expected);
}

TEST(BrickWall, Test2) {
  Solution solution;
  vector<vector<int>> wall = {{1}, {1}, {1}};
  int expected = 3;
  int actual = solution.leastBricks(wall);
  ASSERT_EQ(actual, expected);
}
