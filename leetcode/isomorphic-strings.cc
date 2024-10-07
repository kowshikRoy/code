#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> mp(128, -1), rp(128, -1);
    for (int i = 0; i < s.length(); i++) {
      int c = s[i], d = t[i];
      if (mp[c] != -1) {
        if (d != mp[c]) return false;
      }
      if (rp[d] != -1) {
        if (c != rp[d]) return false;
      }
      mp[c] = d;
      rp[d] = c;
    }
    return true;
  }
};

#include <gtest/gtest.h>

TEST(IsomorphicStringsTest, Test1) {
  Solution solution;
  string s = "egg";
  string t = "add";
  ASSERT_TRUE(solution.isIsomorphic(s, t));
}

TEST(IsomorphicStringsTest, Test2) {
  Solution solution;
  string s = "foo";
  string t = "bar";
  ASSERT_FALSE(solution.isIsomorphic(s, t));
}

TEST(IsomorphicStringsTest, Test3) {
  Solution solution;
  string s = "paper";
  string t = "title";
  ASSERT_TRUE(solution.isIsomorphic(s, t));
}

TEST(IsomorphicStringsTest, Test4) {
  Solution solution;
  string s = "badc";
  string t = "baba";
  ASSERT_FALSE(solution.isIsomorphic(s, t));
}
