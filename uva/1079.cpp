#include <bits/stdc++.h>
using namespace std;

int n;
int _m;
pair<int, int> a[9];
int take[9];

bool dfs(int pre, int taken) {
  if (taken == n)
    return 1;
  for (int i = 0; i < n; i++) {
    if (!take[i] && pre + _m <= a[i].second) {
      take[i] = 1;
      if (dfs(max(pre + _m, a[i].first), taken + 1))
        return 1;
      take[i] = 0;
    }
  }
  return 0;
}

bool can(int m) {
  _m = m;
  memset(take, 0, sizeof take);
  return dfs(-1e9, 0);
}

int main() {
  int cs = 0;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++)
      cin >> a[i].first >> a[i].second, a[i].first *= 120, a[i].second *= 120;

    int low = 0, high = 1440 * 120, mid, ans = 0, turn = 100;
    while (low <= high) {
      mid = (low + high) / 2;
      if (can(mid)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }

    printf("Case %d: %d:%02d\n", ++cs, ans / 120, ((ans % 120) + 1) / 2);
  }
}
