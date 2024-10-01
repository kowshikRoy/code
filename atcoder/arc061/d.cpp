/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, n;
    cin >> h >> w >> n;
    vector<int> x(n), y(n);
    set<pair<int, int>> points;
    REP(i, n) {
        cin >> x[i] >> y[i];
        points.insert({x[i], y[i]});
    }

    set<pair<int, int>> c[10];

    for (int k = 0; k < n; k++) {
        int a = x[k], b = y[k];
        for (int i = max(1, a - 2); i <= a; i++) {
            for (int j = max(1, b - 2); j <= b; j++) {
                int cnt   = 0;
                bool flag = true;
                for (int t = 0; t < 9; t++) {
                    int u = i + t / 3, v = j + t % 3;
                    if (u > h || v > w) {
                        flag = false;
                        break;
                    }
                    if (points.count({u, v})) cnt++;
                }
                if (flag) c[cnt].insert({i, j});
            }
        }
    }

    ll tot = (h - 3 + 1) * (w - 3 + 1);
    for (int i = 1; i < 10; i++) tot -= c[i].size();
    cout << tot << endl;
    for (int i = 1; i < 10; i++) cout << c[i].size() << endl;

    return 0;
}
