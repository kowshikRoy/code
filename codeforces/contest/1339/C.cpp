#include <bits/stdc++.h>
using namespace std;

int MSB(long long n) {
    int ans = 0;
    while (n) {
        n /= 2;
        ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        long long pivot = -1e18;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) { pivot = max(pivot, a[i - 1]); }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] >= pivot) continue;
            else {
                ans  = max(ans, MSB(pivot - a[i]));
                a[i] = pivot;
            }
        }
        cout << ans << endl;
        for (int i = 1; i < n; i++) { assert(a[i] >= a[i - 1]); }
    }

    return 0;
}
