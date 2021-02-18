#include <bits/stdc++.h>
using namespace std;

int main() {
  long long w, n, a, b;
  while (cin >> w) {
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      ans += a * b;
    }
    cout << ans / w << endl;
  }
}
