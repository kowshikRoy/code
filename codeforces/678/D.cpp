#include <bits/stdc++.h>
using namespace std;
inline long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long A, B, n, x;
  cin >> A >> B >> n >> x;
  long long m = 1e9 + 7;

  long long ans = (bigmod(A, n , m) * x) % m ;
  if(A == 1) ans += (B * ((n ) % m)) % m;
  else ans += ((B * (bigmod(A, n , m) - 1) % m * modinverse(A - 1, m))) % m;
  ans = (ans % m + m) % m;
  cout << ans << endl;

  return 0;
}
