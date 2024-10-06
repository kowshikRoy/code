#include "find-the-difference.h"

#include <string>
#include <iostream>

char Solution::findTheDifference(std::string s, std::string t) {
  int mp[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    mp[s[i] - 'a']++;
  }
  for (int i = 0; i < t.length(); i++) {
    mp[t[i] - 'a']--;
    if (mp[t[i] - 'a'] < 0) return t[i];
  }
  return 0;
}