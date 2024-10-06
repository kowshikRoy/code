#include "contiguous-array.h"

#include "gtest/gtest.h"

TEST(ContiguousArrayTest, Test1) {
  Solution solution;
  std::vector<int> nums = {0, 1};
  ASSERT_EQ(solution.findMaxLength(nums), 2);
}

TEST(ContiguousArrayTest, Test2) {
  Solution solution;
  std::vector<int> nums = {0, 1, 0};
  ASSERT_EQ(solution.findMaxLength(nums), 2);
}

TEST(ContiguousArrayTest, Test3) {
  Solution solution;
  std::vector<int> nums = {0, 0, 1, 0, 0, 0, 1, 1};
  ASSERT_EQ(solution.findMaxLength(nums), 6);
}