#include <bits/stdc++.h>
using namespace std;

#define MAX 20001
#define NIL 0
#define INF (1 << 28)

vector<int> G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for (i = 1; i <= n; i++) {
        if (match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        } else
            dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u != NIL) {
            for (auto &v : G[u])
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u) {
    int i, v, len;
    if (u != NIL) {
        for (auto v : G[u])
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    memset(match, NIL, sizeof match);
    while (bfs()) {
        for (i = 1; i <= n; i++)
            if (match[i] == NIL && dfs(i)) matching++;
    }
    return matching;
}

/* Code by Zobayer Hasan */

int vis[10001];
set<int> s;

void gen(int a) {
    if (vis[a]) return;
    vis[a] = 1;
    s.insert(a);
    for (int t = a; t; t -= t & -t) {
        int x = t & -t;
        if (a + x <= n) {
            G[a].push_back(n + a + x);
            gen(a + x);
        }
    }
}

int main() {
    int t, cs = 0, l, v;
    cin >> t;
    while (t--) {
        cin >> v >> l;
        m = l;
        n = l;
        s.clear();
        for (int i = 1; i <= l; i++) G[i].clear(), vis[i] = 0;
        for (int i = 0; i < v; i++) {
            int a;
            cin >> a;
            gen(a);
        }
        int p = hopcroft_karp();
        printf("Case %d: %d\n", ++cs, s.size() - p);
    }
}
