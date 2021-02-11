#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, cs = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][n];
    int row = 0, col = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      set<int> s;
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        s.insert(a[i][j]);
      }
      if (s.size() != n)
        row++;
      sum += a[i][i];
    }
    for (int i = 0; i < n; i++) {
      set<int> s;
      for (int j = 0; j < n; j++)
        s.insert(a[j][i]);
      if (s.size() != n)
        col++;
    }

    printf("Case #%d: %d %d %d\n", ++cs, sum, row, col);
  }
}
