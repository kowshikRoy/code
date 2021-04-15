/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-01
 * Task: 1096
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int mod = 1e9 + 7;
using Mat     = vector<vector<ll>>;
Mat mul(Mat &A, Mat &B) {
    int r = A.size(), c = B[0].size();
    Mat C(r, vector<long long>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            long long v = 0;
            for (int k = 0; k < c; k++) v += A[i][k] * B[k][j], v %= mod;
            C[i][j] = v;
        }
    return C;
}

Mat exp(Mat &A, long long e) {
    int r = A.size(), c = A[0].size();
    Mat C(r, vector<long long>(c));
    for (int i = 0; i < r; i++) C[i][i] = 1;

    Mat B = A;
    while (true) {
        if (e & 1) C = mul(C, B);

        e >>= 1;
        if (e == 0) break;
        B = mul(B, B);
    }
    return C;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> dp(7);
    dp[0] = 1;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) dp[i] += dp[i - j];
        }
    }

    Mat A(6, vector<ll>(6));
    for (int i = 0; i < 6; i++) A[0][i] = 1;
    for (int i = 1; i < 6; i++) A[i][i - 1] = 1;

    ll n;
    cin >> n;
    if (n <= 6) {
        cout << dp[n] << endl;
        return 0;
    }
    Mat B  = exp(A, n - 6);
    ll ans = 0;
    for (int i = 0; i < 6; i++) ans = (ans + B[0][i] * dp[6 - i]) % mod;
    cout << ans << endl;

    return 0;
}
