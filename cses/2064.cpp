/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 2064
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 1001;
    vector<int> dp(N);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < N; i ++) {
        for(int l = 1; l <= i - l; i ++) dp[i] += dp[l] * dp[i-l];
        printf("%d %d\n", i, dp[i]);
    }
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
    } else {

    }
    return 0;
}
