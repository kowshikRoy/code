#include <iostream>
using namespace std;

int c[35][22][2];
int sum[35][2];

int main() {
  int t1, t2;
  while (scanf("%d %d", &t1, &t2) == 2) {
    if (t1 == 0 && t2 == 0) break;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> c[i][j][0];
        sum[i][0] += c[i][j][0];
      }
      for (int j = 0; j < m; j++) {
        cin >> c[i][j][1];
        sum[i][1] += c[i][j][1];
      }
    }
  }
}
