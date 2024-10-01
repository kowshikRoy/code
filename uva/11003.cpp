/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 11003
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<pair<int, int>> A(n);
    REP(i, n) cin >> A[i].first >> A[i].second;

    int dp[3001] = {0};
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = A[i].second; j >= 0; j--) {
        ans = max(ans, 1 + dp[j]);
        int nw = j + A[i].first;
        if (nw <= 3000) dp[nw] = max(dp[nw], 1 + dp[j]);
      }
    }
    cout << ans << endl;
  }

  return 0;
}
