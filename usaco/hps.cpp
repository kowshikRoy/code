#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int P[100005][4];
int main() {
    setIO("hps");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        P[i][0] = P[i - 1][0];
        P[i][1] = P[i - 1][1];
        P[i][2] = P[i - 1][2];
        if (c == 'H') P[i][0]++;
        if (c == 'P') P[i][1]++;
        if (c == 'S') P[i][2]++;
    }

    int ans = 0;
    for (int x = 0; x <= 2; x++) {
        for (int y = 0; y <= 2; y++) {
            if (x == y) continue;
            for (int i = 1; i <= n; i++) {
                int a = P[i][x] + P[n][y] - P[i][y];
                ans   = max(ans, a);
            }
        }
    }
    cout << ans << endl;
}
