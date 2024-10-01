/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-07
 * Task: 10559
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int a[204], nxt[204], pos[204];
int dp[204][204][204];

int solve(int l, int r, int cnt) {
  if (l > r) return 0;
  int &ret = dp[l][r][cnt];
  if (ret != -1) return ret;
  ret = solve(l + 1, r, 0) + (cnt + 1) * (cnt + 1);
  for (int i = nxt[l]; i <= r; i = nxt[i]) {
    if (a[i] == a[l]) {
      ret = max(ret, solve(l + 1, i - 1, 0) + solve(i, r, cnt + 1));
    }
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  for (int cs = 0; cs < t; cs++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], pos[i + 1] = n;
    for (int i = n - 1; i >= 0; i--) {
      nxt[i] = pos[a[i]];
      pos[a[i]] = i;
    }
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", cs + 1, solve(0, n - 1, 0));
  }
  return 0;
}
