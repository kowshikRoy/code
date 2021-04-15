/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-15
 * Task: 13185
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i * i != n) sum += n / i;
            }
        }
        sum -= n;
        cout << (sum == n ? "perfect" : (sum > n ? "abundant" : "deficient"))
             << endl;
    }

    return 0;
}
