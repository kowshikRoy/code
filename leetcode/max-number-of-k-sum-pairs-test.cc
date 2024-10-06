#include "max-number-of-k-sum-pairs.h"

#include "gtest/gtest.h"

TEST(MaxNumberOfKSumPairsTest, Test1) {
  Solution solution;
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  ASSERT_EQ(solution.maxOperations(nums, k), 2);
}

TEST(MaxNumberOfKSumPairsTest, Test2) {
  Solution solution;
  std::vector<int> nums = {3, 1, 3, 4, 3};
  int k = 6;
  ASSERT_EQ(solution.maxOperations(nums, k), 1);
}

TEST(MaxNumberOfKSumPairsTest, Test3) {
  Solution solution;
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int k = 2;
  ASSERT_EQ(solution.maxOperations(nums, k), 2);
}