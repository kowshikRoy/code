/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1725
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<double> dp1(6 * n + 1), dp2(6 * n + 1);
    dp1[0] = 1;
    for (int i = 1; i <= n; i++) {
        fill(dp2.begin(), dp2.end(), 0);
        for (int k = 1; k <= 6; k++) {
            for (int j = k; j <= 6 * i; j++) dp2[j] += dp1[j - k] / 6;
        }
        swap(dp1, dp2);
    }

    double sum = 0;
    for (int i = a; i <= b; i++) sum += dp1[i];
    cout << setprecision(6) << fixed << sum << endl;

    return 0;
}
