#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [&](pair<int, int> &a, pair<int, int> &b) {
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
    });
    int take = 0, used = 0;
    for (auto p : v) {
      int rem = p.second - used;
      if (rem >= p.first)
        take++, used += p.first;
    }

    printf("%d\n%s", take, tc ? "\n" : "");
  }
}
