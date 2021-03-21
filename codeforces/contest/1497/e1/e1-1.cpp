/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: e1-1
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
const int M = 1e7 + 7;
const int N = 2e5 + 5;
int vis[M + 1];
int A[N];

int main() {
    for (int i = 2; i <= M; i++) {
        if (vis[i]) continue;
        vis[i] = i;
        for (int j = i; j <= M; j += i) { vis[j] = i; }
    }

    int t, n, k;
    in(t);
    while (t--) {
        in2(n, k);
        for (int i = 0; i < n; i++) {
            int x, ret = 1;
            cin >> x;
            while (x > 1) {
                int p = vis[x], cnt = 0;
                while (x % p == 0) cnt++, x /= p;
                if (cnt & 1) ret *= p;
            }
            A[i] = ret;
        }
        int cnt = 1;
        map<int, int> Map;
        for (int i = 0; i < n; i++) {
            if (Map.count(A[i])) {
                cnt++;
                Map.clear();
                Map[A[i]] = i;
            }
            Map[A[i]] = i;
        }
        cout << cnt << endl;
    }

    return 0;
}
