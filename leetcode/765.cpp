/**
 * Author: Repon Kumar Roy
 * Date: 2021-09-07
 * Task: 765
 */

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

using namespace std;

class Solution {
 public:
  int minSwapsCouples(vector<int> &row) {
    int n = (int)row.size() / 2;
    vector<int> post(n * 2);
    for (int i = 0; i < row.size(); i++) post[row[i]] = i;
    vector<int> dp(1 << n, -1);
    function<int(int)> dfs = [&](int mask) -> int {
      if (mask == (1 << n) - 1) return 0;
      int &ans = dp[mask];
      if (ans != -1) return ans;
      int i = 2 * __builtin_popcount(mask);

      dbg(mask, row, i);

      if (row[i] == (row[i + 1] ^ 1))
        return dp[mask] = dfs(mask | (1 << (row[i] / 2)));

      assert((mask & (1 << (row[i] / 2))) == 0);
      // swap second
      int myCouplePosition = post[row[i] ^ 1];
      swap(row[i + 1], row[myCouplePosition]);
      ans = 1 + dfs(mask | (1 << (row[i] / 2)));
      swap(row[i + 1], row[myCouplePosition]);

      assert((mask & (1 << (row[i + 1] / 2))) == 0);
      myCouplePosition = post[row[i + 1] ^ 1];
      swap(row[i], row[myCouplePosition]);
      ans = min(ans, 1 + dfs(mask | (1 << (row[i + 1] / 2))));
      swap(row[i], row[myCouplePosition]);

      return ans;
    };
    return dfs(0);
  }
};

int main() {
  vector<int> row = {6, 2, 1, 7, 4, 5, 3, 8, 0, 9};
  cout << Solution().minSwapsCouples(row) << endl;
}
