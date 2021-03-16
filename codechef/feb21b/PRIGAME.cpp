/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-11
 * Task: PRIGAME 
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

const int N = 1e6+6;
int dp[N], vis[N];
int main() {
    vis[1] = 1;
    for(int i = 2; i < N; i ++){
        if(vis[i] ) continue;
        for(int j = i + i; j < N; j += i) {
            vis[j] = 1;
        }
    }
    for(int i = 1; i < N; i ++) {
        dp[i] = dp[i-1] + (vis[i] == 0);
    }
    int t,x,y;
    in(t);
    while(t--) {
        in2(x,y);
        if(dp[x] <= y) {
            printf("Chef\n");
        }
        else 
            printf("Divyam\n");
        

    }
    return 0;
}
