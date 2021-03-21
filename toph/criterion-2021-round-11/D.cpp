/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
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
const int N = 2e5+5;
const int LG = 31;

vector<long long> down, up;
long long A[N];
vector<int>G[N];
int cnt[N][LG][2];

void dfs(int u, int p) {
    for(int i = 0; i < LG; i ++){
        int b = (A[u] >> i) & 1;
        cnt[u][i][b] ++;
    }
    down[u] = A[u];
    for(auto v: G[u]) if(v != p) {
        dfs(v,u);
        for(int i = 0; i < LG; i ++) {
            int b = (A[u] >> i) & 1;
            down[u] += (1LL << i) * cnt[v][i][b^1];
            cnt[u][i][0] += cnt[v][i][b];
            cnt[u][i][1] += cnt[v][i][b^1];
        }
    }
}

void dfs2(int u, int p, vector<int>upto, int i) {
    int b = (A[u] >> i) & 1;
    up[u] += (1LL << i) * upto[b^1];
    vector<int> temp = {0,0};
    temp[0] = cnt[u][i][0] + upto[b];
    temp[1] = cnt[u][i][1] + upto[b^1];


    for(auto v: G[u]) if(v != p) {
        auto nxt = temp;
        nxt[0] -= cnt[v][i][b];
        nxt[1] -= cnt[v][i][b^1];
        dfs2(v, u, nxt,i);
    }
}

int main() {
    int t;
    in(t);
    while(t--){
        int n;
        in(n);
        for(int i = 1; i <= n; i ++) in(A[i]);
        for(int i = 1; i <= n; i ++) memset(cnt[i], 0, sizeof cnt[i]);
        for(int i = 0; i < n-1; i ++) {
            int a,b;
            in2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }

        down.resize(n + 1, 0);
        up.resize(n + 1,0); 
        dfs(1,-1);
        for(int i = 0; i < LG; i ++) {
            vector<int> upto = {0,0};
            dfs2(1,-1,upto,i);
        }

        for(int i = 1; i <= n; i ++) {
            printf("%lld%s",down[i] + up[i], i == n ? "\n" : " ");
        }
        for(int i = 1; i <= n; i ++) G[i].clear(), memset(cnt[i], 0, sizeof cnt[i]);
        fill(all(down),0);
        fill(all(up), 0);

    }

    return 0;
}
