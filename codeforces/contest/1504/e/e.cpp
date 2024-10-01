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
 * Date: 2021-04-04
 * Task: e
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)
const ll INF = LLONG_MAX / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i][0] >> a[i][1]; }
    sort(a.begin() + 1, a.end(), [](auto x, auto y) { return x[0] < y[0]; });

    dbg(a);

    vector<ll> csum(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) csum[i] = csum[i - 1];
        csum[i] += a[i][1];
    }

    auto sum = [&](int a, int b) {
        return csum[b] - (a > 0 ? csum[a - 1] : 0);
    };

    vector<ll> dp(n + 1, INF);

    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i] = min(
                dp[i], max(a[j][1], a[j][0] - a[i][0]) + sum(i, j - 1) + dp[j]);
        }
    }
    ll ans = INF;
    for(int i = 1; i < n; i ++) ans = min(ans, csum[i-1] + max(a[i][1], a[i][0] - a[i][1]) + dp[i]);
    cout << ans << endl;
}
