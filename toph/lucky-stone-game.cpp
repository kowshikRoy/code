/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-28
 * Task: lucky-stone-game
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

unordered_map<int, bool> dp[100005];
int solve(int x, int y) {
    if (x == 0) return 0;
    if (y == 0) return 0;
    if (dp[x].count(y)) return dp[x][y];

    int ret = 0;
    if (x >= 4 && solve(x - 4, y) == 0) ret = 1;
    else if (x >= 7 && solve(x - 7, y) == 0)
        ret = 1;
    if (ret) return dp[x][y] = 1;

    int div = -1;
    if (y % 7 == 0) div = 7;
    else if (y % 4 == 0)
        div = 4;
    else
        div = 3;
    return dp[x][y] = !solve(x, y / div);
}
void solve(int cs) {
    int n, m;
    cin >> n >> m;
    printf("Case %d: %s\n", cs, solve(n, m) ? "Alice" : "Bob");
}

int main() {
    for(int i = 1; i <= 80; i ++) {
        for(int j = 1; j <= 80; j ++) {
            printf("%2d", solve(i,j));
        }
        printf("\n");
    }
    return 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, cs = 0;
    cin >> t;
    while (t--) { solve(++cs); }
    return 0;
}
