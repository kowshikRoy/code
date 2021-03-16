/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-14
 * Task: ATWNT 
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
const int N = 1e5+5;
const int C = 1e6;

int P[N], Child[N];
vector<int>G[N];
map<int,int> dp[N];
vector<pair<int,int>>Q[N];
LL Ans[N];

map<int,int> dfs(int u) {
    int k = Child[u];
    map<int,int> M;
    if(k == 0) M[1] = 1;
    else if(k == 1) M = dfs(G[u][0]);
    else {
        for(auto v: G[u]) {
            auto m = dfs(v);
            for(auto p: m) {
                if(p.first * k <= C) M[p.first * k] += p.second;
            }
        }
    }

    for(auto q: Q[u]) {
        int w = q.first, id = q.second;
        LL done = 0;
        for(auto p: M) {
            if(w % p.first == 0) 
                done += p.second * w/p.first;
        }
        Ans[id] = w - done;
    }
    return M;
}

void dfs2(int u) {
}



int main() {
    int n,q;
    in(n);
    for(int i = 2; i <= n; i ++) {
        in(P[i]);
        Child[P[i]] ++;
        G[P[i]].push_back(i);
    }

    in(q);
    for(int i = 0; i < q; i ++) {
        int v, w;
        in2(v,w);
        Q[v].push_back({w,i});
    }
    dfs(1);
    for(int i = 0; i < q; i ++) printf("%lld\n", Ans[i]);

    return 0;
}
