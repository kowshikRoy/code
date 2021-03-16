/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 2220
 */

#include <bits/stdc++.h>
using namespace std;
#define LL long long

vector<int> digits;
LL dp[20][11][2];

LL solve(int idx, int pre, bool flag,
         bool empty) {  // true if current number = n
    if (idx < 0) return 1;
    if (dp[idx][pre][flag] != -1) return dp[idx][pre][flag];

    LL ans = 0;
    for (int i = 0; i < 10; i++) {
        if (flag && i > digits[idx]) continue;
        if (i == pre) continue;
        ans += solve(idx - 1, (empty && i == 0) ? 10 : i,
                     flag && (i == digits[idx]), empty && (i == 0));
    }
    return dp[idx][pre][flag] = ans;
}

LL solve(LL n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    digits.clear();
    memset(dp, -1, sizeof dp);
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }

    return solve(digits.size() - 1, 10, true, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
}
