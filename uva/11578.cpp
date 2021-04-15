/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 11578
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)
#define inf       1LL << 28

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<array<int, 3>> st(n);
        REP(i, n) cin >> st[i][0] >> st[i][1], st[i][1] /= 10, st[i][2] = i;

        sort(st.begin(), st.end());
        int dp[n][6][6][3];
        int Take[n][6][6][3];
        memset(dp, -1, sizeof dp);

        function<int(int, int, int, int)> dfs = [&](int pos, int f, int s,
                                                    int w) -> int {
            if (pos == n) return abs(f - 1) * 10 + abs(s - 1) * 10;
            int &ret = dp[pos][f][s][w];
            if (ret != -1) return ret;

            int F = inf, S = inf;
            // assign to 1st
            if (w == 1 && st[pos - 1][0] == st[pos][0]) {
            } else
                F = 15 + abs(st[pos][1] - f) * 10 +
                    dfs(pos + 1, st[pos][1], s, 1);

            if (w == 2 && st[pos - 1][0] == st[pos][0]) {
            } else
                S = 15 + abs(st[pos][1] - s) * 10 +
                    dfs(pos + 1, f, st[pos][1], 2);

            if (F < S) {
                Take[pos][f][s][w] = 1;
                ret                = F;
            } else {
                Take[pos][f][s][w] = 2;
                ret                = S;
            }
            return ret;
        };

        cout << dfs(0, 1, 1, 0) << endl;
        int f = 1, s = 1, w = 0;
        vector<int> pos(n);
        REP(i, n) {
            int p         = Take[i][f][s][w];
            pos[st[i][2]] = p;
            if (p == 1) f = st[i][1], w = 1;
            else
                s = st[i][1], w = 2;
        }
        REP(i, n) cout << pos[i] << endl;
    }
    return 0;
}
