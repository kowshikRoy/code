#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int n   = 1005;
const int m   = 1000006;
const int inf = 1 << 20;

vector<vector<int>> col;
int main() {
#ifndef local
    setIO("art");
#endif
    int n;
    cin >> n;
    col.resize(n + 1, vector<int>(n + 1));

    vector<int> top(m, 0);
    vector<int> bottom(m, inf);
    vector<int> left(m, inf);
    vector<int> right(m, 0);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> pf(n, vector<int>(n, 0));

    int tot = 0;
    set<int> co;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> col[i][j];
            if (col[i][j]) {
                int c     = col[i][j];
                left[c]   = min(left[c], i);
                right[c]  = max(right[c], i);
                bottom[c] = min(bottom[c], j);
                top[c]    = max(top[c], j);
                co.insert(col[i][j]);
            }
        }
    }
    if (co.size() == 1) {
        cout << n * n - 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n * n; i++) {
        if (top[i]) {
            dp[left[i]][bottom[i]]++;
            dp[right[i] + 1][bottom[i]]--;
            dp[left[i]][top[i] + 1]--;
            dp[right[i] + 1][top[i] + 1]++;
        }
    }

    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pf[i][j] =
                dp[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
            if (pf[i][j] > 1) { s.insert(col[i][j]); }
        }
    }
    cout << n * n - s.size() << endl;
}
