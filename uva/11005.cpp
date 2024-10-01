/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-24
 * Task: 11005
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
    vector<int> c(36);
    REP(i, 36) cin >> c[i];

    auto cost = [&](int n, int b) -> ll {
      if (n == 0) return c[0];
      ll sum = 0;
      while (n > 0) sum += c[n % b], n /= b;
      return sum;
    };
    if (cs) cout << endl;
    cout << "Case " << ++cs << ":" << endl;
    int q;
    cin >> q;
    while (q--) {
      int n;
      cin >> n;
      ll min_cost = LLONG_MAX;
      vector<int> out;
      for (int i = 2; i <= 36; i++) {
        auto cur_cost = cost(n, i);
        if (cur_cost < min_cost) {
          min_cost = cur_cost;
          out.clear();
          out.push_back(i);
        } else if (cur_cost == min_cost)
          out.push_back(i);
      }
      cout << "Cheapest base(s) for number " << n << ":";
      for (auto x : out) cout << " " << x;
      cout << endl;
    }
  }
  return 0;
}
