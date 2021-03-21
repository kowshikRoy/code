/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: B
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

template <class T> inline void input(T& x) {
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
const int N = 1e5 + 5;
const int M  = 1e9 + 7;
int Fact[N];
double fact[N];
long long R, C, L;

long double calc(long long a) {
    auto b = L + 1 - a;
    return log(R - a + 1) + log(C - b + 1) + fact[L - 1] - fact[a - 1] -
           fact[L - a];
}

int main() {
    Fact[0] = 1;
    fact[0] = 0;
    for (int i = 1; i < N; i++) {
        Fact[i] = (1LL * Fact[i - 1] * i) % M;
        fact[i] = fact[i - 1] + logl(i);
    }
    int t;
    in(t);
    while (t--) {
        in3(R, C, L);
        if (R + C - 1 < L) {
            puts("0");
            continue;
        }
        long long low = 1, high = min(L, R), mid, A = -1, B = -1;
        long double mx = -1;
        while(low <= high) {
            auto f = low + (high - low)/3;
            auto g = high - (high - low)/3;
            if(calc(f) > calc(g)) {
                A = f;
                high = g - 1;
            }
            else {
                A = g;
                low = f + 1;
            }
        }
        B = L + 1 - A;
        assert(A <= L);
        assert(B <= L);
        long long ans = (1LL * (R - A + 1) * (C - B + 1)) % M;
        ans           = (ans * Fact[L - 1]) % M;
        ans           = (ans * modinverse(Fact[A - 1], M)) % M;
        ans           = (ans * modinverse(Fact[L - A], M)) % M;
        printf("%lld\n", ans);
    }

    return 0;
}
