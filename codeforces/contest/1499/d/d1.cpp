/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-18
 * Task: d 
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
const int N = 2e7+7;
int cnt[N];
bool vis[N];

int c,d,x;
long long calc(long long g) {
        long long p = (x / g + d);
        if(p % c) return 0;
        p/=c;
        return 1LL << (cnt[p]) ;
}

long long solve() {

        int div = 0;
        long long ans = 0;
        for(int g = 1; g * g <= x; g ++) {
            if(x % g) continue;
            auto a = calc(g);
            auto b = calc(x/g);
            if(g * g == x) ans +=  a;
            else ans += a + b;
        }
        return ans;
}
int main() {
    cnt[1] = 0;
    for(int i = 2; i < N; i ++) {
        if(vis[i]) continue;
        for(int j = i; j < N; j += i) {
            vis[j] = 1;
            cnt[j] ++;
        }
    }

    int t;
    in(t);
    while(t--) {
        in3(c,d,x);
        cout << solve() << endl;
    }

    return 0;
}

