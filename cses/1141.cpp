/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1141
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k[n];
    for (int i = 0; i < n; i++) cin >> k[i];

    set<int> s;
    int ans = 0;
    for (int l = 0, r = 0; r < n;) {
        int v = k[r];
        if (s.count(v)) {
            s.erase(k[l]);
            l++;
            continue;
        } else {
            s.insert(v);
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    cout << ans << endl;
}
