#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using PII = pair<long long, long long>;

const int N = 1e4 + 4;
const long long INF = 1LL << 60;
vector<PII> g[N], r[N];
int n, m;
vector<long long> dij(int s, vector<PII> g[N]) {
    auto comp = [](PII a, PII b) {
        return a.second > b.second;
    };
    priority_queue<PII, vector<PII>, decltype(comp)> pq(comp);
    vector<long long> dis(n + 1, INF);
    vector<bool> vis(n + 1, false);
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (vis[u.first]) continue;
        vis[u.first] = 1;
        for (auto v : g[u.first]) {
            if (dis[v.first] > dis[u.first] + v.second) {
                dis[v.first] = dis[u.first] + v.second;
                pq.push({v.first, dis[v.first]});
            }
        }
    }
    return dis;
}

/*

   Maxflow Dinic Implementation. Work for both directed and Undirected Graph
Complexity : V^2E

 * init(number_of_node)
 * addEdge(from, to, cap)
 * dinitz(source,dest)

 $ MAXNODE : 3000
 $ For Undirected Graph : edge and reverse edge capacity = cap

*/
const int maxn = 10005;
using T = long long;
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
        for (int i = 0; i <= n; i++) G[i].clear();
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
        if (x == t || a == 0) return a;
        T flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            Edge &e = edge[G[x][i]];
            if (d[x] + 1 == d[e.v] &&
                (f = dfs(e.v, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edge[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
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

} maxf;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i <= n; i++) g[i].clear(), r[i].clear();
        for (int i = 0; i < m; i++) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            g[x].push_back({y, c});
            r[y].push_back({x, c});
            edges.push_back(make_tuple(x, y, c));
        }

        auto d1 = dij(1, g);
        auto d2 = dij(n, r);
        if (d1[n] == INF) {
            cout << 0 << endl;
        } else {
            maxf.init(n);
            for (auto e : edges) {
                int x = get<0>(e);
                int y = get<1>(e);
                int c = get<2>(e);
                if (d1[x] + c + d2[y] == d1[n]) { maxf.addEdge(x, y, c); }
            }
            cout << maxf.dinitz(1, n) << endl;
        }
    }
}
