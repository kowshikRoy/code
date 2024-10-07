#include <algorithm>
#include <set>
using namespace std;

class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    set<int> s;
    for (int i = 1; i <= bound; i *= x) {
      for (int j = 1; i + j <= bound; j *= y) {
        s.insert(i + j);
        if (y == 1) break;
      }
      if (x == 1) break;
    }
    return vector<int>(s.begin(), s.end());
  }
};

#include <gtest/gtest.h>

TEST(PowerfulIntegersTest, Test1) {
  Solution solution;
  int x = 2;
  int y = 3;
  int bound = 10;
  vector<int> expected = {2, 3, 4, 5, 7, 9, 10};
  vector<int> actual = solution.powerfulIntegers(x, y, bound);
  sort(actual.begin(), actual.end());
  ASSERT_EQ(actual, expected);
}

TEST(PowerfulIntegersTest, Test2) {
  Solution solution;
  int x = 3;
  int y = 5;
  int bound = 15;
  vector<int> expected = {2, 4, 6, 8, 10, 14};
  vector<int> actual = solution.powerfulIntegers(x, y, bound);
  sort(actual.begin(), actual.end());
  ASSERT_EQ(actual, expected);
}

TEST(PowerfulIntegersTest, Test3) {
  Solution solution;
  int x = 1;
  int y = 1;
  int bound = 3;
  vector<int> expected = {2};
  vector<int> actual = solution.powerfulIntegers(x, y, bound);
  sort(actual.begin(), actual.end());
  ASSERT_EQ(actual, expected);
}