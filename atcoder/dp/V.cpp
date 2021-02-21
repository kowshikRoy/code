/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: V
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N], child[N], pf[N], suf[N];
long long dp[N], ans[N], up[N];
int n, mod;

void dfs(int u, int p) {
    long long sum = 1;
    for (auto v : g[u])
        if (v != p) {
            dfs(v, u);
            sum = (sum * (1 + dp[v])) % mod;
            child[u].push_back(v);
        }
    dp[u] = sum;

    long long s = 1;
    for (int i = 0; i < child[u].size(); i++) {
        int v = child[u][i];
        s     = (s * (1 + dp[v])) % mod;
        pf[u].push_back(s);
    }

    s = 1;
    for (int i = (int)child[u].size() - 1; i >= 0; i--) {
        int v = child[u][i];
        s     = (s * (1 + dp[v])) % mod;
        suf[u].push_back(s);
    }
    reverse(suf[u].begin(), suf[u].end());
}

void dfs2(int u, int p) {
    ans[u] = (dp[u] * (1 + up[u])) % mod;
    for (int i = 0; i < child[u].size(); i++) {
        int v       = child[u][i];
        long long s = 1;
        if (i > 0) s = (s * pf[u][i - 1]) % mod;
        if (i + 1 < child[u].size()) s = (s * suf[u][i + 1]) % mod;
        if (p != -1) s = (s * (1 + up[u])) % mod;
        up[v] = s;
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> mod;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1);
    /* for(int i = 1; i <= n; i ++) printf("dp[%d] = %lld\n", i, dp[i]); */
    /* for(int i = 1; i <= n; i ++) printf("up[%d] = %lld\n", i, up[i]); */
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}
