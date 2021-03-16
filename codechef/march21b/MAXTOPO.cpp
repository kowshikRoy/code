/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-07
 * Task: MAXTOPO 
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
const int N = 5e5+5;

int sub[N];
vector<long double>f,dp,ans;
vector<long long> Ans, F, Dp, R;
vector<vector<int>>G;

long long int M = 1e9 + 7;

int n,k;
void dfs(int u, int p) {
    sub[u] = 1;
    Dp[u] = 1;
    dp[u] = 0;
    for(auto v: G[u]) if(v != p) {
        dfs(v,u);
        sub[u] += sub[v];
        dp[u] += dp[v] - f[sub[v]];
        Dp[u] = ((Dp[u] * Dp[v]) % M * R[sub[v]] ) % M;
    }
    dp[u] += f[sub[u] -1];
    Dp[u] = (Dp[u] * F[sub[u] - 1]) % M;
}

void dfs2(int u, int p, long double c, long long m){
    ans[u] = c + f[n-1] - f[n-sub[u]];
    Ans[u] = ((m * F[n-1]) % M * R[n-sub[u]]) % M;
    
    for(auto v: G[u]) if(v != p) {
        ans[u] += dp[v] - f[sub[v]];
        Ans[u] = ((Ans[u] * Dp[v]) % M * R[sub[v]]) % M;
    }
    for(auto v: G[u]) if (v != p) {
        long double c = ans[u] + f[n - 1 - sub[v]] - f[n-1] + f[sub[v]] - dp[v] ;
        long long mul = (((Ans[u] * F[n-1-sub[v]]) % M * R[n-1]) % M * F[sub[v]]) % M;
        mul = (mul * modinverse(Dp[v], M)) % M;
        dfs2(v, u, c, mul);
    }
}

struct node{
    int a;
    long double ans;
    long long m;
    bool operator<(const node &rhs) const{
        if(fabs(ans - rhs.ans) < 1e-12) return a > rhs.a;
        return ans > rhs.ans;
    }
};

int main() {
    f.resize(N);
    F.resize(N);
    R.resize(N);

    f[0] = 0;
    for(int i = 1; i < N; i ++) f[i] = f[i-1] + log(i);
    F[0] = 1;
    for(int i = 1; i < N; i ++) F[i] = (F[i-1] * i) % M;
    for(int i = 0; i < N; i ++) R[i] = modinverse(F[i], M);

    int t ;
    in(t);
    while(t--){
        in2(n,k);
        dp.resize(n);
        Dp.resize(n);
        Ans.resize(n);
        ans.resize(n);
        G.resize(n);
        for(int i = 0; i < n-1; i ++) {
            int x,y;
            in2(x,y);
            x -- , y --;
            G[x].pb(y);
            G[y].pb(x);
        }
        dfs(0,-1);
        dfs2(0,-1,0,1);
        vector<node>v;
        for(int i = 0; i < n; i ++) v.push_back({i,ans[i], Ans[i]});
        sort(v.begin(), v.end());
        node p = v[k - 1];

        printf("%d %lld\n", p.a + 1, p.m);
        for(int i = 0; i < n; i ++) G[i].clear() ;
    }

    
    return 0;
}
