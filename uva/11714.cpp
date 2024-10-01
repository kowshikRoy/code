/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-06
 * Task: 11714
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, ans = 0;
  while (scanf("%lld", &n) == 1) {
    ans = 1;
    while (n > 2) {
      ans += (n / 2) + 1;
      n = (n + 1) / 2;
    }
    printf("%lld\n", ans);
  }
}
