/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-07
 * Task: COLGLF4 
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
LL n,e,h,a,b,c;

LL calc(LL e, LL h) {
    long long iMin = min(e,h);
    return iMin + (e - iMin) / 2 + (h - iMin)/3;
}



int main() {
    int t;
    in(t);
    while(t--){
        in3(n,e,h);
        in3(a,b,c);
        if(calc(e,h) < n) {
            printf("-1\n");
            continue;
        }
        LL ans = LLONG_MAX, A, B,C;
        for( C = 0; C <= min(e,h) && C <= n; C ++) {
            LL re = e - C, rh = h - C;
            if(C + re / 2 + rh / 3 < n) continue;
            A = min(n - C, re / 2);
            B = min(n - A - C, rh / 3);
            if(A + B + C == n) {
                ans = min(ans, A * a + B * b + C * c);
            }
            B = min(n - C, rh / 3);
            A = min(n - C - B, re / 2);
            if(A + B + C == n) {
                ans = min(ans, A * a + B * b + C * c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
