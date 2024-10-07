#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    for (auto& str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      mp[s].push_back(str);
    }
    for (auto [k, v] : mp) {
      ans.push_back(v);
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(GroupAnagrams, Test1) {
  Solution solution;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> expected = {
      {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
  vector<vector<string>> actual = solution.groupAnagrams(strs);
  ASSERT_EQ(actual, expected);
}

TEST(GroupAnagrams, Test2) {
  Solution solution;
  vector<string> strs = {""};
  vector<vector<string>> expected = {{""}};
  vector<vector<string>> actual = solution.groupAnagrams(strs);
  ASSERT_EQ(actual, expected);
}

TEST(GroupAnagrams, Test3) {
  Solution solution;
  vector<string> strs = {"a"};
  vector<vector<string>> expected = {{"a"}};
  vector<vector<string>> actual = solution.groupAnagrams(strs);
  ASSERT_EQ(actual, expected);
}