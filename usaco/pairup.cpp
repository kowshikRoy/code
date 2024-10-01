/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-28
 * Task: pairup
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    vector<array<ll, 2>> cow(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> cow[i][0] >> cow[i][1];
    sort(cow.begin(), cow.end(), [](auto a, auto b) { return a[1] < b[1]; });
    for (int i = 0; i < n; i++) a[i] = cow[i][0];

    ll ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        ans = max(ans, cow[l][1] + cow[r][1]);
        if (l == r) {
            ans = max(ans, cow[l][1] + cow[l][1]);
            break;
        }
        auto k = min(a[l], a[r]);
        a[l] -= k;
        a[r] -= k;
        if (a[l] == 0) l++;
        if (a[r] == 0) r--;
    }
    cout << ans << endl;
}

int main() {
#ifndef LOCAL
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
#endif

    ios::sync_with_stdio(false), cin.tie(0);
    solve();
}
