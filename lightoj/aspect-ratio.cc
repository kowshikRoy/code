#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int cs = 1; cs <= t; cs ++) {
    double k;
    cin >> k;
    printf("Case %d: %.4lf\n", cs, sqrt((k*k-1)/(4-k*k)));
  }

  
}