/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int maxe = max(a[i], a[i - 1]), mine = min(a[i], a[i - 1]);
        if (maxe <= 2 * mine) continue;
        else {
            while (maxe > 2 * mine) cnt++, mine = 2 * mine;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
