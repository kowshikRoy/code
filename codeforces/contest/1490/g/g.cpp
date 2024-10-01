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
 * Date: 2021-03-29
 * Task: g
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n, m;

    cin >> n >> m;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    ll pre = 0, maxe = INT_MIN;
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (pre > maxe) {
            se.insert({pre, i});
            maxe = pre;
        }
    }
    dbg(se);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto p = se.lower_bound({x, -1});
        if (p == se.end()) {
            if (s > 0) {
                ll turn = (x - se.rbegin()->first)/s;
                ll ans = turn * n ;
                ll rm = x - turn * s;
                while(true) {
                    p = se.lower_bound({rm,-1});
                    if(p == se.end()) {
                        ans += n;
                        rm -= s;
                    }
                    else {
                        cout << ans + p->second << " ";
                        break;
                    }
                }


            } else
                cout << -1 << " ";
        } else {
            cout << p->second << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
