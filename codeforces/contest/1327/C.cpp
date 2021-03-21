#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    int a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) { cin >> a >> b; }
    for (int i = 0; i < k; i++) cin >> a >> b;
    string ans;
    for (int i = 0; i < m; i++) ans.push_back('L');
    for (int i = 0; i < n; i++) ans.push_back('U');
    int dir = 0;
    for (int i = 0; i < n; i++) {
        if (dir == 0) {
            for (int j = 0; j < m - 1; j++) ans.push_back('R');
            if (i + 1 < n) ans.push_back('D');
            dir = 1;
        } else {
            for (int j = m - 1; j >= 1; j--) ans.push_back('L');
            if (i + 1 < n) ans.push_back('D');
            dir = 0;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}
