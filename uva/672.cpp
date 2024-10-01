/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-05
 * Task: 672
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

struct gang {
  int t, p, s;
};

int n, k, T;
gang g[105];

void solve() {
  cin >> n >> k >> T;
  for (int i = 0; i < n; i++) { cin >> g[i].t; }

  for (int i = 0; i < n; i++) cin >> g[i].p;
  for (int i = 0; i < n; i++) cin >> g[i].s;
  sort(g, g + n, [](gang a, gang b) { return a.t < b.t; });
  int dp[n];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (g[i].t > T) break;
    dp[i] = INT_MIN;
    if (g[i].t >= g[i].s) dp[i] = g[i].p;
    for (int j = 0; j < i; j++) {
      // can i go from j -> i
      if (abs(g[i].t - g[j].t) >= abs(g[i].s - g[j].s))
        dp[i] = max(dp[i], g[i].p + dp[j]);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    if (t) cout << endl;
  }
  return 0;
}
