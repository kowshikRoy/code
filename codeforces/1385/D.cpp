#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
string s;
int a[N], cnt[N][26];
int CS = 0;
int T[5 * N][26], vis[5 * N][26];
int findC(int b, int e, int x) {
    int p = cnt[e][x] - (b > 0 ? cnt[b - 1][x] : 0);
    return e - b + 1 - p;
}
int solve(int n, int b, int e, int x) {
    if (vis[n][x] == CS) return T[n][x];
    if (b == e) {
        if (a[b] == x) return T[n][x] = 0;
        else
            return T[n][x] = 1;
    }
    vis[n][x] = CS;
    int mid = (b + e) / 2;
    int ret = min(findC(b, mid, x) + solve(2 * n + 1, mid + 1, e, x + 1),
                  solve(2 * n, b, mid, x + 1) + findC(mid + 1, e, x));
    //	cout << n << " " << b << " " << e << " " << x << endl;
    return T[n][x] = ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) cnt[i][j] = 0;
        }
        for (int i = 0; i < n; i++) cnt[i][a[i]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++)
                cnt[i][j] += (i > 0 ? cnt[i - 1][j] : 0);
        }
        ++CS;

        cout << solve(1, 0, n - 1, 0) << endl;
    }
    return 0;
}
