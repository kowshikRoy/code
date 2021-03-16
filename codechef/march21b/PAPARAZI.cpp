/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-07
 * Task: PAPARAZI 
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
struct Pint{
    long long x,y;
    Pint(){}
    Pint(long long x,long long y):x(x),y(y){}
    bool operator<(const Pint &p) const { return x<p.x||(x==p.x&& y<p.y);}
    bool operator==(const Pint &p) const {return x==p.x && y==p.y; }
    Pint operator-(const Pint &p) const { return {x-p.x,y-p.y};           }
};
long long dot(Pint a,Pint b) { return a.x*b.x + a.y*b.y; }
long long cross(Pint a,Pint b) { return a.x*b.y - a.y*b.x;}
bool cw(const Pint &a, const Pint &b, const Pint &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
};
vector<Pint> convexHull(vector<Pint> &p)
{
 
    int n = (int)p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<Pint> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}
int main() {
    int t,n;
    in(t);
    while(t--){
        in(n);
        vector<Pint> points;
        for(int i = 0; i < n; i ++) {
            int y;
            in(y);
            points.push_back({i+1,y});
        }
        auto hull = convexHull(points);
        LL ans = 0;
        for(int i = 1; i < hull.size(); i ++) {
            ans = max(ans, hull[i].x - hull[i-1].x);
        }
        printf("%lld\n", ans);

    }


    
    return 0;
}
