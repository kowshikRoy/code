#include <bits/stdc++.h>
using namespace std;
/*
   Change MRows,MCols
   1. Call init(row,col)
   2. Build Initial Matrix
   3. Expo

*/
const int MRows = 100;
const int MCols = 100;
typedef long long m_t;
long long MOD = 1e9 + 7;
struct Matrix {
    int r, c;
    m_t m[MRows][MCols];

    void init(int R, int C) {
        memset(m, 0, sizeof m);
        r = R;
        c = C;
    }
    void iden() {
        for (int i = 0; i < r; i++) m[i][i] = 1;
    }
    void print() {
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) printf("%4d  ", m[i][j]);
            printf("\n");
        }
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }

    void mul(const Matrix &y, Matrix &z) const {
        // value Stored in Z
        z.r = r, z.c = y.c;
        m_t v;

        for (int i = 0; i < z.r; ++i)
            for (int j = 0; j < z.c; ++j) {
                v = 0;
                for (int k = 0; k < c; ++k) {
                    v += m[i][k] * y.m[k][j];
                    v %= MOD;
                }

                z.m[i][j] = v;
            }
    }
    void add(const Matrix &B, Matrix &c) {
        c.r = c.c = r;
        for (int i = 0; i < c.r; i++) {
            for (int j = 0; j < c.c; j++) { c.m[i][j] = m[i][j] + B.m[i][j]; }
        }
    }
    void exp(long long e, Matrix &z) {
        // value stored in Z
        z.init(r, c);
        z.iden();
        Matrix x, b = *this;
        while (true) {
            if (e & 1) {
                z.mul(b, x);
                z = x;
            }
            e >>= 1;
            if (e == 0) break;
            b.mul(b, x);
            b = x;
        }
    }
};

int count(long long a) {
    int cnt = 0;
    while (a) cnt++, a -= a & -a;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    Matrix A;
    A.init(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count(a[i] ^ a[j]) % 3 == 0) A.m[i][j] = 1;
            else
                A.m[i][j] = 0;
        }
    }

    Matrix B;
    A.exp(k - 1, B);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { sum = (sum + B.m[i][j]) % MOD; }
    }
    cout << sum << endl;

    return 0;
}
