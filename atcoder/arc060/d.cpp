/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-05
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;
    auto f = [&](ll b, ll n) -> ll {
        ll ans = 0;
        while (n) ans += n % b, n /= b;
        return ans;
    };

    for (ll b = 2; b * b <= n; b++) {
        auto k = f(b, n);
        if (k == s) {
            cout << b << endl;
            return 0;
        }
    }

    ll t = n - s;
    vector<ll> d;
    for (ll b = 1; b * b <= t; b++) {
        if (t % b == 0) {
            d.push_back(b);
            d.push_back(t / b);
        }
    }

    sort(d.begin(), d.end());
    for (auto b : d) {
        if (b < 1) continue;
        if (f(b + 1, n) == s) {
            cout << b + 1 << endl;
            return 0;
        }
    }
    if (n == s) {
        cout << n + 1 << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}
