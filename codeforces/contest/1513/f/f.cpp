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
 * Task: f
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
    vector<array<ll, 2>> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> a[i], A[i] = {a[i], i};
    for (int i = 0; i < n; i++) cin >> b[i], B[i] = {b[i], i};
    sort(A.begin(), A.end(), [](auto a, auto b) { return a[0] < b[0]; });
    sort(B.begin(), B.end(), [](auto a, auto b) { return a[0] < b[0]; });

    ll sum = 0;
    for (int i = 0; i < n; i++) sum += abs(a[i] - b[i]);
    ll ans = sum;

    auto sw = [&](int x, int y) {
        dbg(x,y);
        ll t = sum;
        t -= abs(a[x] - b[x]) + abs(a[y] - b[y]);
        t += abs(a[x] - b[y]) + abs(a[y] - b[x]);
        dbg(t);
        return t;
    };
    dbg(ans);

    for (int i = 0; i < n; i++) {
        auto ptr = lower_bound(B.begin(), B.end(), array<ll, 2>{a[i], -1});
        if (ptr != B.end()) { ans = min(ans, sw(i, (*ptr)[1])); }
        if (ptr != B.begin()) {
            ptr--;
            ans = min(ans, sw(i, (*ptr)[1]));
        }
        ptr = lower_bound(A.begin(), A.end(), array<ll, 2>{b[i], -1});
        if (ptr != A.end()) { ans = min(ans, sw(i, (*ptr)[1])); }
        if (ptr != A.begin()) {
            ptr--;
            ans = min(ans, sw(i, (*ptr)[1]));
        }
    }
    cout << ans<<endl;

        return 0;
}
