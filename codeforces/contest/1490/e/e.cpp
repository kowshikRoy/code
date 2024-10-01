/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: e
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = i;

    sort(a.begin(), a.end(), [](auto a, auto b) { return a[0] < b[0]; });

    vector<ll> pf(n);
    for (int i = 0; i < n; i++) { pf[i] = (i ? pf[i - 1] : 0) + a[i][0]; }

    vector<int> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (pf[i] >= a[i + 1][0] && dp[i + 1]) dp[i] = 1;
        else
            break;
    }
    vector<int> out;
    for (int i = 0; i < n; i++) {
        if (dp[i]) out.push_back(a[i][1]);
    }
    sort(out.begin(), out.end());
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); i++) cout << out[i] + 1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
