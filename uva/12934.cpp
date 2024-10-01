/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: 12934
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, cs = 0;

  while (cin >> k) {
    cout << "Case " << ++cs << ": ";
    if (k == 1) {
      cout << "Impossible" << endl;
      continue;
    }
    int A = k, B = k - 1;
    bool f = false;
    for (int i = 2; i * (i - 1) <= k && !f; i++) {
      ll m = 1;
      for (int j = i; j > 1 && m < k; j--) {
        m *= j;
        if (m == k) {
          A = i;
          B = j - 1;
          f = true;
          break;
        }
      }
    }
    cout << A << " " << B << endl;
  }
  return 0;
}
