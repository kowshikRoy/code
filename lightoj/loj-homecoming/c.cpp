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
 * Date: 2021-04-04
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    int t, cs = 0;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<ll> a(n), p(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (i) p[i] = p[i - 1];
            p[i] += a[i];
        }
        ll now = p[n - 1];
        int v = n;
        ll sum = 0;
        dbg(now);
        while(v >= k) {
            v = (v + k - 1)/ k;
            sum += now;
        }
        REP(i,v) sum += a[i];
    
        printf("Case %d: %lld\n", cs, sum);
    }
    return 0;
}
