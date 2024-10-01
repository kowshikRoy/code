/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: mehta-and-the-typical-supermarket
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> nums(1 << n);
    vector<int> sign(1 << n);
    const ll M = 2e18 + 1;
    for (int i = 0; i < 1 << n; i++) {
        ll t  = 1;
        int f = 1;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                f *= -1;
                ll g = __gcd(t, a[j]);
                if (t / g > M / a[j]) {
                    t = M;
                    break;
                } else
                    t = t / g * a[j];
            }
        }
        sign[i] = f;
        nums[i] = t;
    }

    auto fun = [&](ll m) {
        ll ans = 0;
        for (int i = 0; i < 1 << n; i++) { ans += sign[i] * (m / nums[i]); }
        return m - ans;
    };

    cin >> d;
    while (d--) {
        ll l, r;
        cin >> l >> r;
        cout << fun(r) - fun(l - 1) << endl;
    }
    return 0;
}
