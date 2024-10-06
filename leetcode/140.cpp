/**
 * Author: Repon Kumar Roy
 * Date: 2021-07-01
 * Task: 140
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words;
    for (auto x : wordDict) words.insert(x);

    vector<string> ret;
    string cur;

    function<void(int)> rec = [&](int idx) -> void {
      if (idx == s.length()) {
        ret.push_back(cur.substr(0, cur.length() - 1));
        return;
      }
      for (int i = idx; i < idx + 10 && i < s.length(); i++) {
        string sub = s.substr(idx, i - idx + 1);
        if (words.find(sub) != words.end()) {
          cur += sub + " ";
          rec(i + 1);
          cur.resize(cur.length() - sub.length() - 1);
        }
      }
    };
    rec(0);
    return ret;
  }
};
