/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-06
 * Task: 10668
 */

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double len, t, cof;
  while (cin >> len >> t >> cof) {
    if (len < 0) break;
    double mul = 1 + t * cof;

    if (mul - 1 < EPS) {
      printf("%.3lf\n", 0);
      continue;
    }

    double low = 0, high = acos(-1) / 2;
    for (int i = 0; i < 100; i++) {
      double theta = (low + high) / 2;
      if (theta / mul > sin(theta))
        high = theta;
      else
        low = theta;
    }
    double r = mul * .5 * len / low;
    double x = r - r * cos(low);
    printf("%.3lf\n", x);
  }
}
