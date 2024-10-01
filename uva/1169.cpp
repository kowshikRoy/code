/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-28
 * Task: 1169
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 100005;
long long x[N], y[N], v[N];
long long dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int C, n;
    cin >> C;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x[i] >> y[i] >> v[i]; }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      int tot = 0;
      long long dis = 0;
      pair<ll, ll> pre = {0, 0};
      dp[i] = LLONG_MAX;
      for (int j = i; j < n; j++) {
        tot += v[j];
        if (tot > C) break;
        dis += abs(x[j] - pre.first) + abs(y[j] - pre.second) - abs(pre.first) -
               abs(pre.second) + abs(x[j]) + abs(y[j]);
        pre = {x[j], y[j]};
        dp[i] = min(dp[i], dis + dp[j + 1]);
      }
    }
    cout << dp[0] << endl;
    if (t) cout << endl;
  }
}
