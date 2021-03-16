/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1093
 */

#include <bits/stdc++.h>
using namespace std;
inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

const int M = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % M;
    }
    cout << (1LL * dp[sum] * modinverse(2, M)) % M << endl;
}
