#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == i) ans++;
        }
        if (ans == n) cout << 0 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
