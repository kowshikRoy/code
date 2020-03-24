#include <bits/stdc++.h>
using namespace std;

int n;
double p[20][20];
bool vis[20][1 << 18];
double dp[20][1 << 18];

double solve(int r, int mask) {
  if (vis[r][mask])
    return dp[r][mask];
  if (mask == 0) {
    return r == 0;
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      ans = max(ans, p[r][i] * solve(r, mask ^ (1 << i)) +
                         p[i][r] * solve(i, mask ^ (1 << i)));
    }
  }
  vis[r][mask] = 1;
  dp[r][mask] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> p[i][j];
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  double ans = 0;
  int cnt = 0;
  int mask = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int nmask = mask ^ (1 << i) ^ (1 << j);
      ans = max(ans, p[i][j] * solve(i, nmask) + p[j][i] * solve(j, nmask));
    }
  }

  printf("%.15lf\n", ans);
  return 0;
}
