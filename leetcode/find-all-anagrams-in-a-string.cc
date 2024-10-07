#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> pv(26), sv(26), ans;
    for (auto c : p) pv[c - 'a']++;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      sv[c - 'a']++;
      if (i >= p.size()) sv[s[i - p.size()] - 'a']--;
      if (pv == sv) ans.push_back(i - p.size() + 1);
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(FindAllAnagramsInAString, Test1) {
  Solution solution;
  string s = "cbaebabacd";
  string p = "abc";
  vector<int> expected = {0, 6};
  vector<int> actual = solution.findAnagrams(s, p);
  ASSERT_EQ(actual, expected);
}

TEST(FindAllAnagramsInAString, Test2) {
  Solution solution;
  string s = "abab";
  string p = "ab";
  vector<int> expected = {0, 1, 2};
  vector<int> actual = solution.findAnagrams(s, p);
  ASSERT_EQ(actual, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}