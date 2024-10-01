/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 13095
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;

  while (cin >> n) {
    int p[10][n + 1] = {0};
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 10; j++) p[j][i] = p[j][i - 1];
      p[x][i]++;
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      REP(i, 10) {
        int t = p[i][r] - p[i][l - 1];
        if (t) ans++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
