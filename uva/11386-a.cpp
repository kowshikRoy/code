#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int a[N];
int b[N];
int c[N];
long long nC2(long long n) { return n * (n - 1) / 2; }
int bs(int arr[], int l, int r, int v) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == v) return mid;
    if (arr[mid] < v)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(a, a + n);
    sort(b, b + n);
    int nu = (int)(unique(b, b + n) - b), pivot = 0;
    for (int i = 0; i < nu; i++) {
      int j = pivot;
      int cnt = 0;
      for (; j < n && a[j] == b[i]; j++) cnt++;
      c[i] = cnt;
      pivot = j;
    }

    long long ans = 0;
    pivot = 0;
    for (int i = 0; i < nu; i++) {
      if (2 * b[i] > b[nu - 1]) break;
      int ptr = bs(b, pivot, nu - 1, 2 * b[i]);
      if (ptr != -1) {
        ans += nC2(c[i]) * c[ptr];
        pivot = ptr + 1;
      }
    }
    for (int i = 0; i < nu; i++) {
      pivot = 0;
      for (int j = i + 1; j < nu; j++) {
        if (b[i] + b[j] > b[nu - 1]) break;
        int ptr = bs(b, pivot, nu - 1, b[i] + b[j]);
        if (ptr != -1) {
          ans += c[i] * c[j] * c[ptr];
          pivot = ptr + 1;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
