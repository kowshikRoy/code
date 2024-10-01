/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 12862
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, f;

  while (cin >> n >> f) {
    vector<vector<array<int, 2>>> g(n + 1);
    REP(i, n - 1) {
      int a, b, c;
      cin >> a >> b >> c;
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }

    vector<bool> friends(n + 1);
    REP(i, f) {
      int a;
      cin >> a;
      friends[a] = 1;
    }

    // dp[i] -> starts at the subtree rooted at i visit all the child and
    // finish at some node
    // sub[i] -> total cost to start and finish at subtree rooted at i
    const int inf = INT_MAX / 4;
    vector<int> dp(n + 1, inf);
    vector<int> sub(n + 1, 0);
    vector<int> must(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int p) -> void {
      int sum = 0;
      bool isLeaf = true;

      for (auto v : g[u])
        if (v[0] != p) {
          dfs(v[0], u);
          if (must[v[0]]) sum += v[1] + sub[v[0]];
          isLeaf = false;
          must[u] |= must[v[0]];
        }
      sub[u] = sum;
      if (isLeaf || !must[u]) {
        dp[u] = 0;
        sub[u] = 0;
        must[u] |= friends[u];
        return;
      }

      int ret = inf;
      for (auto v : g[u])
        if (v[0] != p && must[v[0]]) {
          ret = min(ret, sum - (v[1] + sub[v[0]]) + dp[v[0]]);
        }
      dp[u] = ret;
    };
    dfs(1, -1);
    cout << dp[1] << endl;
  }

  return 0;
}
