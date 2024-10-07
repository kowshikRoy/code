#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};
#include <gtest/gtest.h>

TEST(ValidAnagramTest, Test1) {
  Solution solution;
  string s = "anagram";
  string t = "nagaram";
  ASSERT_TRUE(solution.isAnagram(s, t));
}

TEST(ValidAnagramTest, Test2) {
  Solution solution;
  string s = "rat";
  string t = "car";
  ASSERT_FALSE(solution.isAnagram(s, t));
}

TEST(ValidAnagramTest, Test3) {
  Solution solution;
  string s = "aacc";
  string t = "ccac";
  ASSERT_FALSE(solution.isAnagram(s, t));
}