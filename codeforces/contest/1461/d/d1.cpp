#include<bits/stdc++.h>
using namespace std;

/*************************** MACROS **************************/

#define ld long double
#define ll long long  
#define ull unsigned long long
#define vll vector<ll>
#define pb push_back
#define S second
#define F first
#define B begin()
#define E end()
#define W(x) while(x--)
#define pll pair< ll,ll >
#define vpll vector< pll >
#define qll queue<ll>
#define dqll deque<ll>
#define qpll queue<pll>
#define dqpll deque<pll>
#define pqll priority_queue<ll>
#define pqpll priority_queue<pll>
#define Line cout<<"\n**************************\n\n";

/*************************** CONST ******************************/

const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll MIN_LL = -1e18;
const ll MAX_LL = 1e18;
const int MAX_INT = 1e9;
const int MIN_INT = -1e9;
const ld pie = 3.1415926535;

/************************** POW UTIL *****************************/

ll fpow(ll n,ll p){;ll m=1;while(p){if(p%2)m*=n;p>>=1;n*=n;}return m;}
ll mfpow(ll n,ll p,ll M){ll m=1;n%=M;while(p){if(p%2)m=(m*n)%M;n=(n*n)%M;p>>=1;}return m%M;}
ll invmod(ll n,ll m){return mfpow(n,m-2,m);}

/*************************** VARIABLES **************************/

const vll days={31,28,31,30,31,30,31,31,30,31,30,31};
	 
bool br,br1,br2; 
char ch,ch1,ch2;

ll n, m, k, x, y, z, d, mini, maxi, l, r, sum, t, w, h;
pll p, p1, p2;

string s, s1, s2, s3;

multiset<ll> mst;
set<ll> st, st1, st2, st3;

map<ll, ll> mp, mp1, mp2;

/**************************** FXNS ****************************/

void process(vector<ll> &v, int x, int y, vector<ll> &pre, set<ll> &st)
{
	st.insert(pre[y]-(x?pre[x-1]:0));
	int mid_ind = upper_bound(v.begin(), v.end(), (v[x]+v[y])/2)-v.begin();
	// cout<<"@ "<<x<<" "<<mid_ind<<" "<<y<<endl;
	// cin>>ch;
	if(mid_ind != y+1)
	{
		process(v, x, mid_ind-1, pre, st);
		process(v, mid_ind, y, pre, st);
	}
}

void solve()
{
	cin>>t;

	W(t)
	{
		cin>>n>>m;
		set<ll> st;
		vll v(n), pre(n);

		for(auto &i:v)cin>>i;
		sort(v.begin(), v.end());

		pre[0] = v[0];
		for(int i=1;i<n;i++)pre[i] = pre[i-1]+v[i];
		
		process(v, 0, n-1, pre, st);
		cout<<st.size()<<endl;

		for(int i=0;i<m;i++)
		{
			cin>>x;
			cout<<(st.count(x)?"Yes":"No")<<endl;
		}
	}
}


/*************************** MAIN ****************************/
 
int main(){
 
 
	// #ifndef ONLINE_JUDGE
	        // freopen("input.txt", "rt", stdin);
	        // freopen("output.txt", "wt", stdout);
	// #endif
 
	ios_base::sync_with_stdio(0);	
	cin.tie(NULL);cout.tie(NULL);

	solve();

	return 0;
}

