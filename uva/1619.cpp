/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: 1619
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  bool f = false;

  while (cin >> n) {
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> L(n), R(n);
    vector<ll> p(n);
    REP(i, n) {
      int j = i - 1;
      while (j >= 0 && a[j] >= a[i]) j = L[j];
      L[i] = j;
    }
    REP(i, n) {
      if (i) p[i] = p[i - 1];
      p[i] += a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      int j = i + 1;
      while (j < n && a[j] >= a[i]) j = R[j];
      R[i] = j;
    }

    ll ans = -1;
    int A = 1, B = 1;
    REP(i, n) {
      ll now = 1LL * a[i] * (p[R[i] - 1] - (L[i] >= 0 ? p[L[i]] : 0));
      if (now > ans) {
        A = L[i] + 2;
        B = R[i];
        ans = now;
      }
    }

    if (f) cout << endl;
    f = true;

    cout << ans << endl;
    if (ans == 0) A = B = 1;
    cout << A << " " << B << endl;
  }

  return 0;
}
