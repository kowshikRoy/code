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
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;
    ll m   = min(a, min(b, c));
    if (sum % 9 == 0 && (sum / 9 <= m)) cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
