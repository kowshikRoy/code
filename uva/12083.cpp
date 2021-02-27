/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-27
 * Task: 12083
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int h[N];
char g[N];
string music[N], s[N];

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

bool notMatch(int i, int j) {
    if (!((abs(h[i] - h[j]) > 40) || (g[i] == g[j]) || (music[i] != music[j]) ||
          (s[i] == s[j])))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int stu;
        vector<int> Male, Female;
        cin >> stu;
        for (int i = 1; i <= stu; i++) {
            cin >> h[i] >> g[i] >> music[i] >> s[i];
            if (g[i] == 'M') Male.push_back(i);
            else
                Female.push_back(i);
        }
        n = Male.size(), m = Female.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = Male[i], v = Female[j];
                if (notMatch(u, v)) { G[i + 1].push_back(n + j + 1); }
            }
        }
        cout << (stu - hopcroft_karp()) << endl;
        for (int i = 1; i <= n; i++) G[i].clear();
    }
}
