#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H;
  if (sizeof...(T)) cerr << ", ";
  dbg_out(T...);
}
#define dbg(...)                                                     \
  cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
      dbg_out(__VA_ARGS__)

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    istringstream iss(s);
    string word;
    int ptr = 0;
    vector<string> v(26);
    vector<string> words;
    unordered_map<string, char> mp;
    while (iss >> word) words.push_back(word);
    if (pattern.size() != words.size()) return false;
    for (auto word : words) {
      char c = pattern[ptr];

      if (v[c - 'a'].empty() && mp.find(word) == mp.end()) {
        v[c - 'a'] = word;
        mp[word] = c;
      } else if (v[c - 'a'] != word || mp[word] != c) {
        return false;
      }
      ptr++;
    }
    return true;
  }
};

#include <gtest/gtest.h>

TEST(WordPattern, test1) {
  Solution solution;
  string pattern = "abba";
  string s = "dog cat cat dog";
  ASSERT_TRUE(solution.wordPattern(pattern, s));
}

TEST(WordPattern, test2) {
  Solution solution;
  string pattern = "abba";
  string s = "dog cat cat fish";
  ASSERT_FALSE(solution.wordPattern(pattern, s));
}

TEST(WordPattern, test3) {
  Solution solution;
  string pattern = "aaaa";
  string s = "dog cat cat dog";
  ASSERT_FALSE(solution.wordPattern(pattern, s));
}

TEST(WordPattern, test4) {
  Solution solution;
  string pattern = "abba";
  string s = "dog dog dog dog";
  ASSERT_FALSE(solution.wordPattern(pattern, s));
}

TEST(WordPattern, test5) {
  Solution solution;
  string pattern = "aba";
  string s = "dog cat cat";
  ASSERT_FALSE(solution.wordPattern(pattern, s));
}

TEST(WordPattern, test6) {
  Solution solution;
  string pattern = "aaa";
  string s = "aa aa aa aa";
  ASSERT_FALSE(solution.wordPattern(pattern, s));
}