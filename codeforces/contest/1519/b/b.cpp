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
 * Date: 2021-04-29
 * Task: b
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 102;
const int M = 10001;
bitset<M + 1> vis[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vis[1][1][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i + 1 < N) {
                for (int k = 0; k + j <= M; k++) {
                    if (vis[i][j][k]) vis[i + 1][j][k + j] = 1;
                }
            }
            if (j + 1 < N) {
                for (int k = 0; k + i <= M; k++) {
                    if (vis[i][j][k]) vis[i][j + 1][k + i] = 1;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << (vis[n][m][k] ? "YES" : "NO") << endl;
    }

    return 0;
}
