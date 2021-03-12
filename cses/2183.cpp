/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 2183
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);
    long long pre = 0;
    for (int i = 0; i < n; i++) {
        if (pre + 1 < h[i]) {
            cout << pre + 1 << endl;
            return 0;
        }
        pre += h[i];
    }
    cout << pre + 1 << endl;
}
