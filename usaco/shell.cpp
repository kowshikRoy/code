/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-02
 * Task: shell
 */

#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 201;

vector<vector<int>> dp, a;
int main() {
#ifndef LOCAL
    setIO("shell");
#endif
    int n;
    cin >> n;
    int a[n], b[n], g[n];
    for (int i = 0; i < n; i++) { cin >> a[i] >> b[i] >> g[i]; }
    int ans = 0;
    for (int p = 1; p <= 3; p++) {
        int v[4] = {0};
        v[p]     = 1;
        int cnt  = 0;
        for (int i = 0; i < n; i++) {
            swap(v[a[i]], v[b[i]]);
            if (v[g[i]]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
