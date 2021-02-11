#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
int n, k;
PII v[55];
int dp[50][50][2500];

int solve(int i, int k, int h) {
  if (i == n || k == 0)
    return 0;
  int &ret = dp[i][k][h];
  if (ret != -1)
    return ret;

  ret = max(solve(i + 1, k, h), 2 * v[i].first * h + v[i].first * v[i].second +
                                    solve(i + 1, k - 1, h + v[i].second));
  return ret;
}

int main() {
  int t, cs = 0;
  cin >> t;
  while (t--) {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }
    sort(v, v + n,
         [](PII a, PII b) { return a.second * b.first > a.first * b.second; });

    printf("Case %d: %d\n", ++cs, solve(0, k, 0));
  }
}
