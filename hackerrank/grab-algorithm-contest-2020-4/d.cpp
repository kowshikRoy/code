#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long v1 = 0, v2 = 0;
        long long f1 = 0, f2 = 0;
        long long ans1 = *max_element(a, a + n);
        long long ans2 = ans1;
        for (int i = 0; i < n; i++) {
            v1 += a[i];
            if (v1 < 0) v1 = 0, f1 = 0;
            else
                f1 = 1;
            if (a[i] > 0) v2 += a[i], f2 = 1;
            if (f1) ans1 = max(ans1, v1);
            if (f2) ans2 = max(ans2, v2);
        }
        cout << ans1 << " " << ans2 << endl;
    }
}
