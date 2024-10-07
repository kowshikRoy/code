#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    auto dis = [](vector<int> &a, vector<int> &b) {
      return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    };
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
      unordered_map<int, int> mp;
      for (int j = 0; j < points.size(); j++) {
        if (i == j) continue;
        int d = dis(points[i], points[j]);
        if (mp.count(d)) ans += 2 * mp[d];
        mp[d]++;
      }
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(NumberOfBoomerangs, Test1) {
  Solution solution;
  vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
  int expected = 2;
  int actual = solution.numberOfBoomerangs(points);
  ASSERT_EQ(actual, expected);
}

TEST(NumberOfBoomerangs, Test2) {
  Solution solution;
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  int expected = 2;
  int actual = solution.numberOfBoomerangs(points);
  ASSERT_EQ(actual, expected);
}

TEST(NumberOfBoomerangs, Test3) {
  Solution solution;
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
  int expected = 4;
  int actual = solution.numberOfBoomerangs(points);
  ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}