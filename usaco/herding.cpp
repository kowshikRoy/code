/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-26
 * Task: herding
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    sort(x.begin(), x.end());
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
        while (x[r] - x[l] > n) l++;
        ans = max(ans, r - l + 1);
    }
    printf("%d\n%d\n", n - ans, ans);
}

int main() {
#ifndef LOCAL
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif

    ios::sync_with_stdio(false), cin.tie(0);
    solve();
}
