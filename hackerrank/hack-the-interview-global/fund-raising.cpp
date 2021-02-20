#include <bits/stdc++.h>
using namespace std;

using LL     = long long;
const LL INF = LONG_LONG_MAX / 4;
int n, m, k, t;
LL charm[16][16];
LL table[16][16];
LL mem[16][1 << 15];
int tableSize[16];
LL calc(int g, int mask) {
    vector<LL> values;
    for (int i = 0; i < t; i++) {
        if (mask & (1 << i)) {
            for (int j = 0; j < tableSize[i]; j++) {
                values.push_back(table[i][j]);
            }
        }
    }

    if (values.size() > n * k) return -1;
    sort(values.begin(), values.end());
    LL sum  = 0;
    int cnt = 0, ptr = n - 1;
    for (int i = values.size() - 1; i >= 0; i--) {
        cnt++;
        if (cnt > k) ptr--, cnt = 1;
        sum += charm[g][ptr] * values[i];
    }
    return sum;
}

LL dp[15][1 << 15];
bool vis[15][1 << 15];

LL solve(int g, int mask) {
    if (g == m) {
        if (mask) return -INF;
        return 0;
    }
    if (vis[g][mask]) return dp[g][mask];

    LL ret = -INF;
    for (int i = mask; i >= 0; i = mask & (i - 1)) {
        if (mem[g][i] >= 0) ret = max(ret, mem[g][i] + solve(g + 1, mask ^ i));
        if (i == 0) break;
    }
    vis[g][mask]       = 1;
    return dp[g][mask] = ret;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> m >> n >> t;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) { cin >> charm[i][j]; }
            sort(charm[i], charm[i] + n);
        }

        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            tableSize[i] = x;
            for (int j = 0; j < x; j++) { cin >> table[i][j]; }
        }
        cin >> k;
        LL ans = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 1 << t; j++) { mem[i][j] = calc(i, j); }
        }

        memset(vis, 0, sizeof vis);
        ans = max(ans, solve(0, (1 << t) - 1));
        cout << ans << endl;
    }
}
