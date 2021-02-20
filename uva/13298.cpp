#include <bits/stdc++.h>
using namespace std;

using mat     = vector<vector<long long>>;
const int mod = 1e9 + 9;

mat mul(mat &a, mat &b) {
    int r = a.size();
    mat x(r, vector<long long>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            long long sum = 0;
            for (int k = 0; k < r; k++) {
                sum = (sum + a[i][k] * b[k][j]) % mod;
            }
            x[i][j] = sum;
        }
    }
    return x;
}
int main() {
    long long n, k;
    while (scanf("%lld %lld", &k, &n) == 2) {
        if (n == 0 && k == 0) break;
        mat A(k, vector<long long>(k));
        mat B(k, vector<long long>(k));
        for (int i = 0; i < k; i++) A[0][i] = 1;
        for (int i = 1; i < k; i++) A[i][i - 1] = 1;
        for (int i = 0; i < k; i++) B[i][i] = 1;

        long long e = n;
        while (e > 0) {
            if (e & 1) B = mul(A, B);
            e >>= 1;
            if (!e) break;
            A = mul(A, A);
        }

        printf("%lld\n", B[0][0]);
    }
}
