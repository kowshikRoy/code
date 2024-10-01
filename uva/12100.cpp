/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-29
 * Task: 12100
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
    int n, m;
    cin >> n >> m;
    deque<pair<int, int>> dq;
    REP(i, n) {
      int x;
      cin >> x;
      dq.push_back({x, i});
    }
    int cnt = 0;
    while (true) {
      auto u = dq.front();
      dq.pop_front();
      bool highest = true;
      for (auto x : dq)
        if (x.first > u.first) {
          highest = false;
          break;
        }
      if (highest) {
        cnt++;
        if (u.second == m) break;
      } else
        dq.push_back(u);
    }
    cout << cnt << endl;
  }

  return 0;
}
