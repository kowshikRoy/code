/**
 * Author: Repon Kumar Roy
 * Date: 2023-02-05
 * Task: 11039
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> red, blue;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0)
      red.push_back(abs(x));
    else
      blue.push_back(abs(x));
  }
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  if (red.size() == 0 || blue.size() == 0) {
    cout << 1 << endl;
    return;
  }

  int ans = 0, H = -1;
  int pr = 0, pb = 0;
  string nxt;
  if (red[0] < blue[0]) {
    ans++;
    nxt = "blue";
    H = red[0];
    pr++;
  } else {
    ans++;
    nxt = "red";
    H = blue[0];
    pb++;
  }

  while (pr < red.size() || pb < blue.size()) {
    if (nxt == "blue") {
      if (pb == blue.size()) break;
      while (pb < blue.size()) {
        if (blue[pb] > H) {
          H = blue[pb];
          ans++;
          nxt = "red";
          pb++;
          break;
        }
        pb++;
      }
    } else {
      if (pr == red.size()) break;
      while (pr < red.size()) {
        if (red[pr] > H) {
          H = red[pr];
          ans++;
          nxt = "blue";
          pr++;
          break;
        }
        pr++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
