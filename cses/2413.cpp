/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-22
 * Task: 2413 
 */

#include<bits/stdc++.h>
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

const int N = 1e1+6, mod = 1e9 + 7;
long long p1[N], p2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    p1[0] = 1;
    long long sum = 1;
    for(int i = 1; i < N; i ++) {
        p1[i] = sum;
        sum = (sum + p1[i]) % mod;
    }
    vector<int> x(10, -1);
    debug(x); 
    /* for(int i =1 ; i <= 10; i ++) printf("p[%d] = %lld\n", i, p1[i]); */
    /* for(int i = 1; i < N; i ++) { */
    /*     long long v = 0; */
    /*     for(int k = 1; k <= i - k; k ++) { */
    /*         v += p2[k] * p2[i-k]; */
    /*     } */
    /*     v += 2 * p1[i]; */
    /*     p2[i] = v; */
    /* } */
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << p2[n] << endl;
    }
}
