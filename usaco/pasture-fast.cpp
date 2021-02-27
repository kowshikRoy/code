/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-27
 * Task: pasture-fast
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 2505;

vector<pair<int, int>> p;
vector<vector<int>> grid, pre;

int points(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] +
           pre[x1 - 1][y1 - 1];
}

int main() {
    int n;
    cin >> n;
    p.resize(n);
    vector<int> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        xs.push_back(p[i].first);
        ys.push_back(p[i].second);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for (int i = 0; i < n; i++)
        p[i].first =
            lower_bound(xs.begin(), xs.end(), p[i].first) - xs.begin() + 1;
    for (int i = 0; i < n; i++)
        p[i].second =
            lower_bound(ys.begin(), ys.end(), p[i].second) - ys.begin() + 1;

    int r = xs.size(), c = ys.size();
    grid.resize(r + 1, vector<int>(c + 1, 0));
    pre.resize(r + 1, vector<int>(c + 1, 0));
    for (int i = 0; i < n; i++) grid[p[i].first][p[i].second] = 1;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            pre[i][j] =
                grid[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

    long long ans = 1;

    for (int low = 0; low < n; low++) {
        for (int high = 0; high < n; high++) {
            if (p[low].second <= p[high].second) {
                int x =
                    points(1, p[low].second, min(p[low].first, p[high].first),
                           p[high].second);
                int y = points(max(p[low].first, p[high].first), p[low].second,
                               r, p[high].second);
                ans += (long long)x * y;
            }
        }
    }
    cout << ans << endl;
}
