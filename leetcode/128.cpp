/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 128
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> H;
    int ans = 0;
    for (auto n : nums) H.insert(n);
    for (auto n : nums) {
      if (H.count(n) == 0) continue;
      int r = n + 1, l = n - 1;
      while (H.count(r)) {
        H.erase(r);
        r++;
      }
      while (H.count(l)) {
        H.erase(l);
        l--;
      }
      ans = max(ans, r - l - 1);
    }
    return ans;
  }
};
