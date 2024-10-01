/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-08
 * Task: 1263
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct node {
  int x, y, d;
};

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
void solve() {
  int n;
  cin >> n;
  node p[n];
  vector<int> g[n];
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> p[i].d;
  sort(p, p + n, [](node a, node b) { return a.d < b.d; });
  auto can = [&](int i, int j) -> bool {
    return 2 * p[j].x >= 2 * p[i].x - p[i].d &&
           2 * p[j].x <= 2 * p[i].x + p[i].d &&
           2 * p[j].y >= 2 * p[i].y - p[i].d &&
           2 * p[j].y <= 2 * p[i].y + p[i].d;
  };

  scc s;
  s.init(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && can(i, j)) {
        g[i].push_back(j);
        s.add(i, j);
      }

  s.doscc();
  set<int> T[s.col];
  vector<int> deg(s.col);
  vector<int> vis(s.col);
  for (int i = 0; i < n; i++) {
    for (auto v : g[i]) {
      int x = s.scc[i];
      int y = s.scc[v];
      if (x != y) T[x].insert(y);
    }
  }
  for (int i = 0; i < s.col; i++) {
    for (auto v : T[i]) { deg[v]++; }
  }

  auto bfs = [&](int u) -> void {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      for (auto v : T[u])
        if (!vis[v]) q.push(v);
    }
  };
  int ans = 0;
  for (int i = 0; i < s.col; i++) {
    if (deg[i] == 0) {
      ans++;
      bfs(i);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
