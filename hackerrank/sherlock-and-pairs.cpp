/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: sherlock-and-pairs
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
        int n;
        cin >> n;
        map<int, int> cnt;
        ll ans = 0;
        REP(i, n) {
            int x;
            cin >> x;
            ans += cnt[x];
            cnt[x]++;
        }
        cout << 2 * ans << endl;
    }

    return 0;
}
