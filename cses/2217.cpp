/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 2217
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int x[N], pos[N];

int n, m;
int get(int s) {
    int ret = 0;
    if (s - 1 >= 1 && pos[s - 1] > pos[s]) ret++;
    if (s < n && pos[s] > pos[s + 1]) ret++;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i], pos[x[i]] = i;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) ans++;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int u = x[a], v = x[b];
        ans    = ans - get(u) - get(v);
        pos[u] = b;
        pos[v] = a;
        ans    = ans + get(u) + get(v);
        cout << ans << endl;
    }
}
