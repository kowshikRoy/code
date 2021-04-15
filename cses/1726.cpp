/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1726
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int step;
    cin >> step;

    auto move = [](int i, int j) -> vector<pair<int, int>> {
        vector<pair<int, int>> nxt;
        int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int d = 0; d < 4; d++) {
            int x = i + dir[d][0], y = j + dir[d][1];
            if (x >= 0 && x < 8 && y >= 0 && y < 8) nxt.push_back({x, y});
        }
        return nxt;
    };

    vector<vector<double>> Ans(8, vector<double>(8, 1));

    REP(i, 8) REP(j, 8) {
        vector<vector<double>> P(8, vector<double>(8, 0));
        P[i][j] = 1;
        REP(k, step) {
            vector<vector<double>> T(8, vector<double>(8, 0));
            REP(x, 8) REP(y, 8) {
                auto nxt = move(x, y);
                for (auto p : nxt) T[p.first][p.second] += P[x][y] / nxt.size();
            }
            swap(P, T);
        }

        REP(x, 8) REP(y, 8) { Ans[x][y] *= (1 - P[x][y]); }
    }

    double ans = 0;
    REP(i, 8) REP(j, 8) ans += Ans[i][j];
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
