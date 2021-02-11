#include <bits/stdc++.h>
using namespace std;

char g[55][55];
int dp[55][55][1005];

int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int check(int d, char c) {
  if (d == 0 && c == 'U')
    return 0;
  if (d == 1 && c == 'L')
    return 0;
  if (d == 2 && c == 'D')
    return 0;
  if (d == 3 && c == 'R')
    return 0;
  return 1;
}
int main() {
  int n, m, K;
  int x, y;
  cin >> n >> m >> K;
  for (int i = 0; i < n; i++)
    cin >> g[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (g[i][j] == '*')
        x = i, y = j;
  }

  memset(dp, 63, sizeof dp);
  dp[x][y][0] = 0;

  for (int k = 0; k < K; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == x && y == j)
          continue;
        for (int d = 0; d < 4; d++) {
          int xp = i + dir[d][0], yp = j + dir[d][1];
          if (xp >= 0 && xp < n && yp >= 0 && yp < m && dp[xp][yp][k] < K) {
            dp[i][j][k + 1] =
                min(dp[i][j][k + 1], dp[xp][yp][k] + check(d, g[i][j]));
          }
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i <= K; i++)
    ans = min(ans, dp[0][0][i]);
  if (ans > K)
    cout << -1 << endl;
  else
    cout << ans;
}
