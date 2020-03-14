#include <bits/stdc++.h>
using namespace std;

/*
   Change MRows,MCols
   1. Call init(row,col)
   2. Build Initial Matrix
   3. Expo

*/
const int MRows = 105;
const int MCols = 105;
typedef long long m_t;
const int MOD = 1000000009;
struct Matrix {

	int r, c;
	m_t m[MRows][MCols];

	void init(int R, int C) {
		memset(m,0,sizeof m);
		r = R;
		c = C;
	}
	void iden() {
		for (int i = 0; i < r; i++)
			m[i][i] = 1;
	}
	void print() {
		puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				printf("%4d  ", m[i][j]);
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
	void add(const Matrix &B, Matrix &C) {
		C.r = C.c = r;
		for (int i = 0; i < C.r; i++) {
			for (int j = 0; j < C.c; j++) {
				C.m[i][j] = m[i][j] + B.m[i][j];
			}
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
			if (e == 0)
				break;
			b.mul(b, x);
			b = x;
		}
	}
};

int main() {
	long long n;
	int k;
	while (scanf("%d %lld", &k, &n)) {
		if (n == 0 && k == 0)
			break;
		Matrix A, B;
		A.init(k, k);

		for (int i = 0; i < k; i++)
			A.m[0][i] = 1;
		for (int i = 1; i < k; i++)
			A.m[i][i - 1] = 1;
		A.exp(n, B);
		printf("%lld\n",B.m[0][0]);
	}
}
