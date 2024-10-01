/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: a
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
        vector<int> a(n);
        REP(i, n) a[i] = i + 1;
        for (int i = 1; i + 1 < n; i += 2) {
            if (k > 0  ) {
                swap(a[i], a[i + 1]);
                k--;
            }
        }

        if (k) cout << -1 << endl;
        else {
            REP(i, n) cout << a[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
