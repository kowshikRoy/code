/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 13197
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, p;
  while (cin >> a >> p) {
    bool f = false;
    REP(i, p) if ((i * i * i) % p == a) {
      if (f) cout << " ";
      cout << i;
      f = 1;
    }
    cout << endl;
  }

  return 0;
}
