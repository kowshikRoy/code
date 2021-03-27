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
 * Date: 2021-03-26
 * Task: game-on-mars
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve(int cs) {
    int n, x, y;
    cin >> n;
    int g = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        g ^= x ^ y;
        v.push_back(x);
        v.push_back(y);
    }
    printf("Case %d: %s\n", cs, g ? "Alice" : "Bob");
    if(g) {
        dbg(v);
        dbg(g);
        int ans = 0;
        for(auto p: v) {
            int t = p ^ g;
            if(p > t) ans ++;
        }
        printf("%d\n", ans);

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--) { solve(++cs); }
    return 0;
}
