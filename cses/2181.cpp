/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 2181
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int n, m;

vector<int> expand(int mask) {
    vector<int> v;
    REP(i, n) v.push_back(mask % 3), mask /= 3;
    reverse(v.begin(), v.end());
    return v;
}
int compact(vector<int> &v) {
    int sum       = 0;
    REP(i, n) sum = sum * 3 + v[i];
    return sum;
}

/* int dfs(int mask, int lay) { */
/*     if(lay == 0) return mask == 0; */
/*     if(dp[mask][lay] != -1) return dp[mask][lay]; */
/*     auto e = expand(mask); */
/*     int ret = 0; */
/*     int pivot = -1; */
/*     REP(i,n) if(e[i] == 0) { pivot = i; break; } */
/*     /1* dbg(e, pivot, lay); *1/ */
/*     if(pivot == -1) { */
/*         REP(i,n) e[i] --; */
/*         return dfs(compact(e), lay - 1); */
/*     } */
/*     // 2 x 1 */
/*     if(pivot + 1 < n && e[pivot + 1] == 0) { */
/*         e[pivot] = 1; */
/*         e[pivot + 1] = 1; */
/*         add(ret, dfs(compact(e), lay)); */
/*         e[pivot] = 0; */
/*         e[pivot + 1] = 0; */
/*     } */
/*     // 1 x 2 */
/*     e[pivot] = 2; */
/*     add(ret, dfs(compact(e), lay)); */
/*     e[pivot] = 0; */

/*     return dp[mask][lay] = ret; */

/* } */

void solve() {
    cin >> n >> m;
    int mx       = 1;
    REP(i, n) mx = mx * 3;

    vector<vector<int>> dp(2, vector<int>(mx, 0));
    dp[0][0] = 1;
    vector<vector<pair<int, int>>> trans(mx);

    for (int i = mx - 1; i >= 0; i--) {
        auto e = expand(i);

        int pivot = -1;
        REP(i, n) if (e[i] == 0) {
            pivot = i;
            break;
        }
        if (pivot == -1) {
            REP(i, n) e[i]--;
            trans[i].push_back({1, compact(e)});
            continue;
        }

        // 2 x 1
        if (pivot + 1 < n && e[pivot + 1] == 0) {
            e[pivot]     = 1;
            e[pivot + 1] = 1;
            trans[i].push_back({0, compact(e)});
            e[pivot]     = 0;
            e[pivot + 1] = 0;
        }
        // 1 x 2
        e[pivot] = 2;
        trans[i].push_back({0, compact(e)});
        e[pivot] = 0;
    }

    for (int lay = 1; lay <= m; lay++) {
        int now = lay & 1;
        for (int i = mx - 1; i >= 0; i--) {
            dp[now][i] = 0;
            for (auto p : trans[i]) {
                add(dp[now][i], dp[now ^ p.first][p.second]);
            }
        }
    }

    cout << dp[m & 1][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
