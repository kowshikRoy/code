/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: 13245
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 550;
bool vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> prime;
  prime.push_back(1);
  for (int i = 2; i < N; i++) {
    if (vis[i] == 0) {
      prime.push_back(i);
      if (prime.size() > 100) break;
    }
    for (int j = i; j < N; j += i) vis[j] = 1;
  }

  vector<vector<int>> dp(101, vector<int>(5001, 10000000));
  for (int i = 0; i <= 5000; i++) dp[0][i] = i;
  for (int i = 1; i < prime.size(); i++) {
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= prime[i]) dp[i][j] = min(dp[i][j], 1 + dp[i][j - prime[i]]);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    cout << dp[n - 1][q] << endl;
  }

  return 0;
}
