/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: 1619a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        vector<ll> a(n);
        REP(i, n) cin >> a[i];
        ll ans = -1;
        int A, B;
        REP(i, n) {
            ll imin = INT_MAX, sum = 0;
            for (int j = i; j < n; j++) {
                imin = min(imin, a[j]);
                sum += a[j];
                if (imin * sum > ans) {
                    ans = imin * sum;
                    A   = i;
                    B   = j;
                }
            }
        }
        cout << ans << endl;
        cout << A + 1 << " " << B + 1 << endl;
    }

    return 0;
}
