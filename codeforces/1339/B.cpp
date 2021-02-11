#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n  +1 ];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    int ptr = (n -1) / 2;
    cout << a[ptr] << " ";
    int R = ptr + 1, L = ptr - 1;
    for (int i = 1; i < n; i++) {
      if (i & 1)
        cout << a[R] << " ", R++;
      else
        cout << a[L] << " " , L--;
    }
    cout << endl;
  }

  return 0;
}
