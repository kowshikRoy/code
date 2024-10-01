#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
unordered_map<long long, long long> sum;
int a[N];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) { sum[a[i] + a[j]]++; }
    }
    //		for(auto x: sum) printf("%lld -> %lld\n", x.first,
    // x.second);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (sum.count(a[i])) ans += sum[a[i]];
    }
    printf("%lld\n", ans);
    sum.clear();
  }
}
