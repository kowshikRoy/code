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
 * Date: 2021-03-29
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n,m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int p = 0;

    vector<int> minc(m), maxc(m);
    for (int i = 0; i < n; i++) {
        if (p < m && s[i] == t[p]) {
            minc[p] = i;
            p++;
        }
    }
    p = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (p >= 0 && s[i] == t[p]) {
            maxc[p] = i;
            p--;
        }
    }
    dbg(minc);
    dbg(maxc);

    int ans = 0;
   for (int i = 0; i < m; i++) {
        if (i + 1 < m) { ans = max(ans, maxc[i + 1] - minc[i]); }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
