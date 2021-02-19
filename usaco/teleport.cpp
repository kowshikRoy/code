#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("teleport");
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans = abs(b - a);
    ans = min(ans, abs(a - x) + abs(b - y));
    ans = min(ans, abs(a - y) + abs(b - x));
    cout << ans << endl;
}
