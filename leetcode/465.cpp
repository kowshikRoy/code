/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-28
 * Task: 465
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  vector<long long> debt;
  int dfs(int s) {
    if (s == debt.size()) return 0;
    if (debt[s] == 0) return dfs(s + 1);
    int res = INT_MAX;
    for (int i = s + 1; i < debt.size(); i++) {
      if (debt[i] * debt[s] < 0) {
        auto p = debt[s];
        debt[i] += debt[s];
        res = min(res, 1 + dfs(s + 1));
        debt[i] -= debt[s];
      }
    }
    return res;
  }

 public:
  int minTransfers(vector<vector<int>>& transactions) {
    unordered_map<int, int> b;
    for (auto t : transactions) {
      b[t[0]] += t[2];
      b[t[1]] -= t[2];
    }
    for (auto x : b)
      if (x.second) debt.push_back(x.second);
    return dfs(0);
  }
};
