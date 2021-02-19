#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[101];
int d[101][101];
int dis[101];
bool vis[101];
struct Node {
    int u, c;
    bool operator<(const Node &rhs) const { return c > rhs.c; }
};
int dij(int s, int t) {
    priority_queue<Node> pq;
    memset(dis, 63, sizeof dis);
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.u == t) return cur.c;
        if (vis[cur.u]) continue;
        for (auto next : g[cur.u]) {
            if (vis[next.first] == 0 && dis[next.first] > cur.c + next.second) {
                pq.push({next.first, cur.c + next.second});
                dis[next.first] = cur.c + next.second;
            }
        }
    }
    return -1;
}
int main() {
    int n, m, bh, of, yh, market;
    while (cin >> n >> m >> bh >> of >> yh >> market) {
        memset(d, 63, sizeof d);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            d[a][b] = d[b][a] = c;
            g[b].push_back({a, c});
            g[a].push_back({b, c});
        }
        for (int i = 1; i <= n; i++) d[i][i] = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        for (int i = 1; i <= n; i++) {
            if (d[bh][i] + d[i][of] == d[bh][of]) vis[i] = 1;
        }
        vis[of] = 1;
        vis[bh] = 1;
        int v = dij(yh, market);
        if (vis[yh] || vis[market] || v == -1) printf("MISSION IMPOSSIBLE.\n");
        else
            printf("%d\n", v);

        for (int i = 1; i <= n; i++) g[i].clear();
    }
}
