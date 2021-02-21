/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: D
 */

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}

const LL MOD = 998244353;
LL N, K, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    if (N == 1 && M == 1) {
        cout << K << endl;
        return 0;
    }

    LL ans = 0;
    for (int P = 1; P <= K; P++) {
        long long u = (bigmod(P, N, MOD) - bigmod(P - 1, N, MOD) + MOD) % MOD;
        long long v;
        v = bigmod(K - P + 1, M, MOD);
        if (N == 1) {
            v = (v - bigmod(K - P, M, MOD) + MOD) % MOD;
        } else if (M == 1) {
            v = (v - bigmod(K - P, M, MOD) + MOD) % MOD;
        }

        /* cout << u << " " << v << " " << u * v << endl; */
        ans = (ans + u * v) % MOD;
    }
    cout << ans << endl;
}
