#include "single-number.h"

#include "gtest/gtest.h"

TEST(SingleNumberTest, Test1) {
  Solution solution;
  std::vector<int> nums = {2, 2, 1};
  ASSERT_EQ(solution.singleNumber(nums), 1);
}

TEST(SingleNumberTest, Test2) {
  Solution solution;
  std::vector<int> nums = {4, 1, 2, 1, 2};
  ASSERT_EQ(solution.singleNumber(nums), 4);
}

TEST(SingleNumberTest, Test3) {
  Solution solution;
  std::vector<int> nums = {1};
  ASSERT_EQ(solution.singleNumber(nums), 1);
}