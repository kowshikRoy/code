/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-30
 * Task: 608
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string a[3], b[3], c[3];
    REP(i, 3) cin >> a[i] >> b[i] >> c[i];
    int N = 12;
    vector<int> w(N);

    auto calc = [&](string s) -> int {
      int ans = 0;
      for (auto x : s) ans += w[x - 'A'];
      return ans;
    };
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
      for (int j = 0; j <= 2 && !found; j += 2) {
        for (int k = 0; k < N; k++) w[k] = 1;
        w[i] = j;
        bool flag = true;
        REP(p, 3) {
          int u = calc(a[p]), v = calc(b[p]);
          if (u == v && c[p] != "even") flag = false;
          if (u > v && c[p] != "up") flag = false;
          if (u < v && c[p] != "down") flag = false;
        }
        if (flag) {
          printf("%c is the counterfeit coin and it is %s.\n", 'A' + i,
                 j == 0 ? "light" : "heavy");
          found = true;
          break;
        }
      }
    }
  }
  return 0;
}
