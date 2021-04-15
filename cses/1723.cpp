/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-01
 * Task: 1723
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int mod = 1e9 + 7;

using Mat = vector<vector<ll>>;
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
    int n, m, k;
    cin >> n >> m >> k;

    Mat A(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[a][b]++;
    }
    auto B = exp(A, k);
    cout << B[0][n - 1] << endl;
    return 0;
}
