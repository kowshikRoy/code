#include "gtest/gtest.h"
#include "find-the-difference.h"

TEST(FindTheDifferenceTest, Test1) {
    Solution solution;
    ASSERT_EQ(solution.findTheDifference("abcd", "abcde"), 'e');
}

TEST(FindTheDifferenceTest, Test2) {
    Solution solution;
    ASSERT_EQ(solution.findTheDifference("", "y"), 'y');
}

TEST(FindTheDifferenceTest, Test3) {
    Solution solution;
    ASSERT_EQ(solution.findTheDifference("a", "aa"), 'a');
}
