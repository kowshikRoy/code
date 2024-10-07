#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (s.count(n) == 0) {
      s.insert(n);
      int sum = 0;
      while (n) sum += (n % 10) * (n % 10), n /= 10;
      if (sum == 1) return true;
      n = sum;
    }
    return false;
  }
};

#include <gtest/gtest.h>

TEST(HappyNumberTest, Test1) {
  Solution solution;
  ASSERT_TRUE(solution.isHappy(19));
}

TEST(HappyNumberTest, Test2) {
  Solution solution;
  ASSERT_FALSE(solution.isHappy(2));
}
