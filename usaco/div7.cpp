#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("div7");
    int n;
    cin >> n;
    int d[7] = {0};
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum = (sum + a) % 7;
        if (d[sum]) ans = max(ans, i - d[sum]);
        else
            d[sum] = i;
    }
    cout << ans << endl;
}
