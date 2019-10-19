#include<bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define LL                      long long
#define Ulong                   unsigned long long
#define REP(i,n)                for(long long i=0; i < n ; i++ )
#define mp                      make_pair
#define pb                      push_back
#define all(x)                  (x).begin(),(x).end()
#define PI                      acos(-1.0)
#define EPS                     1e-14
#define F                       first
#define S                       second
#define di(x)                   int x; input(x)
#define in(x)                   input(x)
#define in2(x,y)                in(x),in(y)
#define in3(x,y,z)              in(x),in2(y,z)
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl
#define nl                      cout<<endl
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))
#define IO                      ios_base::sync_with_stdio(0);cin.tie(0)
#define READ                    freopen("/home/matrixcode/Desktop/in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
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

/***************************** END OF TEMPLATE *******************************/

const int N = 3e3+5;
int dp[N][N];
pair<int,int> ptr[N][N];
int main()
{

  string s, t;
  cin >> s >> t;
  for(int i = 0; i < s.size(); i ++) {
    for(int j = 0; j < t.size(); j ++) {
      if(s[i] == t[j]) {
        dp[i+1][j+1] = 1 + dp[i][j];
        ptr[i+1][j+1] = make_pair(i,j);
      }
      else {
        if(dp[i][j+1] > dp[i+1][j]) 
          dp[i+1][j+1] = dp[i][j+1] , ptr[i+1][j+1] = make_pair(i,j+1);
        else dp[i+1][j+1] = dp[i+1][j], ptr[i+1][j+1] = make_pair(i+1,j);
      }
    }
  }
  int lcs = dp[s.size()][t.size()];
  cout <<lcs << endl;
  for(int i = 0; i <= s.size(); i ++) {
    for(int j = 0; j <= t.size(); j ++) {
      printf("%d ", dp[i][j]);
    }
    cout << endl;
  }
  for(int i = 0; i <= s.size(); i ++) {
    for(int j = 0; j <= t.size(); j ++) {
      printf("(%2d,%2d) ", ptr[i][j].F, ptr[i][j].S);
    }
    cout << endl;
  }
  string ans;
  int x = s.size(), y = t.size();
  
  while(lcs ) {
    cout << lcs << endl;
    if( ptr[x][y] == make_pair(x-1,y-1))
      ans.push_back(s[x-1]), lcs --;
    x = ptr[x][y].F;
    y = ptr[x][y].S;
    cout << x << " " << y << endl;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}

