/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 2428
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) { cin >> a[i]; }

    int l = 0, r = 0;
    map<int, int> M;
    long long ans = 0;
    while (r < n) {
        M[a[r]]++;
        while (M.size() > k) {
            M[a[l]]--;
            if (M[a[l]] == 0) M.erase(a[l]);
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    cout << ans << endl;
}
