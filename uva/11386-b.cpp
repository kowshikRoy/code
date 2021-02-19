#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
unordered_map<long long, long long> cnt;
long long a[N], b[N];
long long nc2(long long n) { return n * (n - 1) / 2; }
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]), b[i] = a[i], cnt[a[i]]++;
        sort(a, a + n);
        sort(b, b + n);
        int nu = unique(b, b + n) - b;

        long long ans = 0;
        for (int i = 0; i < nu; i++) {
            if (cnt.count(2 * b[i])) ans += cnt[2 * b[i]] * nc2(cnt[b[i]]);
        }

        for (int k = 2; k < nu; k++) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (b[i] + b[j] == b[k]) {
                    ans += cnt[b[i]] * cnt[b[j]] * cnt[b[k]];
                    i++, j--;
                } else if (b[i] + b[j] < b[k])
                    i++;
                else
                    j--;
            }
        }
        printf("%lld\n", ans);
        cnt.clear();
    }
}
