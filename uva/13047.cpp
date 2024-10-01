/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-25
 * Task: 13047
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
    string s;
    cin >> s;
    int n = (int)s.size();
    int ans = -1;

    auto isArrow = [&](string s) -> bool {
      if (s[0] == '<') {
        set<char> se;
        for (int i = 1; i < s.size(); i++) se.insert(s[i]);
        if (se.size() == 0) return true;
        if (se.size() > 1) return false;
        return *se.begin() == '-' || *se.begin() == '=';
      } else if (s.back() == '>') {
        set<char> se;
        for (int i = 0; i + 1 < s.size(); i++) se.insert(s[i]);
        if (se.size() == 0) return true;
        if (se.size() > 1) return false;
        return *se.begin() == '-' || *se.begin() == '=';
      }
      return false;
    };

    for (int i = 0; i < n; i++) {
      string sub;
      for (int j = i; j < n; j++) {
        sub.push_back(s[j]);
        if (isArrow(sub)) ans = max(ans, (int)sub.length());
      }
    }
    cout << "Case " << ++cs << ": " << ans << endl;
  }

  return 0;
}
