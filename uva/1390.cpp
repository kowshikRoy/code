#include <bits/stdc++.h>
using namespace std;

map<vector<int>, double> dp;
double solve(vector<int> v) {
    if (v.size() == 1) return 0;
    auto it = dp.find(v);
    if (it != dp.end()) return it->second;

    int n = (int)v.size(), sum = 0;
    for (auto a : v) sum += a;
    double ret = 0, tot = sum * (sum - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> nv = v;
            nv.erase(nv.begin() + j);
            nv[i] = v[i] + v[j];
            sort(nv.begin(), nv.end());
            ret += v[i] * v[j] * (1 + solve(nv)) / tot;
        }
    }
    double p0 = 0;
    for (int i = 0; i < n; i++) p0 += v[i] * (v[i] - 1) / 2;
    p0 /= tot;

    return dp[v] = (p0 + ret) / (1 - p0);
}

vector<int> g[33];
bool vis[33];
int _cnt = 0;
void dfs(int u) {
    vis[u] = 1;
    _cnt++;
    for (auto v : g[u])
        if (!vis[v]) dfs(v);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) g[i].clear(), vis[i] = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            _cnt = 0;
            if (!vis[i]) dfs(i), v.push_back(_cnt);
        }
        sort(v.begin(), v.end());
        printf("%.6lf\n", solve(v));
    }
}
