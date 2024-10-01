#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<int, int> H;
void solve(int n) {
  int x;
  scanf("%d", &x);
  if (x == -1) return;
  H[n] += x;
  solve(n - 1);
  solve(n + 1);
}
int main() {
  int tc = 0;
  while (1) {
    solve(0);
    if (H.empty()) break;
    printf("Case %d:\n", ++tc);
    int f = 0;
    for (auto x : H) {
      if (f) printf(" ");
      printf("%d", x.second);
      f = 1;
    }
    printf("\n\n");
    H.clear();
  }
}
