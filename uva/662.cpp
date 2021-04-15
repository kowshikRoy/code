/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-08
 * Task: 662
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int INF = INT_MAX / 4;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, cs = 0;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        vector<ll> d(n);
        REP(i, n) cin >> d[i];

        vector<vector<ll>> cost(n, vector<ll>(n, INF));
        vector<vector<int>> opt(n, vector<int>(n, INF));
        vector<ll> pf(n);
        REP(i, n) {
            if (i) pf[i] = pf[i - 1];
            pf[i] += d[i];
        }

        auto sum = [&](int a, int b) {
            return pf[b] - (a ? pf[a - 1] : 0);
        };

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int m      = (i + j) / 2;
                cost[i][j] = (m - i + 1) * d[m] - sum(i, m) + sum(m, j) -
                             (j - m + 1) * d[m];
                opt[i][j] = m;
                m++;
                if (m >= i && m <= j) {
                    ll t = (m - i + 1) * d[m] - sum(i, m) + sum(m, j) -
                           (j - m + 1) * d[m];
                    if (t < cost[i][j]) {
                        opt[i][j]  = m;
                        cost[i][j] = t;
                    }
                }
            }
        }

        vector<vector<ll>> dp(k + 1, vector<ll>(n, INF));
        vector<vector<pair<int, int>>> nxt(k + 1,
                                           vector<pair<int, int>>(n, {0, -1}));
        REP(i, n) dp[1][i] = cost[0][i], nxt[1][i] = {0, -1};
        for (int i = 2; i <= k; i++) {
            for (int p = 0; p < n; p++) {
                dp[i][p] = dp[i - 1][p];
                for (int q = 1; q <= p; q++) {
                    ll t = dp[i - 1][q - 1] + cost[q][p];
                    if (t < dp[i][p]) {
                        dp[i][p]  = t;
                        nxt[i][p] = {i - 1, q - 1};
                    }
                }
            }
        }
        cout << "Chain " << ++cs << endl;
        int x = k, y = n - 1;
        vector<array<int, 3>> solution;
        for (int depot = 0; depot < k; depot++) {
            auto p = nxt[x][y];
            int rb = p.second + 1, re = y;
            solution.push_back({opt[rb][re], rb, re});
            x = p.first;
            y = p.second;
        }
        reverse(solution.begin(), solution.end());
        for (int i = 0; i < k; i++) {
            int p = solution[i][0], b = solution[i][1], e = solution[i][2];
            cout << "Depot " << i + 1 << " at restaurant " << p + 1
                 << " serves ";
            if (b == e) {
                cout << "restaurant " << b + 1 << endl;
            } else {
                cout << "restaurants " << b + 1 << " to " << e + 1 << endl;
            }
        }

        cout << "Total distance sum = " << dp[k][n - 1] << endl << endl;
    }

    return 0;
}
