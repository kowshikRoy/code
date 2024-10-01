#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
   
/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


int dp[N][22];
int iMin[N][22];
int mn[N];
void initRMQ(int n,int a[])
{
    mn[0]=-1;
    for(int i= 1;i<=n;i++) dp[i][0] = a[i], mn[i]=mn[i/2]+1;
    for(int j= 1; (1<<j) <= n; j ++ ){
        for(int i = 1; i + (1<<j) - 1 <= n ; i ++ ) {
            dp[i][j] = __gcd(dp[i][j-1] , [i + (1<<(j-1))][j-1]);
            iMin[i][j] = min(iMin[i][j-1] , iMin[i + (1<<(j-1))][j-1]);

        }
    }
}
int askRMQ(int L,int R)
{
    int k = mn[R-L+1];
    return __gcd(dp[L][k], dp[R - (1<<k) + 1][k]);
}

int askMin(int L, int R) {
    int k = mn[R-L+1];
    return min(iMin[L][k], iMin[R - (1<<k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> L(n + 1);
        for(int i = 1; i <= n; i ++) {
            int j = i - 1;
            while(j > 0 && a[j] >= a[i]) j = L[j];
            L[i] = j;
        }

        vector<array<int, 3>> e;
        for (int i = 1; i < n; i++) e.push_back({i, i + 1, p});
        for (int i = 2; i <= n; i++) {
            int high = i -1;
            while(high >= 1) {
                int t = askRMQ(high, i);
                while(low <= high) {
                    int mid = (low + high)/2;
                    int g = askRMQ(mid, i);
                    if(g >= t) {
                        ans = mid;
                        high = mid  -1;
                    }
                    else low = mid + 1;
                }
            }
        }

        sort(e.begin(), e.end(), [](auto a, auto b) { return a[2] < b[2]; });
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) f[i] = i;

        function<int(int)> Find = [&](int u) -> int {
            if (f[u] == u) return u;
            return f[u] = Find(f[u]);
        };
        ll ans = 0;
        dbg(e);

        for (auto ed : e) {
            int u = Find(ed[0]), v = Find(ed[1]);
            if (u != v) {
                ans += ed[2];
                f[u] = v;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
