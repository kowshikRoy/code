/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-23
 * Task: 2413
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 6, mod = 1e9 + 7;
int main() {
    vector<ll> dp(N), s(N), t(N);

    dp[0]    = 1;
    s[0]     = 1;
    t[0]     = 1;
    ll pfsum = 1, sfsum = 1;
    for (int i = 1; i < N; i++) {
        s[i]  = pfsum;
        t[i]  = sfsum;
        dp[i] = (s[i] + t[i]) % mod;
        pfsum = (pfsum + dp[i]) % mod;
        sfsum = (4 * sfsum + s[i]) % mod;
    }

    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
