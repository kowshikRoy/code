/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-25
 * Task: 200
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& g) {
    if (g.empty()) return 0;
    int n = (int)g.size(), m = (int)g[0].size(), cnt = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    function<void(int x, int y)> dfs = [&](int x, int y) -> void {
      if (vis[x][y]) return;
      vis[x][y] = 1;
      for (int i = 0; i < 4; i++) {
        int xp = x + dir[i][0], yp = y + dir[i][1];
        if (xp >= 0 && xp < n && yp >= 0 && yp < m && g[xp][yp] == '1')
          dfs(xp, yp);
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] == 0 && g[i][j] == '1') dfs(i, j), cnt++;
      }
    }
    return cnt;
  }
};
