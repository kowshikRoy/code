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

/*
 * Tarjan's Algorithm to find SCC of a directed Graph
 * Complexity: O(V+E)
 *
 * Usage:
 * - init(n) : n is #nodes, 0 indexed
 * - add(u,v): Adds a directed edge from u to v
 * - doscc() : Processes the graph and finds out SCC of the graph
 */

struct scc {
  vector<vector<int>> g;
  vector<int> scc, low, ind;
  int n, T, col;
  void init(int _n) {
    n = _n, T = 0, col = 0;
    g.clear();
    g.resize(n);
    scc.assign(n, -1);
    low.assign(n, -1);
    ind.assign(n, -1);
  }

  void add(int u, int v) { g[u].push_back(v); }

  vector<int> stk;
  void dfs(int u) {
    low[u] = ind[u] = ++T;
    stk.push_back(u);

    for (auto v : g[u]) {
      if (ind[v] == -1) dfs(v);
      if (scc[v] == -1) low[u] = min(low[u], low[v]);
    }

    if (ind[u] == low[u]) {
      int t;
      do {
        t = stk.back();
        stk.pop_back();
        scc[t] = col;
      } while (t != u);
      col++;
    }
  }
  void doscc() {
    for (int i = 0; i < n; i++)
      if (ind[i] == -1) dfs(i);
  }
};

int main() {
  scc s;
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    s.init(n);
    for (int i = 0; i < m; i++) {
      int k;
      int u, v;
      /* scanf("%d", &k); */
      in(k);
      if (k == 1) {
        /* scanf("%d %d", &u, &v); */
        in2(u, v);
        s.add(u - 1, v - 1);
      } else {
        int pre = -1, first = -1;
        for (int j = 0; j < k; j++) {
          /* scanf("%d", &u); */
          in(u);
          if (pre == -1)
            first = u;
          else
            s.add(pre - 1, u - 1);
          pre = u;
        }
        s.add(pre - 1, first - 1);
      }
    }
    s.doscc();
    printf("%s\n", s.col == 1 ? "YES" : "NO");
  }
}
