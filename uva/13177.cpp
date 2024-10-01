/**
 * Author: Repon Kumar Roy
 * Date: 2023-01-31
 * Task: 13177
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int p, n;
  while (cin >> p >> n) {
    vector<int> m(n);
    for (int i = 0; i < n; i++) { cin >> m[i]; }
    int ans = *max_element(m.begin(), m.end());
    int low = 1, high = ans;
    while (low <= high) {
      int mid = (low + high) / 2, sum = 0;

      for (int i = 0; i < n; i++) { sum += (m[i] + mid - 1) / mid; }
      if (sum <= p) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    cout << ans << endl;
  }
}
