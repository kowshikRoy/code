/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-26
 * Task: keep-moving
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve(int cs) {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> dp(n + 1, -1);
    function<bool(int)> dfs = [&](int u) -> bool {
        if (dp[u] != -1) return dp[u];
        bool ret = false;
        for (auto v : g[u]) {
            if (dfs(v) == 0) ret |= true;
        }
        return dp[u] = ret;
    };

    printf("Case %d: %s\n", cs, dfs(x) ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, cs = 0;
    cin >> t;
    while (t--) { solve(++cs); }
    return 0;
}
