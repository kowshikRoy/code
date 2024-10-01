/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-28
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll g = 0;
    for (int i = 1; i < n; i++) g = __gcd(g, a[i] - a[0]);
    for (int i = 0; i < m; i++) {
        ll b;
        cin >> b;
        if (n == 1) printf("%lld ", a[0] + b);
        else
            printf("%lld ", gcd(a[0] + b, g));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
