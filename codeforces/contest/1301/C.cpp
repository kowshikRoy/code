#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        auto nc2 = [](long long x) {
            return x * (x + 1) / 2;
        };
        long long n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << 0 << endl;
            continue;
        }
        long long d   = (n - n % m) / m;
        long long ans = nc2(n) - nc2(d) - nc2(n % m);
        cout << ans << endl;
    }
    return 0;
}
