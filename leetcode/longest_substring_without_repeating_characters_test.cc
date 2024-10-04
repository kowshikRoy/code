#include <gtest/gtest.h>
#include "longest_substring_without_repeating_characters.h"


TEST(Solution, test) {
    Solution sol;
    EXPECT_EQ(sol.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(sol.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(sol.lengthOfLongestSubstring("pwwkew"), 3);
    EXPECT_EQ(sol.lengthOfLongestSubstring("aabaab!bb"), 3);
    EXPECT_EQ(sol.lengthOfLongestSubstring(""), 0);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}