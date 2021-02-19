#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int mod = 998244353;
long long rm[N];

long long calc(int n) {
    if (n <= 0) return 1;
    return 9 * rm[n - 1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    rm[0] = 1;
    for (int i = 1; i < N; i++) rm[i] = (rm[i - 1] * 10) % mod;

    for (int len = 1; len < n; len++) {
        long long sum = 0;
        for (int dig = 0; dig < 10; dig++) {
            int tip = n - len;
            sum += (calc(0) * calc(tip) * 2) % mod;
            if (tip >= 2) sum += ((tip - 1) * 9 * 9 * rm[tip - 2]) % mod;
        }
        // cout << psum << endl;
        cout << sum % mod << endl;
    }
    cout << 10 << endl;

    return 0;
}
