#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL res, f[4010][2], s1[4010][2], S1[4010][2], s2[4010][2], S2[4010][2], T, n,
    a[4010], b[4010], cnt;
inline LL read() {
  char c;
  LL d = 1, f = 0;
  while (c = getchar(), !isdigit(c))
    if (c == '-') d = -1;
  f = (f << 3) + (f << 1) + c - 48;
  while (c = getchar(), isdigit(c)) f = (f << 3) + (f << 1) + c - 48;
  return d * f;
}
inline LL order(int l, int r, bool k) {
  return S1[r][k] - S1[l - 1][k] - (l - 1) * (s1[r][k] - s1[l - 1][k]);
}  // order表示l到r都去到l-1，k表示是算a的和还是b的和
inline LL rrder(int l, int r, bool k) {
  return S2[l][k] - S2[r + 1][k] - (n - r) * (s2[l][k] - s2[r + 1][k]);
}  // rrder表示l到r都去到r+1，k表示是算a的和还是b的和
inline LL cost(int l, int r, bool k) {
  if (l == 1 && r == n) return 1e18;      //两边都啥都没有
  if (l == 1) return rrder(l, r, k ^ 1);  //左边没有的话，全部都去右边
  if (r == n) return order(l, r, k ^ 1);  //右边没有的话，全部都去左边
  int mid = l + r >> 1;
  return order(l, mid, k ^ 1) +
         rrder(mid + 1, r, k ^ 1);  //否则前一半去左边，后一半去右边
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    s1[0][0] = s1[0][1] = S1[0][0] = S1[0][1] = s2[n + 1][0] = s2[n + 1][1] =
        S2[n + 1][0] = S2[n + 1][1] = 0;  //初始化
    for (register int i = 1; i <= n; i++) {
      a[i] = read();
      b[i] = read();
      f[i][0] = f[i][1] = 1e18;
      s1[i][0] = s1[i - 1][0] + a[i];
      S1[i][0] = S1[i - 1][0] + i * a[i];  //处理a[i]前缀和以及i*a[i]的前缀和
      s1[i][1] = s1[i - 1][1] + b[i];
      S1[i][1] = S1[i - 1][1] + i * b[i];  //处理b[i]前缀和以及i*b[i]的前缀和
    }
    for (register int i = n; i >= 1; i--) {
      s2[i][0] = s2[i + 1][0] + a[i];
      S2[i][0] = S2[i + 1][0] +
                 (n - i + 1) * a[i];  //处理a[i]的后缀和以及(n-i)*a[i]的后缀和
      /*是n-i的原因：这个是倒过来的*/
      s2[i][1] = s2[i + 1][1] + b[i];
      S2[i][1] = S2[i + 1][1] + (n - i + 1) * b[i];
    }
    f[0][0] = f[0][1] = 0;  //初始化
    for (register int i = 1; i <= n; i++)
      for (register int j = 0; j < i; j++)
        for (register int k = 0; k < 2; k++)
          f[i][k] = min(f[i][k], f[j][k ^ 1] + cost(j + 1, i, k));  //动态转移
    printf("Case #%lld: %lld\n", ++cnt, min(f[n][0], f[n][1]));  //记得取最小值
  }
}
