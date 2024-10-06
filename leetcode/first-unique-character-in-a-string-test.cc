#include "gtest/gtest.h"
#include "first-unique-character-in-a-string.h"

TEST(FirstUniqCharTest, Test1) {
    Solution solution;
    ASSERT_EQ(solution.firstUniqChar("leetcode"), 0);
}

TEST(FirstUniqCharTest, Test2) {
    Solution solution;
    ASSERT_EQ(solution.firstUniqChar("loveleetcode"), 2);
}

TEST(FirstUniqCharTest, Test3) {
    Solution solution;
    ASSERT_EQ(solution.firstUniqChar("aabb"), -1);
}