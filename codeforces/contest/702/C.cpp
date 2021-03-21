#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int L = lower_bound(b, b + m, a[i]) - b;
        int d = INT_MAX;
        if (L < m) d = min(d, abs(a[i] - b[L]));
        if (L > 0) {
            L--;
            d = min(d, abs(a[i] - b[L]));
        }
        ans = max(ans, d);
    }
    cout << ans << endl;
    return 0;
}
