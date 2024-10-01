/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-28
 * Task: 11034
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
    int len, m;
    cin >> len >> m;
    len *= 100;

    queue<int> L, R;
    REP(i, m) {
      int x;
      string s;
      cin >> x >> s;
      if (s == "left")
        L.push(x);
      else
        R.push(x);
    }

    int t = 0;
    int ans = 0;
    while (L.size() || R.size()) {
      ans++;
      auto &now = t == 0 ? L : R;
      int s = 0;
      while (now.size() && s + now.front() <= len) {
        s += now.front();
        now.pop();
      }
      t ^= 1;
    }
    cout << ans << endl;
  }

  return 0;
}
