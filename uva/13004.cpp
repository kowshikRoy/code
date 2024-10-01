/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: 13004
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

ll dp[20][2][59049];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  auto to = [](vector<int> &v) -> int {
    int ans = 0;
    for (auto x : v) ans = 3 * ans + x;
    return ans;
  };

  vector<ll> p10(20);
  p10[0] = 1;
  for (int i = 1; i < 20; i++) p10[i] = 10 * p10[i - 1];
  memset(dp, -1, sizeof dp);

  ll u;
  while (cin >> u) {
    vector<int> y;
    auto t = u;
    while (t) y.push_back(t % 10), t /= 10;
    vector<int> v(10);

    function<ll(int, int, int)> dfs = [&](int pos, int f, int z) -> ll {
      if (pos < 0) return 0;
      int num = to(v);
      if (!f && dp[pos][z][num] != -1) return dp[pos][z][num];

      ll ret = -1;
      for (int i = 0; i < 10; i++) {
        if (f && y[pos] < i) continue;
        if (i > 0 || !z) v[i]++;
        if (v[i] > 2) {
          v[i]--;
          continue;
        }
        auto k = dfs(pos - 1, f && (i == y[pos]), z && (i == 0));
        if (k != -1) { ret = max(ret, i * p10[pos] + k); }
        if (i > 0 || !z) v[i]--;
      }
      if (!f) dp[pos][z][num] = ret;
      return ret;
    };

    cout << dfs(y.size() - 1, true, true) << endl;
  }

  return 0;
}
