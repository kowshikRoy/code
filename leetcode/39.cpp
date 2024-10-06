/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 39
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& c, int target) {
    sort(c.begin(), c.end());
    int n = (int)c.size();

    vector<vector<int>> ret;
    vector<int> cur;
    function<void(int, int)> go = [&](int idx, int sum) -> void {
      if (idx == n) return;
      if (sum == target) {
        ret.push_back(cur);
        return;
      }
      if (sum + c[idx] > target) return;
      // don't take
      go(idx + 1, sum);

      // take
      cur.push_back(c[idx]);
      go(idx, sum + c[idx]);
      cur.pop_back();
    };

    go(0, 0);
    return ret;
  }
};
