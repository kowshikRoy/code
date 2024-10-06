#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (auto c : s) mp[c]++;
    int ans = 0;
    for (auto [k, v] : mp) {
      ans += (v / 2) * 2;
      mp[k] = v % 2;
    }
    for (auto [k, v] : mp) {
      if (v) {
        ans++;
        break;
      }
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(LongestPalindrome, Test1) {
  Solution solution;
  string s = "abccccdd";
  int expected = 7;
  int actual = solution.longestPalindrome(s);
  ASSERT_EQ(actual, expected);
}

TEST(LongestPalindrome, Test2) {
  Solution solution;
  string s = "a";
  int expected = 1;
  int actual = solution.longestPalindrome(s);
  ASSERT_EQ(actual, expected);
}

TEST(LongestPalindrome, Test3) {
  Solution solution;
  string s = "ccc";
  int expected = 3;
  int actual = solution.longestPalindrome(s);
  ASSERT_EQ(actual, expected);
}
