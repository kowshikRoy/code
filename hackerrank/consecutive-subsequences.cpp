/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: consecutive-subsequences
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<ll, ll> cnt;
        cnt[0]  = 1;
        ll psum = 0, ans = 0;
        REP(i, n) {
            int x;
            cin >> x;
            psum += x;
            psum %= k;
            ans += cnt[psum];
            cnt[psum]++;
        }
        cout << ans << endl;
    }

    return 0;
}
