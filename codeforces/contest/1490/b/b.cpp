/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: b
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt[3] = {0};
    for (int i = 0; i < n; i++) cnt[a[i] % 3]++;

    int each = n / 3;
    int ans  = 0;
    bool f   = true;
    while (f) {
        f = false;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > each) {
                int m = cnt[i] - each;
                cnt[(i + 1) % 3] += m;
                cnt[i] -= m;
                ans += m;
                f = true;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
