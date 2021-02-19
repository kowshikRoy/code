#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) { return a * b / __gcd(a, b); }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
        } else {
            long long iL = n - 1;
            int A = 1, B = n - 1;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int x = i;
                    int y = n - x;
                    long long l = lcm(x, y);
                    if (l < iL) {
                        A = x;
                        B = y;
                        iL = l;
                    }
                    x = n / i;
                    y = n - x;
                    l = lcm(x, y);
                    if (l < iL) {
                        A = x;
                        B = y;
                        iL = l;
                    }
                }
            }
            cout << A << " " << B << endl;
        }
    }
    return 0;
}
