#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int prime = 0;
    vector<bool> vis(n + 1, 0);
    int col[n + 1];
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        prime++;
        for (int j = i; j <= n; j += i) {
            if (vis[j] == 0) col[j] = prime;
            vis[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++) cout << col[i] << " ";
    return 0;
}
