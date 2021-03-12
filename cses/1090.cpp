/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1090
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        ans++;
        if (p[l] + p[r] <= x) {
            l++;
            r--;
        } else
            r--;
    }
    cout << ans << endl;
}
