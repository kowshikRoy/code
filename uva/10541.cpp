#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H;
  if (sizeof...(T)) cerr << ", ";
  dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                     \
  cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 10541
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
    int n, a;
    cin >> n >> a;
    dbg(n, a);
    vector<int> v;
    while (a--) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    if (v.size() == 0) {
      cout << 1 << endl;
      continue;
    }

    int m = (int)v.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = v[0]; i <= n; i++) dp[0][i] = 1;
    dbg(dp[0]);
    for (int i = 1; i < m; i++) {
      for (int j = v[i] + 1; j <= n; j++) {
        dp[i][j] = 0;
        for (int k = j - v[i] - 1; k >= 0; k--) dp[i][j] += dp[i - 1][k];
      }
      dbg(dp[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans += dp[m - 1][i];
    cout << ans << endl;
  }

  return 0;
}
