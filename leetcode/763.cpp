/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 763
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int n = (int)s.length();
    vector<int> maxPos(26, -1);
    for (int i = 0; i < n; i++) {
      int v = s[i] - 'a';
      maxPos[v] = max(maxPos[v], i);
    }

    int ptr = 0;
    int last = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i > ptr) {
        ans.push_back(i - last);
        last = i;
      }
      ptr = max(ptr, maxPos[s[i] - 'a']);
    }

    ans.push_back(n - last);
    return ans;
  }
};
