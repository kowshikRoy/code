#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 6;

int B[N], a[N], cnt[N];

long long dp[N], f[N];
int main() {
    long long n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), cnt[a[i]]++;

    sort(a, a + n);
    for (int i = 1; i < N; i++) {
        if (!cnt[i]) continue;
        for (int j = i; j < N; j += i) {
            int v = j / i;
            if (i == v) {
                f[j] += cnt[i] * (cnt[i] - 1);
            } else {
                f[j] += cnt[i] * cnt[v];
            }
        }
    }
    for (int i = 1; i < N; i++) dp[i] = dp[i - 1] + f[i];

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        long long p;
        scanf("%lld", &p);
        long long ans = n * (n - 1) - dp[p - 1];
        printf("%lld\n", ans);
    }
    return 0;
}
