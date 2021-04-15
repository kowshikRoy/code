/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-31
 * Task: 1712
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

ll bigmod(ll a, ll b, ll m) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
void solve() {
    const int mod = 1e9 + 7;
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = bigmod(b, c, mod - 1);
    cout << bigmod(a, d, mod) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
