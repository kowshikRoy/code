/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-31
 * Task: 1081
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 1e6 + 6;

void solve() {
    int n;
    cin >> n;
    vector<int> ache(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ache[x]++;
    }

    int ans = 1;
    for (int i = 1; i < N; i++) {
        int cnt = 0;
        for (int j = i; j < N; j += i) cnt += ache[j];
        if (cnt > 1) ans = i;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
