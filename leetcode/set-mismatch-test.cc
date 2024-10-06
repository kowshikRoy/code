#include "set-mismatch.h"

#include "gtest/gtest.h"

TEST(SetMismatchTest, Test1) {
  Solution solution;
  std::vector<int> nums = {1, 2, 2, 4};
  std::vector<int> expected = {2, 3};
  ASSERT_EQ(solution.findErrorNums(nums), expected);
}

TEST(SetMismatchTest, Test2) {
  Solution solution;
  std::vector<int> nums = {1, 1};
  std::vector<int> expected = {1, 2};
  ASSERT_EQ(solution.findErrorNums(nums), expected);
}