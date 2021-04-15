/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-05
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, A, s = 0;
    cin >> n >> A;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];

    vector<vector<vector<ll>>> dp(
        n, vector<vector<ll>>(s + 1, vector<ll>(n + 1, -1)));

    function<ll(int, int, int)> dfs = [&](int pos, int sum, int taken) -> ll {
        if (pos == n) return sum == taken * A;
        ll &ret = dp[pos][sum][taken];
        if (ret != -1) return ret;
        ret = dfs(pos + 1, sum, taken);
        ret += dfs(pos + 1, sum + a[pos], taken + 1);
        return ret;
    };

    cout << dfs(0, 0, 0) - 1 << endl;
    return 0;
}
