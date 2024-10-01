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
 * Date: 2021-04-05
 * Task: acc7p3
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> f(n + 1), P(n + 1);
    vector<array<int, 3>> e;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        if (i > 1) e.push_back({i, i - 1, f[i] - f[i - 1]});
    }

    for (int i = 1; i <= n; i++) P[i] = i;

    function<int(int)> find = [&](int u) -> int {
        if (u == P[u]) return u;
        return P[u] = find(P[u]);
    };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int u = find(a), v = find(b);
        if (u != v) { P[u] = v; }
    }

    sort(e.begin(), e.end(), [](auto a, auto b) { return a[2] < b[2]; });

    ll ans = 0;
    for (auto edge : e) {
        int u = find(edge[0]), v = find(edge[1]);
        if (u != v) {
            P[u] = v;
            ans += edge[2];
        }
    }
    cout << ans << endl;

    return 0;
}
