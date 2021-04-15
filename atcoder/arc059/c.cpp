/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-04
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    REP(i, n) cin >> a[i];
    int x   = *min_element(a, a + n);
    int y   = *max_element(a, a + n);
    int ans = INT_MAX;
    for (int i = x; i <= y; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) t += (a[j] - i) * (a[j] - i);
        ans = min(t, ans);
    }
    cout << ans << endl;
    return 0;
}
