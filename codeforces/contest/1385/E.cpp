#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> d[N];
int vis[N], rak[N];
vector<pair<int, int>> vec;
bool isLoop = false;
vector<int> top;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs_copy(int v) {
    color[v] = 1;
    for (int u : d[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs_copy(u)) return true;
        } else if (color[u] == 1) {
            cycle_end   = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool isCycle(int n) {
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs_copy(v)) break;
    }

    if (cycle_start == -1) { return false; }
    return true;
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : d[u]) { dfs(v); }
    top.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> ans;
        for (int i = 0; i < m; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 1) d[x].push_back(y), ans.push_back(make_pair(x, y));
            else
                vec.push_back(make_pair(x, y));
        }

        bool isLoop = isCycle(n);
        if (isLoop) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
                if (vis[i] == 0) dfs(i);
            reverse(top.begin(), top.end());
            for (int i = 0; i < top.size(); i++) rak[top[i]] = i;

            for (auto p : vec) {
                if (rak[p.first] < rak[p.second])
                    ans.push_back(make_pair(p.first, p.second));
                else
                    ans.push_back(make_pair(p.second, p.first));
            }
            for (auto p : ans) { cout << p.first << " " << p.second << endl; }
        }
        vec.clear();
        for (int i = 1; i <= n; i++) d[i].clear(), vis[i] = 0;
        top.clear();
    }

    return 0;
}
