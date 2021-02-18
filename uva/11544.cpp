#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int INF = 1e9;
typedef int T;
struct Edge {
  int u, v;
  T cap, flow;
  Edge(int u, int v, T c, T f) : u(u), v(v), cap(c), flow(f) {}
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edge;
  vector<int> G[maxn];
  bool vis[maxn];
  int d[maxn];
  int cur[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; i++)
      G[i].clear();
    edge.clear();
  }

  void addEdge(int u, int v, T cap) {
    edge.push_back(Edge(u, v, cap, 0));
    edge.push_back(Edge(v, u, 0, 0));
    m = edge.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }

  bool bfs() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = edge[G[x][i]];
        if (!vis[e.v] && e.cap > e.flow) {
          vis[e.v] = true;
          d[e.v] = d[x] + 1;
          q.push(e.v);
        }
      }
    }
    return vis[t];
  }

  T dfs(int x, T a) {
    if (x == t || a == 0)
      return a;
    T flow = 0, f;
    for (int &i = cur[x]; i < G[x].size(); i++) {
      Edge &e = edge[G[x][i]];
      if (d[x] + 1 == d[e.v] && (f = dfs(e.v, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edge[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0)
          break;
      }
    }
    return flow;
  }

  T dinitz(int s, int t) {
    this->s = s;
    this->t = t;
    T flow = 0;
    while (bfs()) {
      memset(cur, 0, sizeof cur);
      flow += dfs(s, INF);
    }
    return flow;
  }
};

int main() {
  int t, cs = 0, n, m;
  int p[55];
  cin >> t;
  while (t--) {
    cin >> n >> m;
    Dinic mf;
    int S = 0, T = n + m + 1;
    mf.init(T);

    for (int i = 1; i <= m; i++)
      cin >> p[i], mf.addEdge(n + i, T, p[i]);
    for (int i = 1; i <= n; i++)
      mf.addEdge(0, i, 1);
    vector<vector<int>> choice(n + 1);

    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int a;
        cin >> a;
        choice[i].push_back(a);
        mf.addEdge(i, n + a, 1);
      }
    }
    int maxFlow = mf.dinitz(0, T);
    printf("Case #%d:\n", ++cs);
    printf("%d applicant(s) can be hired.\n", maxFlow);
    vector<pair<int, int>> match;

    for (int a = 1; a <= n; a++) {
      for (auto b : choice[a]) {
        if (p[b] == 0)
          continue;
        p[b]--;
        for (int i = 1; i <= m; i++)
          if (p[i] > 0)
            mf.addEdge(n + i, T, p[i]);
        for (int i = a + 1; i <= n; i++) {
          mf.addEdge(0, i, 1);
          for (auto x : choice[i]) {
            mf.addEdge(i, n + x, 1);
          }
        }
        int maxf = mf.dinitz(0, T);
        if (maxf + match.size() + 1 == maxFlow) {
          match.push_back({a, b});
          break;
        } else
          p[b]++;
      }
    }

    for (auto p : match)
      cout << p.first << " " << p.second << endl;
  }
}
