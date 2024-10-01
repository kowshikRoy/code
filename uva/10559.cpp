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
#include <map>
#include <queue>
#include <vector>
using namespace std;

int T;
int n;
int a[204];
int dp[204][204][204];
int vis[204][204][204];
int nxt[204];
vector<int> blocks;
vector<int> counts;

int solve(int l, int r, int cnt) {
  if (l > r) return 0;
  if (vis[l][r][cnt] == T) return dp[l][r][cnt];
  int &ret = dp[l][r][cnt];

  ret = cnt * cnt + solve(l + 1, r, l + 1 < blocks.size() ? counts[l + 1] : 0);

  for (int i = nxt[l]; i <= r; i = nxt[i]) {
    if (blocks[i] == blocks[l]) {
      ret = max(
          ret,
          (cnt + counts[i]) * (cnt + counts[i]) +
              solve(l + 1, i - 1, l + 1 < blocks.size() ? counts[l + 1] : 0) +
              solve(i + 1, r, i + 1 < blocks.size() ? counts[i + 1] : 0));
      ret = max(ret,
                solve(l + 1, i - 1, l + 1 < blocks.size() ? counts[l + 1] : 0) +
                    solve(i, r, cnt + counts[i]));
    }
  }
  vis[l][r][cnt] = T;
  return ret;
}

int main() {
  int t;
  T = 1;
  cin >> t;
  for (int cs = 0; cs < t; cs++, T++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i == 0 || a[i] != a[i - 1]) {
        blocks.push_back(a[i]);
        counts.push_back(1);
      } else
        counts.back()++;
    }
    n = (int)blocks.size();
    map<int, int> pos;
    for (int i = n - 1; i >= 0; i--) {
      if (pos.count(blocks[i]) == 0)
        nxt[i] = n;
      else
        nxt[i] = pos[blocks[i]];
      pos[blocks[i]] = i;
    }

    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", cs + 1, solve(0, n - 1, counts[0]));
    counts.clear();
    blocks.clear();
  }
  return 0;
}
