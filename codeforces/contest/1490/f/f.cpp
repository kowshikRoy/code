/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: f
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    map<int, int> f;
    for (auto x : cnt) f[x.second]++;

    vector<array<int, 2>> vec;
    for (auto x : f) { vec.push_back({x.first, x.second}); }

    // f - fre, s -> how many integers
    vector<int> suf(vec.size());
    for (int i = (int)vec.size() - 1; i >= 0; i--) {
        suf[i] = (i + 1 < vec.size() ? suf[i + 1] : 0) + vec[i][1];
    }

    int pre = 0;
    int ans = 10000000;
    for (int i = 0; i < vec.size(); i++) {
        int me = vec[i][0] * vec[i][1];
        int r  = 0;
        if (i + 1 < vec.size()) r = suf[i + 1];
        int cur = pre + n - pre - me - r * vec[i][0];
        ans     = min(ans, cur);
        pre += me;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
