#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string> &words) {
    vector<int> cur(26, INT_MAX);
    for (auto &word : words) {
      array<int, 26> now = {0};
      for (auto c : word) now[c - 'a']++;
      for (int i = 0; i < 26; i++) cur[i] = min(cur[i], now[i]);
    }

    vector<string> ans;
    for (auto x = 'a'; x <= 'z'; x++) {
      while (cur[x - 'a']--) ans.push_back(string{x});
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(FindCommonCharacters, Test1) {
  Solution solution;
  vector<string> words = {"bella", "label", "roller"};
  vector<string> expected = {"e", "l", "l"};
  vector<string> result = solution.commonChars(words);
  sort(expected.begin(), expected.end());
  sort(result.begin(), result.end());
  ASSERT_EQ(result, expected);
}

TEST(FindCommonCharacters, Test2) {
  Solution solution;
  vector<string> words = {"cool", "lock", "cook"};
  vector<string> expected = {"c", "o"};
  vector<string> result = solution.commonChars(words);
  sort(expected.begin(), expected.end());
  sort(result.begin(), result.end());
  ASSERT_EQ(result, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}