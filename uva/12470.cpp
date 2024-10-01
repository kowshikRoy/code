#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 9;
using Mat = vector<vector<long long>>;

Mat mul(Mat &A, Mat &B) {
  int r = A.size(), c = B[0].size();
  Mat C(r.vector<long long>(c));
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
  long long n;
  Mat A = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

  while (scanf("%lld", &n) && n) {
    if (n == 1)
      cout << 0 << endl;
    else if (n == 2)
      cout << 1 << endl;
    else if (n == 3)
      cout << 2 << endl;
    else {
      Mat B = exp(A, n - 3);
      long long sum = (B[0][0] * 2 + B[0][1]) % mod;
      cout << sum << endl;
    }
  }
}
