/*
ID: newcode2
PROG: ride
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

  string s1, s2;

  cin >> s1 >> s2;
  long long ans1 = 1, ans2 = 1;
  for (int i = 0; i < s1.length(); i++) {
    ans1 = (ans1 * (s1[i] - 'A' + 1)) % 47;
  }

  for (int i = 0; i < s2.length(); i++) {
    ans2 = (ans2 * (s2[i] - 'A' + 1)) % 47;
  }

  string ans = (ans1 == ans2) ? "GO" : "STAY";

  cout << ans << endl;
}
