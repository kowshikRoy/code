#include "first-unique-character-in-a-string.h"

#include <iostream>
#include <string>

int Solution::firstUniqChar(std::string s) {
  int mp[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    mp[s[i] - 'a']++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (mp[s[i] - 'a'] == 1) return i;
  }
  return -1;
}