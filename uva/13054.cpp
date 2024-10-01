/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-25
 * Task: 13054
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
    int n, H, ta, tb;
    cin >> n >> H >> ta >> tb;
    vector<int> h(n);
    REP(i, n) cin >> h[i];

    cout << "Case " << ++cs << ": ";

    if (2 * ta <= tb) {
      cout << ta * n << endl;
      continue;
    }

    sort(h.begin(), h.end());
    int l = 0;
    int ans = 0;
    int taken = 0;
    for (int i = n - 1; i >= 0 && i > l; i--) {
      if (h[i] + h[l] < H) {
        ans += tb;
        taken += 2;
        l++;
      }
    }
    ans += ta * (n - taken);
    cout << ans << endl;
  }
  return 0;
}
