#include <bits/stdc++.h>
using namespace std;

const int N  = 2e5 + 5;
using LL     = long long;
const LL mod = 998244353;

LL f[N], g[N];
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

LL ncr(LL n, LL r) {
    if (n < r) return 0;
    return (((f[n] * g[r]) % mod) * g[n - r]) % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LL n, m;
    cin >> n >> m;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i < N; i++) { f[i] = (i * f[i - 1]) % mod; }
    for (int i = 0; i < N; i++) g[i] = modinverse(f[i], mod);

    long long fans = 0;
    for (int iMax = 2; iMax <= m; iMax++) {
        long long ans = 1;
        ans           = ncr(iMax - 1, n - 3);
        ans           = (ans * bigmod(2, n - 3, mod)) % mod;
        ans           = (ans * (iMax - n + 2)) % mod;
        fans          = (fans + ans) % mod;
    }
    cout << fans << endl;

    return 0;
}
