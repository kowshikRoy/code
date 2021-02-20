#include <bits/stdc++.h>

#define MAXN          100
#define MAXM          100010
#define MAXP          666666
#define MAX           10000010
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define isprime(x)    (((x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))

using namespace std;

namespace pcf {
    long long dp[MAXN][MAXM];
    unsigned int ar[(MAX >> 6) + 5] = {0};
    int len                         = 0, primes[MAXP], counter[MAX];

    void Sieve() {
        setbit(ar, 0), setbit(ar, 1);
        for (int i = 3; (i * i) < MAX; i++, i++) {
            if (!chkbit(ar, i)) {
                int k = i << 1;
                for (int j = (i * i); j < MAX; j += k) setbit(ar, j);
            }
        }

        for (int i = 1; i < MAX; i++) {
            counter[i] = counter[i - 1];
            if (isprime(i)) primes[len++] = i, counter[i]++;
        }
    }

    void init() {
        Sieve();
        for (int n = 0; n < MAXN; n++) {
            for (int m = 0; m < MAXM; m++) {
                if (!n) dp[n][m] = m;
                else
                    dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
            }
        }
    }

    long long phi(int n, long long m) {
        if (n == 0) return m;
        if ((long long)primes[n - 1] * primes[n - 1] >= m)
            return counter[m] - n + 1;
        if (m < MAXM && n < MAXN) return dp[n][m];
        return phi(n - 1, m) - phi(n - 1, m / primes[n - 1]);
    }

    long long Lehmer(long long m) {
        if (m < MAX) return counter[m];

        long long w, res = 0;
        int i, a, s, c, x, y;
        s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
        a = counter[y], res = phi(a, m) + a - 1;
        for (i = a; primes[i] <= s; i++)
            res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
        return res;
    }
}  // namespace pcf

long long solve(long long n) {
    int i, j, k, l;
    long long x, y, res = 0;

    for (i = 0; i < pcf::len; i++) {
        x = pcf::primes[i], y = n / x;
        if ((x * x) > n) break;
        res += (pcf::Lehmer(y) - pcf::Lehmer(x));
    }

    for (i = 0; i < pcf::len; i++) {
        x = pcf::primes[i];
        if ((x * x * x) > n) break;
        res++;
    }

    return res;
}

int main() {
    pcf::init();
    long long n, res;

    while (scanf("%lld", &n) != EOF) {
        res = solve(n);
        printf("%lld\n", res);
    }
    return 0;
}
