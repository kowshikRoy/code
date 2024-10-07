#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int countWords(vector<string>& words, string chars) {
    unordered_map<char, int> mp;
    for (auto c : chars) mp[c]++;
    int ans = 0;
    for (auto word : words) {
      unordered_map<char, int> tmp;
      bool flag = true;
      for (auto c : word) {
        tmp[c]++;
        if (tmp[c] > mp[c]) {
          flag = false;
          break;
        }
      }
      if (flag) ans += word.size();
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(FindWordsThatCanBeFormedByCharacters, Test1) {
  Solution solution;
  vector<string> words = {"cat", "bt", "hat", "tree"};
  string chars = "atach";
  int expected = 6;
  int actual = solution.countWords(words, chars);
  ASSERT_EQ(actual, expected);
}

TEST(FindWordsThatCanBeFormedByCharacters, Test2) {
  Solution solution;
  vector<string> words = {"hello", "world", "leetcode"};
  string chars = "welldonehoneyr";
  int expected = 10;
  int actual = solution.countWords(words, chars);
  ASSERT_EQ(actual, expected);
}