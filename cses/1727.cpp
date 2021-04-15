/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1727
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= k; i++) ans += i * (pow(i, n) - pow(i - 1, n));
    for (int i = 1; i <= n; i++) ans /= k;
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
