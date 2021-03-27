#pragma GCC optimize("Ofast,unroll-loops")
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
 * Date: 2021-03-25
 * Task: easy
 */

#include <bits/stdc++.h>
using namespace std;

#define ll           long long
#define REP(i, n)    for (int i = 0; i < (n); i++)
#define all(x)       (x).begin(), (x).end()
#define PI           acos(-1.0)
#define EPS          1e-14
#define F            first
#define S            second
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)

template <class T> inline void input(T &x) {
    char c  = getchar_unlocked();
    x       = 0;
    int neg = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
        ;
    if (c == '-') {
        neg = 1;
        c   = getchar();
    }
    for (; c > 47 && c < 58; c = getchar()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

/********************************************************/

void solve() {
    int n;
    in(n);
    vector<vector<ll>> sets(n);
    vector<int> cnt(n);
    REP(i, n) {
        int m;
        in(m);
        cnt[i] = m;
        REP(j, m) {
            ll x;
            in(x);
            sets[i].push_back(x);
        }
    }
    REP(i, n) sort(sets[i].begin(), sets[i].end());

    vector<vector<int>> neigh(n, vector<int>(n, 0));

    REP(i, n) neigh[i][i] = 0;
    REP(i, n) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            for (int p = 0, q = 0; p < sets[i].size() && q < sets[j].size();) {
                if (sets[i][p] == sets[j][q]) {
                    flag = false;
                    break;
                } else if (sets[i][p] < sets[j][q])
                    p++;
                else
                    q++;
            }
            neigh[i][j] = flag;
            neigh[j][i] = flag;
        }
    }
    vector<int> dp(1 << n, -1);

    auto unwrap = [](int n) -> vector<int> {
        vector<int> ret;
        while (n) {
            int i = __builtin_ctz(n);
            ret.push_back(i);
            n = n ^ (1 << i);
        }
        return ret;
    };

    function<int(int)> solve = [&](int mask) -> int {
        if (mask == (1 << n) - 1) return 0;
        if (dp[mask] != -1) return dp[mask];
        int ret         = 0;
        int pt          = ((1 << n) - 1) ^ mask;
        vector<int> can = unwrap(pt), curr = unwrap(mask);
        for (auto c : can) {
            bool no = false;
            for (auto now : curr) {
                if (neigh[now][c] == false) {
                    no = true;
                    break;
                }
            }
            if (!no) ret = max(ret, cnt[c] + solve(mask | (1 << c)));
        }
        return dp[mask] = ret;
    };

    printf("%d\n", solve(0));
}
int main() {
    int t;
    in(t);
    while (t--) { solve(); }
    return 0;
}
