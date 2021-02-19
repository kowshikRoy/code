#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int broken[100005], pre[100005];
int main() {
    setIO("maxcross");
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        broken[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (broken[i]) pre[i]++;
    }
    int ans = n + 1;

    for (int i = 1; i + k - 1 <= n; i++) {
        int t = pre[i + k - 1] - pre[i - 1];
        ans = min(ans, t);
    }
    cout << ans << endl;
}
