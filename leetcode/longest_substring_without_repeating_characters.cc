#include "longest_substring_without_repeating_characters.h"

#include <iostream>
#include <set>
using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
  set<char> H;
  int ans = 0;
  for (int i = 0, j = 0; i < s.length(); i++) {
    if (H.count(s[i])) {
      for (; j < i;) {
        H.erase(s[j]);
        if (s[j] == s[i]) {
          j++;
          break;
        }
        j++;
      }
    }
    H.insert(s[i]);
    cout << i << " " << j << " ";
    for (auto c : H) cout << c << " ";
    cout << endl;
    ans = max(ans, (int)H.size());
  }
  return ans;
}