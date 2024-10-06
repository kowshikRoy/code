/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-25
 * Task: 305
 */

#include <bits/stdc++.h>

#include "debug.cpp"
using namespace std;

class Solution {
 public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    map<vector<int>, int> Map;

    int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int cnt = 0;
    vector<int> ans;
    vector<int> P(positions.size());
    iota(P.begin(), P.end(), 0);

    function<int(int)> find = [&](int u) -> int {
      if (P[u] == u) return u;
      return P[u] = find(P[u]);
    };

    for (int i = 0; i < positions.size(); i++) {
      int x = positions[i][0], y = positions[i][1];
      if (Map.count({x, y})) {
        ans.push_back(cnt);
        continue;
      }
      Map[{x, y}] = i;
      cnt++;
      for (int j = 0; j < 4; j++) {
        int xp = x + dir[j][0], yp = y + dir[j][1];
        if (Map.count({xp, yp})) {
          int u = find(i);
          int id2 = Map[{xp, yp}];
          int v = find(id2);
          if (u != v) cnt--;
          P[u] = v;
        }
      }
      ans.push_back(cnt);
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> p = {{0, 1}, {1, 2}, {2, 1}, {1, 0},
                           {0, 2}, {0, 0}, {1, 1}};
  Solution().numIslands2(3, 3, p);
}
