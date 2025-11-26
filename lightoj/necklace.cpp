#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const long long M = 1e9+7;

long long Pow(long long x, long long p) {
  if(p == 0) return 1;
  if(p%2) return (x * Pow(x, p-1))%M;
  long long t = Pow(x, p/2);
  return (t*t)%M;
}

long long ModInv(long long n) {
  return Pow(n, M - 2);
}

long long gcd(long long a, long long b){
  if(a % b == 0) return b;
  return gcd(b, a % b);
}



int main() {
  int t;
  cin >> t;
  for(int cs = 1; cs <= t; cs ++) {
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for(int i = 1; i <= n; i ++) {
      sum = (sum + Pow(k, gcd(n,i)))%M;
    }
    long long result = (sum * ModInv(n))%M;
    printf("Case %d: %lld\n", cs, result);
  }
}
