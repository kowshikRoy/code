/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

unordered_set<ll> se;
const ll M = 1e12;
void solve() {
    ll n;
    cin >> n;
    for (ll i = 1; i * i * i <= n; i++) {
        if (se.count(n - i * i * i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (ll i = 1; i * i * i <= M; i++) se.insert(i * i * i);

    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
