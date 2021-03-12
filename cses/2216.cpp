/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 2216
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n + 1], pos[n + 1];
    for (int i = 1; i <= n; i++) cin >> x[i], pos[x[i]] = i;

    int cnt = 0;
    for (int i = 1; i <= n;) {
        cnt++;
        int y = pos[i];
        while (i <= n && pos[i] >= y) y = pos[i], i++;
    }
    cout << cnt << endl;
}
