#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
 public:
  int numJewelsInStones(std::string jewels, std::string stones);
};
int Solution::numJewelsInStones(std::string jewels, std::string stones) {
  std::unordered_set<char> s;
  for (auto c : jewels) {
    s.insert(c);
  }
  int res = 0;
  for (auto c : stones) {
    if (s.count(c)) res++;
  }
  return res;
}

#include <gtest/gtest.h>

TEST(JewelsAndStonesTest, Test1) {
  Solution solution;
  std::string jewels = "aA";
  std::string stones = "aAAbbbb";
  ASSERT_EQ(solution.numJewelsInStones(jewels, stones), 3);
}

TEST(JewelsAndStonesTest, Test2) {
  Solution solution;
  std::string jewels = "z";
  std::string stones = "ZZ";
  ASSERT_EQ(solution.numJewelsInStones(jewels, stones), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
