/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1729
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
    vector<int> p(k);
    REP(i, k) cin >> p[i];

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        bool win = false;
        for (auto t : p) {
            if (i >= t)
                if (dp[i - t] == 0) win = true;
        }
        dp[i] = win;
        cout << (win ? 'W' : 'L');
    }
    cout << endl;

    return 0;
}
