#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> s;
    for (auto a : candyType) s.insert(a);
    return min(s.size(), candyType.size() / 2);
  }
};

#include <gtest/gtest.h>

TEST(DistributeCandies, Test1) {
  Solution solution;
  vector<int> candyType = {1, 1, 2, 2, 3, 3};
  int expected = 3;
  int actual = solution.distributeCandies(candyType);
  ASSERT_EQ(actual, expected);
}

TEST(DistributeCandies, Test2) {
  Solution solution;
  vector<int> candyType = {1, 1, 2, 3};
  int expected = 2;
  int actual = solution.distributeCandies(candyType);
  ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}