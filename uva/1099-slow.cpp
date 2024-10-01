#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;
int p[16];
int tot[1 << 15];
bool dp[1 << 15][101];
int vis[1 << 15][101];
int cnt = 1;

bool solve(int mask, int x, int y) {
  if (!(mask & (mask - 1))) { return tot[mask] == x * y; }
  if (vis[mask][x] == cnt) return dp[mask][x];
  int ret = false;
  for (int i = 1; i < x && !ret; i++) {
    for (int j = mask; j && !ret; j = (j - 1) & mask) {
      if (tot[j] == i * y) {
        ret |= solve(j, i, y) & solve(mask ^ j, x - i, y);
      }
    }
  }
  for (int i = 1; i < y && !ret; i++) {
    for (int j = mask; j && !ret; j = (j - 1) & mask) {
      if (tot[j] == x * i) {
        ret |= solve(j, x, i) & solve(mask ^ j, x, y - i);
      }
    }
  }
  vis[mask][x] = cnt;
  return dp[mask][x] = ret;
}

int main() {
  int cs = 0;
  while (scanf("%d", &n) == 1 && n) {
    scanf("%d %d", &x, &y);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
      sum += p[i];
    }
    for (int i = 0; i < 1 << n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) sum += p[j];
      tot[i] = sum;
    }

    if (sum != x * y) {
      printf("Case %d: No\n", ++cs);
    } else
      printf("Case %d: %s\n", ++cs, solve((1 << n) - 1, x, y) ? "Yes" : "No");
    cnt++;
  }
}
