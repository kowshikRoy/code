/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-05
 * Task: acc7p1
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
        ll n;
        cin >> n;
        if(n == 2) cout << 2 << endl;
        else cout << n - 1 << endl;
    }
    return 0;
}
