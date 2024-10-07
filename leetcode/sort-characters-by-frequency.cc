#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<int, int> mp;
    for (auto c : s) {
      mp[c]++;
    }

    vector<pair<int, int>> vec;
    for (auto [k, v] : mp) vec.push_back({k, v});
    sort(vec.begin(), vec.end(), [](auto a, auto b) {
      return (a.second == b.second) ? a.first < b.first : a.second > b.second;
    });
    string ans;
    for (auto [k, v] : vec) {
      while (v--) ans += k;
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(SortCharactersByFrequency, Test1) {
  Solution solution;
  string s = "tree";
  string expected = "eert";
  string actual = solution.frequencySort(s);
  ASSERT_EQ(actual, expected);
}

TEST(SortCharactersByFrequency, Test2) {
  Solution solution;
  string s = "cccaaa";
  string expected = "aaaccc";
  string actual = solution.frequencySort(s);
  ASSERT_EQ(actual, expected);
}

TEST(SortCharactersByFrequency, Test3) {
  Solution solution;
  string s = "Aabb";
  string expected = "bbAa";
  string actual = solution.frequencySort(s);
  ASSERT_EQ(actual, expected);
}
