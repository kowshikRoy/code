/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 11795
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, cs = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string m;
    vector<string> at(n);
    cin >> m;
    REP(i, n) cin >> at[i];

    vector<ll> dp(1 << n, -1);
    auto can = [&](int mask, int e) -> bool {
      if (m[e] == '1') return true;
      REP(i, n) {
        if (((mask >> i) & 1) == 0) {
          if (at[i][e] == '1') return true;
        }
      }
      return false;
    };
    function<ll(int)> dfs = [&](int mask) -> ll {
      if (mask == 0) return 1;
      if (dp[mask] != -1) return dp[mask];

      ll ret = 0;
      REP(i, n) {
        if (((mask >> i) & 1) && can(mask, i)) {  // not killed
          ret += dfs(mask ^ (1 << i));
        }
      }
      return dp[mask] = ret;
    };

    cout << "Case " << ++cs << ": " << dfs((1 << n) - 1) << endl;
  }

  return 0;
}
