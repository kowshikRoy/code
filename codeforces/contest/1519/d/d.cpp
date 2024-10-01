#include <bits/stdc++.h>
using namespace std;
 
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}
 
void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-29
 * Task: d
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
 
    vector<vector<ll>> f(n + 1);
    vector<vector<ll>> r(n + 1);
    vector<vector<ll>> dp(n + 1);
    ll ans = 0;
 
 
    f[1].resize(n);
    r[1].resize(n);
    dp[1].resize(n);
    for (int i = 0; i < n; i++) {
        f[1][i]  = a[i] * b[i];
        r[1][i]  = a[i] * b[i];
        dp[1][i] = max(f[1][i], r[1][i]);
        ans      = max(ans, dp[1][i]);
    }
    f[2].resize(n);
    r[2].resize(n);
    dp[2].resize(n);
    for (int i = 0; i + 1 < n; i++) {
        f[2][i]  = a[i] * b[i] + a[i + 1] * b[i + 1];
        r[2][i]  = a[i] * b[i + 1] + a[i + 1] * b[i];
        dp[2][i] = max(f[2][i], r[2][i]);
        ans      = max(ans, dp[2][i]);
    }
 
    for (int len = 3; len <= n; len++) {
        if (len >= 3) {
            dp[len - 3].clear();
            r[len - 3].clear();
            f[len - 3].clear();
            dp[len-3].shrink_to_fit();
            f[len-3].shrink_to_fit();
            r[len-3].shrink_to_fit();
        }
        f[len].resize(n);
        r[len].resize(n);
        dp[len].resize(n);
        for (int i = 0; i + len <= n; i++) {
            int j      = i + len - 1;
            f[len][i]  = f[len - 2][i + 1] + a[i] * b[i] + a[j] * b[j];
            r[len][i]  = r[len - 2][i + 1] + a[i] * b[j] + a[j] * b[i];
            dp[len][i] = max(f[len][i], r[len][i]);
            dp[len][i] = max(a[i] * b[i] + dp[len - 1][i + 1], dp[len][i]);
            dp[len][i] = max(a[j] * b[j] + dp[len - 1][i], dp[len][i]);
            ans        = max(ans, dp[len][i]);
        }
    }
 
    cout << ans << endl;
 
    return 0;
}
