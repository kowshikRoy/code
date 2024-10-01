/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-05
 * Task: 10901
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
  int c, n, m, t;

  cin >> c;
  while (c--) {
    cin >> n >> t >> m;
    pair<int, string> cars[m];
    for (int i = 0; i < m; i++) { cin >> cars[i].first >> cars[i].second; }
    int T = 0;
    string pos = "left";

    queue<int> left, right;
    vector<int> ans(m);
    for (int i = 0; i < m || left.size() || right.size();) {
      for (int j = i; j < m && cars[j].first <= T; j++) {
        if (cars[j].second == "left")
          left.push(j);
        else
          right.push(j);
        i = j + 1;
      }
      if (left.empty() && right.empty()) {
        T = cars[i].first;
        continue;
      }
      if (pos == "left" && !left.empty()) {
        for (int cnt = 0; left.size() && cnt < n; cnt++) {
          ans[left.front()] = T + t;
          left.pop();
        }
        T += t;
        pos = "right";
      } else if (pos == "right" && !right.empty()) {
        for (int cnt = 0; right.size() && cnt < n; cnt++) {
          ans[right.front()] = T + t;
          right.pop();
        }
        T += t;
        pos = "left";
      } else if (right.size() || left.size()) {
        T += t;
        pos = (pos == "left" ? "right" : "left");
      }
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    if (c) printf("\n");
  }

  return 0;
}
