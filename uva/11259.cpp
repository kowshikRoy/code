/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 11259
 */

/**
 * For two coins it's something like this:
 * Let N be the total number of ways of obtaining value v using the given coin
 * denominations, let N1 and N2 be the number of ways, in which the first or
 * second coin is used more than d[1] or d[2] times, respectively, let N12 be the
 * number of ways in which the first coin is used more than d[1] times, and the
 * second coin is used more than d[2] times. Then the number of ways in which no
 * coin is used more times than necessary is: N - N1 - N2 + N12.
 * 
 * How to compute these N's:
 * N1 = number of ways in which the first coin is used more than d[1] times, by
 * definition. So, use the first coin d[1]+1 times, and find the number of ways
 * to obtain the remaining value.
 */
#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> c(4), d(4);
        int q;
        int v;
        REP(i, 4) cin >> c[i];

        const int maxn = 1e5 + 5;
        vector<ll> dp(maxn);
        dp[0] = 1;
        REP(i, 4) {
            for (int j = c[i]; j < maxn; j++) dp[j] += dp[j - c[i]];
        }

        cin >> q;
        while (q--) {
            REP(i, 4) cin >> d[i];
            cin >> v;

            ll ret = 0;
            REP(i, 1 << 4) {
                int tempV = v;
                int f     = 1;
                REP(j, 4) {
                    if ((i >> j) & 1) f = -f, tempV -= (d[j] + 1) * c[j];
                }
                if (tempV >= 0) ret += f * dp[tempV];
            }
            cout << ret << endl;
        }
    }
    return 0;
}
