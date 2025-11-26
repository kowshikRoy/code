#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int cs = 1; cs <= t; cs ++) {
    int n, m, k;
    double p;
    cin >> n >> m >> k >> p;
    printf("Case %d: %.9lf\n", cs, n * k * p);
  }
}
