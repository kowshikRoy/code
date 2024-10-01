/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);

    REP(i, n) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = A[0], pre = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] - A[i - 1] <= k) pre += A[i];
        else
            pre = A[i];
        ans = max(ans, pre);
    }
    cout << ans << endl;
    return 0;
}
