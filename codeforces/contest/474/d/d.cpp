/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N   = 1e5 + 5;
const int mod = 1e9 + 7;

void solve() {
    int t, k, a, b;
    cin >> t >> k;

    vector<ll> dp(N);
    dp[0] = 1;
    for (int i = 1; i < k; i++) dp[i] = 1;
    dp[k] = 2;
    for (int i = k + 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (i >= k) { dp[i] = (dp[i] + dp[i - k]) % mod; }
    }
    vector<ll> pf(N);
    pf[0] = dp[0];
    for (int i = 1; i < N; i++) pf[i] = (pf[i - 1] + dp[i]) % mod;

    while (t--) {
        cin >> a >> b;
        cout << ((pf[b] - pf[a - 1]) % mod + mod) % mod << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
