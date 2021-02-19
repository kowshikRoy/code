#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long x, sum = 0, ans = 0;
    scanf("%d %lld", &n, &x);
    map<long long, long long> cnt;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        sum += a;
        auto it = cnt.find(sum - x);
        if (it != cnt.end()) ans += it->second;
        cnt[sum]++;
    }
    printf("%lld\n", ans);
}
