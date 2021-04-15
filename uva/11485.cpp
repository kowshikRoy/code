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
 * Date: 2021-04-09
 * Task: 11485
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    while (cin >> n) {
        if (!n) break;
        vector<int> f(n);
        REP(i, n) {
            double x;
            cin >> x;
            f[i] = (int)(x * 10 + .001);
        }
        dbg(f);
        vector<vector<ll>> dp(n + 1, vector<ll>(9,-1));

        function<ll(int pos, int taken)> dfs = [&](int pos, int taken) -> ll {
            if (taken == 0) return 0;
            dbg(pos, taken);
            if (pos >= n) return -1;
            if (dp[pos][taken] != -1) return dp[pos][taken];

            ll ret = 0;
            for (int t = 0; t <= taken; t++) {
                ll nxt =
                    dfs(pos + 1, taken - t) + t * (f[pos] - (f[pos] / 10) * 10);
                if (nxt < 0) continue;
                dbg(nxt);
                ret += nxt;
            }
            return dp[pos][taken] = ret;
        };

        cout << dfs(0, 8) << endl;
    }

    return 0;
}
