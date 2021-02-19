#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        long long mn = 1e9 + 1, mx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i && a[i - 1] != -1)
                    mn = min(mn, a[i - 1]), mx = max(mx, a[i - 1]);
                if (i + 1 < n && a[i + 1] != -1)
                    mn = min(mn, a[i + 1]), mx = max(mx, a[i + 1]);
            }
        }
        long long m = 0, k = 0;
        if (mx == -1) k = 0;
        else
            k = (mx + mn) / 2;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) a[i] = k;
            if (i > 0) m = max(m, abs(a[i] - a[i - 1]));
        }
        cout << m << " " << k << endl;
    }
    return 0;
}
