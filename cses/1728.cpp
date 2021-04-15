/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1728
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
    vector<int> r(n);
    REP(i, n) cin >> r[i];

    double out = 0;
    REP(i, n) {
        double ans = 0;
        for (int k = 1; k <= r[i]; k++) {
            for (int j = 0; j < i; j++) {
                int cnt = max(k, r[j]) - k;
                ans += static_cast<double>(cnt) / r[i] / r[j];
            }
        }
        out += ans;
    }
    cout << fixed << setprecision(6) << out << endl;

    return 0;
}
