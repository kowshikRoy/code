/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define LL           long long
#define Ulong        unsigned long long
#define REP(i, n)    for (long long i = 0; i < n; i++)
#define mp           make_pair
#define pb           push_back
#define all(x)       (x).begin(), (x).end()
#define PI           acos(-1.0)
#define EPS          1e-14
#define F            first
#define S            second
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
#define lc           ((n) << 1)
#define rc           ((n) << 1 | 1)
#define db(x)        cout << #x << " -> " << x << endl

template <class T> inline void input(T &x) {
    register char c = getchar();
    x               = 0;
    int neg         = 0;
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
const int N = 5005;
int n;
vector<LL> tag, s;

int main() {
    int t;
    in(t);
    while (t--) {
        in(n);
        tag.resize(n + 1);
        s.resize(n + 1);
        for (int i = 1; i <= n; i++) in(tag[i]);
        for (int i = 1; i <= n; i++) in(s[i]);
        vector<long long> dp(n + 1, 0);
        for (int j = 2; j <= n; j++) {
            for (int i = j - 1; i >= 1; i--) {
                if (tag[i] != tag[j]) {
                    auto p = abs(s[i] - s[j]);
                    auto q = max(dp[i], dp[j] + p);
                    auto r = max(dp[j], dp[i] + p);
                    dp[i]  = q;
                    dp[j]  = r;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    return 0;
}
