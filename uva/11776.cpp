#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cs = 0;
  while (scanf("%d", &n) == 1) {
    if (n == -1) break;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      events.emplace_back(a, 1);
      events.emplace_back(b, -1);
    }
    sort(events.begin(), events.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           if (a.first == b.first) return a.second > b.second;
           return a.first < b.first;
         });
    int sum = 0, ans = 0;
    for (auto x : events) {
      sum += x.second;
      ans = max(ans, sum);
    }
    printf("Case %d: %d\n", ++cs, ans);
  }
}
