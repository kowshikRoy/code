#include <bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define LL        long long
#define Ulong     unsigned long long
#define REP(i, n) for (long long i = 0; i < n; i++)
#define mp        make_pair
#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define PI        acos(-1.0)
#define EPS       1e-14
#define F         first
#define S         second
#define di(x) \
  int x;      \
  input(x)
#define in(x)               input(x)
#define in2(x, y)           in(x), in(y)
#define in3(x, y, z)        in(x), in2(y, z)
#define lc                  ((n) << 1)
#define rc                  ((n) << 1 | 1)
#define db(x)               cout << #x << " -> " << x << endl
#define nl                  cout << endl
#define ms(ara_name, value) memset(ara_name, value, sizeof(ara_name))
#define IO                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0)
#define READ  freopen("/home/matrixcode/Desktop/in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) { x = (x << 1) + (x << 3) + c - 48; }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}

/***************************** END OF TEMPLATE *******************************/

const int N = 1e6 + 6;
long long a[N], b[N];
int bit[N];

int query(int x) {
  int sum = 0;
  while (x < N) sum += bit[x], x += x & -x;
  return sum;
}
void upd(int x, int v) {
  while (x) bit[x] += v, x -= x & -x;
}
int main() {
  int n;
  while (scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) in(a[i]), b[i] = a[i];
    sort(b, b + n);
    for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + n, a[i]) - b + 1;

    memset(bit, 0, sizeof bit);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += query(a[i]);
      upd(a[i], 1);
    }
    printf("%lld\n", ans);
  }
}
