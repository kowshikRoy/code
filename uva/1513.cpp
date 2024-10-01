/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-28
 * Task: 1513
 */

#include <bits/stdc++.h>
using namespace std;

#define LL           long long
#define Ulong        unsigned long long
#define REP(i, n)    for (long long i = 0; i < n; i++)
#define mp           make_pair
#define pb           push_back
#define all(x)       (x).begin(), (x).end()
#define PI           acos(-1.0)
#define EPS          1e-14
#define F            first
#define S            second
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
#define lc           ((n) << 1)
#define rc           ((n) << 1 | 1)
#define db(x)        cout << #x << " -> " << x << endl

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

/********************************************************/

vector<int> T, pos;
void upd(int n, int b, int e, int pos, int v) {
  if (b > pos || e < pos) return;
  if (b == e) {
    T[n] += v;
    return;
  }
  int mid = (b + e) / 2;
  upd(lc, b, mid, pos, v);
  upd(rc, mid + 1, e, pos, v);
  T[n] = T[lc] + T[rc];
}

int query(int n, int b, int e, int pos) {
  if (b == e) { return T[n]; }
  int mid = (b + e) / 2;
  if (pos <= mid)
    return query(lc, b, mid, pos);
  else
    return T[lc] + query(rc, mid + 1, e, pos);
}

int main() {
  int t, n, m;
  in(t);
  while (t--) {
    in2(n, m);
    T.resize((n + m) * 4);
    pos.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      pos[i] = m + i;
      upd(1, 1, n + m, pos[i], 1);
    }
    int ptr = m;
    for (int i = 1; i <= m; i++) {
      int x;
      in(x);
      printf("%d%c", query(1, 1, n + m, pos[x]) - 1, i == m ? '\n' : ' ');
      upd(1, 1, n + m, pos[x], -1);
      pos[x] = ptr--;
      upd(1, 1, n + m, pos[x], 1);
    }
    T.clear();
  }
  return 0;
}
