#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

const int N = 4004;
long long a[N], b[N];
int n, CNT = 1;
long long dp[N][N];
int vis[N][N];
long long pfsum[2][N][N], revpfsum[2][N][N];

long long solve(int A, int B) {
  int cur = max(A, B) + 1;
  if (cur == n + 1) {
    if (A == 0 || B == 0)
      return LLONG_MAX;
    return pfsum[0][A][n] + pfsum[1][B][n];
  }

  long long &ret = dp[A][B];
  if (vis[A][B] == CNT)
    return dp[A][B];
  vis[A][B] = CNT;
  ret = LLONG_MAX;

  // pick A
  if (A == 0) {
    ret = min(ret, revpfsum[0][cur][1] + solve(cur, B));
  } else {
    int F = (cur + A) / 2;
    ret = min(ret, pfsum[0][A][F] + revpfsum[0][cur][F + 1] + solve(cur, B));
  }

  // pick B
  if (B == 0) {
    ret = min(ret, revpfsum[1][cur][1] + solve(A, cur));
  } else {
    int F = (cur + B) / 2;
    ret = min(ret, pfsum[1][B][F] + revpfsum[1][cur][F + 1] + solve(A, cur));
  }
  return ret;
}

int main() {
  int t, cs = 0;
  cin >> t;

  while (t--) {
      scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld %lld", &a[i], &b[i]);

    for (int i = 1; i <= n; i++)
      pfsum[0][i][i] = 0, revpfsum[0][i][i] = 0L, pfsum[1][i][i] = 0,
      revpfsum[1][i][i] = 0L;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        pfsum[0][i][j] = pfsum[0][i][j - 1] + a[j] * (j - i);
        pfsum[1][i][j] = pfsum[1][i][j - 1] + b[j] * (j - i);
      }
    }

    for (int i = n; i >= 1; i--) {
      for (int j = i - 1; j >= 1; j--) {
        revpfsum[0][i][j] = revpfsum[0][i][j + 1] + a[j] * (i - j);
        revpfsum[1][i][j] = revpfsum[1][i][j + 1] + b[j] * (i - j);
      }
    }

    printf("Case #%d: %lld\n", ++cs, solve(0, 0));
    CNT++;
  }
}
