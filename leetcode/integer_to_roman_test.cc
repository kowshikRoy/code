#include "integer_to_roman.h"

#include "gtest/gtest.h"

TEST(IntegerToRomanTest, Test1) {
  Solution solution;
  ASSERT_EQ(solution.intToRoman(3), "III");
}

TEST(IntegerToRomanTest, Test2) {
  Solution solution;
  ASSERT_EQ(solution.intToRoman(4), "IV");
}

TEST(IntegerToRomanTest, Test3) {
  Solution solution;
  ASSERT_EQ(solution.intToRoman(9), "IX");
}

TEST(IntegerToRomanTest, Test4) {
  Solution solution;
  ASSERT_EQ(solution.intToRoman(58), "LVIII");
}

TEST(IntegerToRomanTest, Test5) {
  Solution solution;
  ASSERT_EQ(solution.intToRoman(1994), "MCMXCIV");
}