#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
/*------- Constants---- */

#define LL        long long
#define Ulong     unsigned long long
#define REP(i, n) for (long long i = 0; i < n; i++)
#define mp        make_pair
#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define PI        acos(-1.0)
#define EPS       1e-14
#define F         first
#define S         second
#define di(x) \
    int x;    \
    input(x)
#define in(x)               input(x)
#define in2(x, y)           in(x), in(y)
#define in3(x, y, z)        in(x), in2(y, z)
#define lc                  ((n) << 1)
#define rc                  ((n) << 1 | 1)
#define db(x)               cout << #x << " -> " << x << endl
#define nl                  cout << endl
#define ms(ara_name, value) memset(ara_name, value, sizeof(ara_name))
#define IO                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define READ  freopen("/home/matrixcode/Desktop/in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
template <class T> inline void input(T &x) {
    register char c = getchar();
    x = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
        ;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    for (; c > 47 && c < 58; c = getchar()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

/***************************** END OF TEMPLATE *******************************/

const int N = 1e5 + 5;

vector<int> G[N];
bool vis[N];
LL dp[N][2];
LL mod = 1e9 + 7;

void dfs(int u) {
    vis[u] = 1;
    bool leaf = true;
    for (auto v : G[u]) {
        if (vis[v] == 0) {
            leaf = false;
            dfs(v);
            dp[u][0] += dp[v][0] + dp[v][1];
            dp[u][1] += dp[v][0];
        }
    }
    if (leaf) dp[u][0] = dp[u][1] = 1;
    dp[u][0] %= mod;
    dp[u][1] %= mod;
}

int main() {
    int n;
    in(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        in2(u, v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
}
