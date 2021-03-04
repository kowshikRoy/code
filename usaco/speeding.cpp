/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-02
 * Task: speeding
 */

#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
#ifndef LOCAL
    setIO("shell");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, limit[105];
    cin >> n >> m;
    int ptr = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++) limit[ptr] = y, ptr++;
    }

    ptr     = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++) {
            ans = max(ans, y - limit[ptr]);
            ptr++;
        }
    }
    cout << ans << endl;
}
