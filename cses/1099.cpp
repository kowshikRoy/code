/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-02
 * Task: 1099
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if ((i & 1) == 0) g ^= x;
    }

    cout << (g ? "first" : "second") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
