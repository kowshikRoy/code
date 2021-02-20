/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: M
 */

#include <bits/stdc++.h>
using namespace std;

int N, K;
long long dp[100005];
long long pf[100005];

int a[105];
const int MOD = 1e9 + 7;

long long calc(int i, int j) { return pf[j] - (i > 0 ? pf[i - 1] : 0); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];

    dp[0] = 1;
    pf[0] = 1;
    for (int i = 1; i <= K; i++) pf[i] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[j] = (calc(j - a[i], j) % MOD + MOD) % MOD;
        }
        for (int j = 0; j <= K; j++) {
            pf[j] = dp[j] + (j > 0 ? pf[j - 1] : 0);
        }
    }
    cout << dp[K] << endl;
}
