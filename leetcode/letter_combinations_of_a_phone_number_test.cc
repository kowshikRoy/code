#include "gtest/gtest.h"
#include "letter_combinations_of_a_phone_number.h"

TEST(LetterCombinationsTest, Test1) {
    Solution solution;
    std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    ASSERT_EQ(solution.letterCombinations("23"), expected);
}

TEST(LetterCombinationsTest, Test2) {
    Solution solution;
    std::vector<std::string> expected = {};
    ASSERT_EQ(solution.letterCombinations(""), expected);
}

TEST(LetterCombinationsTest, Test3) {
    Solution solution;
    std::vector<std::string> expected = {"a", "b", "c"};
    ASSERT_EQ(solution.letterCombinations("2"), expected);
}

TEST(LetterCombinationsTest, Test4) {
    Solution solution;
    std::vector<std::string> expected = {"tw", "tx", "ty", "tz", "uw", "ux", "uy", "uz", "vw", "vx", "vy", "vz"};
    ASSERT_EQ(solution.letterCombinations("89"), expected);
}
