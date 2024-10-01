/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int n = a + b;
    vector<int> x(n), y(n);

    auto print = [&]() -> void {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) cout << x[i];
        cout << endl;
        for (int i = 0; i < n; i++) cout << y[i];
        cout << endl;
    };

    if (b == 1) {
        if (k == 0) {
            x[0] = 1;
            y[0] = 1;
            print();
        } else {
            cout << "No" << endl;
        }
        return;
    }

    b--;
    y[0] = 1;
    x[0] = 1;
    for (int i = n - 1, j = 0; i >= 0 && j < b; j++, i--)  y[i] = 1; 
    for (int i = n - b + 1; i < n; i++) x[i] = 1;

    bool found = false;
    for (int i = 1; i < n; i++) {
        if (n - b - i == k) {
            found = 1;
            x[i]  = 1;
            break;
        }
    }
    if (found) {
        print();
    } else
        cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
