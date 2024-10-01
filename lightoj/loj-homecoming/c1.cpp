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

const int INF = 1 << 28;

int main() {
    int t, cs = 0;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<ll> a(n), p(n);
        int sum = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
        sort(a.begin(), a.end());

        function<int(vector<ll>)> dfs = [&](vector<ll> v) -> int {
            sort(v.begin(), v.end());
            if (v.size() > n) return INF;
            if (v == a) return 0;

            int ret = INF;
            for (int idx = 0; idx < v.size(); idx++) {
                int p = v[idx];
                if (k == 2) {
                    for (int i = 1; i < p; i++) {
                        int j          = p - i;
                        vector<ll> nv = v;
                        nv[idx]        = i;
                        nv.push_back(j);
                        ret = min(ret, p + dfs(nv));
                    }
                }
                if(k == 3) {
                    for(int i = 1; i < p; i ++) {
                        for(int j = 1; i + j < p; j ++) {
                            int k = p - i - j;
                            vector<ll> nv = v;
                            nv[idx]        = i;
                            nv.push_back(j);
                            nv.push_back(k);
                            ret = min(ret, p + dfs(nv));
                        }
                    }
                }
                            
            }
            return ret;
        };

        printf("Case %d: %lld\n", cs, dfs({sum}));
    }
    return 0;
}
