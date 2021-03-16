/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-08
 * Task: MAXTOPO-1 
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
const int N = 101;
int n,k;
vector<int> G[N];
long long Dp[N], sub[N], F[N], R[N];
long double dp[N], f[N];
const long long M = 1e9 + 7;


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
int main() {
    f[0] = 0;
    for(int i = 1; i < N; i ++) f[i] = f[i-1] + log(i);
    F[0] = 1;
    for(int i = 1; i < N; i ++) F[i] = (F[i-1] * i) % M;
    for(int i = 0; i < N; i ++) R[i] = modinverse(F[i], M);

    int t;
    in(t);
    while(t--){
        in2(n,k);
        for(int i = 0; i < n-1; i ++) {
            int x,y;
            in2(x,y);
            G[x].pb(y);
            G[y].pb(x);
        }
        vector<pair<long long, int>> vec;
        for(int i = 1; i <= n; i ++) {
            dfs(i,-1);
            vec.push_back({Dp[i], i});
        }
        sort(vec.begin(), vec.end(), [](auto a, auto b) {
                if(a.first == b.first) return a.second > b.second;
                return a.first > b.first;
                });

        auto node = vec[k - 1];
        printf("%d %lld\n", node.second, node.first);
        for(int i = 1; i <= n; i ++) G[i].clear();

    }

    
    return 0;
}
