/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-13
 * Task: 12840
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
    int n, s;
    cin >> n >> s;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];
    sort(coin.begin(), coin.end());

    const int inf = 1 << 28;
    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    vector<vector<int>> pa(n, vector<int>(s + 1, -1));

    function<int(int, int)> solve = [&](int i, int p) -> int {
      if (p < 0) return inf;
      if (i < 0) return (p == 0 ? 0 : inf);
      if (dp[i][p] != -1) return dp[i][p];
      // not taking current item
      int r1 = solve(i - 1, p);
      // taking current item
      int r2 = 1 + solve(i, p - coin[i]);
      if (r2 <= r1) {
        pa[i][p] = 1;
        return dp[i][p] = r2;
      } else {
        pa[i][p] = 0;
        return dp[i][p] = r1;
      }
    };

    int k = solve(n - 1, s);
    if (k <= s) {
      printf("Case %d: [%d]", ++cs, k);
      int i = n - 1, p = s;
      while (i >= 0) {
        int t = pa[i][p];
        if (t) {
          printf(" %d", coin[i]);
          p -= coin[i];
        } else
          i--;
      }
      printf("\n");

    } else {
      printf("Case %d: impossible\n", ++cs);
    }
  }

  return 0;
}
