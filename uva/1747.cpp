/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-04
 * Task: 1747
 */

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
using LL = long long;
using PII = pair<LL, LL>;

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    vector<PII> loss, gain;
    for (int i = 0; i < n; i++) {
      LL x, y;
      cin >> x >> y;
      if (x > y)
        loss.push_back({x, y});
      else
        gain.push_back({x, y});
    }
    sort(gain.begin(), gain.end(), [](PII a, PII b) { return a.F < b.F; });
    sort(loss.begin(), loss.end(), [](PII a, PII b) { return a.S > b.S; });

    LL ans = 0, sum = 0;
    for (auto x : gain) {
      ans = min(ans, sum - x.F);
      sum += x.S - x.F;
    }

    for (auto x : loss) {
      ans = min(ans, sum - x.F);
      sum += x.S - x.F;
    }
    printf("%lld\n", -ans);
  }
}
