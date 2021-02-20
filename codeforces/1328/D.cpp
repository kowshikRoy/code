#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int dp[N][4][4];
int CS = 1;
int vis[N][4][4], path[N][4][4];
int a[N], c[N];
int solve(int pos, int pre, int begin) {
    if (pos == n - 1) {
        for (int i = 0; i < 3; i++) {
            if (c[pos] != c[pos - 1] && i == pre) continue;
            if (c[pos] != c[0] && i == begin) continue;

            path[pos][pre][begin] = i;
            return i;
        }
    }
    if (vis[pos][pre][begin] == CS) return dp[pos][pre][begin];

    int res = 4;
    for (int i = 0; i < 3; i++) {
        if (i == pre && c[pos] != c[pos - 1]) continue;
        int v = max(i, solve(pos + 1, i, begin));
        if (v < res) {
            path[pos][pre][begin] = i;
            res                   = v;
        }
    }
    vis[pos][pre][begin] = CS;
    dp[pos][pre][begin]  = res;
    return res;
}

void print(int pos, int pre, int begin) {
    if (pos == n - 1) {
        a[pos] = path[pos][pre][begin];
        return;
    }
    a[pos] = path[pos][pre][begin];
    print(pos + 1, a[pos], begin);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> c[i];
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        cout << solve(1, 0, 0) + 1 << endl;
        print(1, 0, 0);
        for (int i = 0; i < n; i++) cout << a[i] + 1 << " ";
        cout << endl;
        CS++;
    }

    return 0;
}
