#include "roman_to_integer.h"

#include <iostream>
#include <string>
using namespace std;

#include "gtest/gtest.h"

TEST(RomanToIntTest, Test1) {
  Solution solution;
  ASSERT_EQ(solution.romanToInt("III"), 3);
}

TEST(RomanToIntTest, Test2) {
  Solution solution;
  ASSERT_EQ(solution.romanToInt("IV"), 4);
}

TEST(RomanToIntTest, Test3) {
  Solution solution;
  ASSERT_EQ(solution.romanToInt("IX"), 9);
}

TEST(RomanToIntTest, Test4) {
  Solution solution;
  ASSERT_EQ(solution.romanToInt("LVIII"), 58);
}

TEST(RomanToIntTest, Test5) {
  Solution solution;
  ASSERT_EQ(solution.romanToInt("MCMXCIV"), 1994);
}