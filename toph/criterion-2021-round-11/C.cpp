/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: c 
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



const int N = 3e4+4 , LG = 20;
int n;
int P[N][20], lev[N], ch = 0;
int chainNo[N], head[N], subsize[N], child[N], pos[N];
int Ar[N], tot = 0 , value[N];

vector<int> G[N];
int seg[N*4];


void build(int n,int b,int e)
{
    if(b==e) {
        seg[n] = Ar[b];return;
    }
    int mid= (b+e)/2;
    build(lc,b,mid);
    build(rc, mid+1,e);
    seg[n] = seg[lc] + seg[rc];
}
void update(int n,int b,int e,int pos,int v)
{
    if(b==e && b== pos) {
        seg[n] = v;
        return ;
    }
    int mid = (b+e)/2;
    if(pos <= mid ) update(lc,b,mid,pos,v);
    else update(rc,mid+1,e,pos,v);
    seg[n] = seg[lc] + seg[rc];
}
 
int query(int n,int b,int e,int i,int j)
{
    if(b>j||e<i) return 0;
    if(b>=i && e <= j ) {
        return seg[n];
    }
    int mid = (b+e)/2;
    return query(lc,b,mid,i,j) + query(rc,mid+1,e,i,j);
}
void dfs(int u,int p)
{
    subsize[u] = 1;
    for(int i = 0; i < G[u].size(); i ++ ) {
        int v = G[u][i];
        if(v == p ) continue;
        lev[v] = 1  + lev[u];
        P[v][0] = u; // Modify
        dfs(v,u);
 
        subsize[u] += subsize[v];
        if(child[u] == -1 || subsize[v] > subsize[child[u]] ) {
            child[u] = v;
        }
 
    }
}
void HLD(int u,int p)
{
    if(head[ch] == -1) head[ch] = u;
    Ar[ ++tot ] = value[u];
    pos[u] = tot;
    chainNo[u] = ch;
 
    if(child[u]  > 0 ) HLD(child[u], u );
    for(int i = 0; i < G[u].size(); i ++ ) {
        int v = G[u][i];
        if(v == p || v == child[u]) continue;
        ++ch;
        HLD(v,u);
    }
}
 
int LCA(int u,int v)
{
    if(lev[u] > lev[v]) swap(u,v);
    int d = lev[v] - lev[u];
    for(int i = LG - 1; i >= 0 ;  i -- ) {
        if( d  &1<<i){
            v = P[v][i];
        }
    }
    
    if(u==v) return u;
    for(int i = LG-1; i >= 0 ; i -- ) {
        if(P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[v][0];
}
 
int queryUp(int from, int to) // Climb up to 
{
    int ret = 0;
    while(chainNo[from ] != chainNo[to] ) {
        int h = head[chainNo[from]];
        ret += query(1,1,tot, pos[h], pos[from]); // Modify 
        from = P[h][0];
    }
    ret += query(1,1,tot,pos[to], pos[from]); // Modify
    return ret;
}
void process()
{
    memset(P,-1,sizeof(P));
    memset(head,-1,sizeof(head));
    memset(child,-1,sizeof(child));
    
    tot = 0 , ch = 0;
    dfs(1,-1);
    HLD(1,-1);
    build(1,1,tot);
    for(int i = 1; i < LG; i ++ ) {
        for(int j = 1; j <= n; j ++ ) if(P[j][i-1] !=-1 ) P[j][i] = P[P[j][i-1]][i-1];
    }
}



int main() {
    int q;
    in2(n,q);
    for(int i = 0; i < n-1; i ++){
        int a,b;
        in2(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }

    process();
    while(q--){
        string str;
        scanf("%s", str);
        if(str.compare("Answer") == 0){

    return 0;
}
