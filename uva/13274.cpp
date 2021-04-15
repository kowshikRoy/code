/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 13274
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> g(n);
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> dp(n);

        function<void(int, int)> dfs = [&](int u, int p) {
            int child = 0;
            vector<int> b;
            for (auto v : g[u])
                if (v != p) {
                    dfs(v, u);
                    b.push_back(dp[v]);
                    child++;
                }
            if (child < k) {
                dp[u] = 1;
            } else {
                sort(b.begin(), b.end(), greater<int>());
                b.resize(k);
                dp[u] = 1 + accumulate(b.begin(), b.end(), 0);
            }
        };

        dfs(0, -1);
        cout << "Case " << ++cs << ": " << dp[0] << endl;
    }

    return 0;
}
