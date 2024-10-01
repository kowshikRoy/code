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
 * Date: 2021-04-14
 * Task: e
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)
const int inf = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    REP(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<int> d(n + 1, inf);
    vector<set<int>> s(n + 1);
    priority_queue<pair<int, int>> q;
    d[1] = 0;
    q.push({0, 1});
    dbg(g);

    while (!q.empty()) {
        auto node = q.top();
        q.pop();
        int u = node.second;
        for (auto v : g[u]) {
            int nxt = v.first, cost = s[u].count(v.second) ? 0 : 1;
            if (d[nxt] > d[u] + cost) {
                d[nxt] = d[u] + cost;
                q.push({-d[nxt], nxt});
                s[nxt].clear();
                s[nxt].insert(v.second);
            } else if (d[nxt] == d[u] + cost) {
                s[nxt].insert(v.second);
            }
        }
    }
    dbg(d);
    if (d[n] == inf) cout << -1 << endl;
    else
        cout << d[n] << endl;

    return 0;
}
