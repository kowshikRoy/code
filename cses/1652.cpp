#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int dp[N][N];
char f[N][N];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> (f[i] + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] +
                       (f[i][j] == '*' ? 1 : 0);
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] +
                    dp[x1 - 1][y1 - 1]
             << endl;
    }
}
