/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: 12321
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll L, n;

  while (cin >> L >> n) {
    if (!L && !n) break;
    vector<array<int, 2>> g(n);
    REP(i, n) cin >> g[i][0] >> g[i][1];
    sort(g.begin(), g.end(), [](array<int, 2> a, array<int, 2> b) {
      return a[0] + a[1] < b[0] + b[1];
    });

    vector<pair<ll, int>> dp;

    dp.push_back({0, 0});
    REP(i, n) {
      ll l = g[i][0] - g[i][1];
      ll r = g[i][0] + g[i][1];
      auto p = lower_bound(dp.begin(), dp.end(), make_pair(l, -1));
      if (p == dp.end()) { continue; }

      while (dp.size() && dp.back().second > 1 + p->second) { dp.pop_back(); }
      dp.push_back({r, 1 + p->second});
    }

    ll ans = -1;
    for (auto x : dp) {
      if (x.first >= L) ans = max(ans, n - x.second);
    }
    cout << ans << endl;
  }

  return 0;
}
