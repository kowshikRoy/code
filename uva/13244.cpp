#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s;
    cin >> s;
    cout << (s + 1) / 2 * (s + 1) / 2 + (s / 2) * (s / 2) << endl;
  }
}
