#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1004;

int dp[N][N], a[N][N];

int main() {
    setIO("paintbarn");
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++;
        a[x1][y1]++;
        a[x2 + 1][y1]--;
        a[x1][y2 + 1]--;
        a[x2 + 1][y2 + 1]++;
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
            if (dp[i][j] == k) ans++;
        }
    }
    cout << ans << endl;
}
