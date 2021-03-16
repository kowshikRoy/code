/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-11
 * Task: MULGAME 
 */

#include<bits/stdc++.h>
using namespace std;
 
#define LL                      long long
#define Ulong                   unsigned long long
#define REP(i,n)                for(long long i = 0; i < n ; i++ )
#define mp                      make_pair
#define pb                      push_back
#define all(x)                  (x).begin(),(x).end()
#define PI                      acos(-1.0)
#define EPS                     1e-14
#define F                       first
#define S                       second
#define in(x)                   input(x)
#define in2(x,y)                in(x),in(y)
#define in3(x,y,z)              in(x),in2(y,z)
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl

template<class T> inline void input(T &x) {
  register char c = getchar();x = 0;
  int neg = 0;
  for(; ((c<48 || c>57) && c != '-'); c = getchar());
  if(c=='-'){neg = 1;c = getchar();}
  for(; c>47 && c<58 ; c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
  if(neg) x = -x;
}
inline long long bigmod(long long p,long long e,long long M){
  long long ret = 1;
  for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
 
/********************************************************/ 

int main() {
    int t,n,q,m;
    in(t);
    while(t--){
        in3(n,q,m);
        int a[n + 1];
        for(int i = 1; i <= n; i ++) in(a[i]);
        map<pair<int,int>, int>M;
        for(int i = 1; i <= q; i ++) {
            int l,r;
            in2(l,r);
            M[make_pair(l,r)] ++;
        }
        int dp[m + 1] = {0};
        for(auto x: M) {
            auto pair = x.first;
            int f = x.second;
            int p = a[pair.first], q = a[pair.second];
            int k = p + q;
            int beg = 0;
            while(beg <= m) {
                if(beg + p <= m) dp[beg + p] += f;
                if(beg + p + q <= m) dp[beg + p + q] -=f;
                beg += k;
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i ++) {
            dp[i] += dp[i-1];
            ans = max(dp[i], ans);
        }
        printf("%d\n" ,ans);
    }

    return 0;
}
