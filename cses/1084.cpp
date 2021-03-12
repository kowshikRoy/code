/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1084
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int L = 0, R = 0;
    int ans = 0;
    while (L < n && R < m) {
        if (a[L] < b[R] - k) L++;
        else if (a[L] > b[R] + k)
            R++;
        else {
            ans++;
            L++;
            R++;
        }
    }

    cout << ans << endl;
}
