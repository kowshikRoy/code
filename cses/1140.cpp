/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1140
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], p[n];
    vector<int> e;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        e.push_back(a[i]);
        e.push_back(b[i]);
    }
    sort(e.begin(), e.end());
    e.resize(unique(e.begin(), e.end()) - e.begin());

    vector<vector<pair<int, int>>> R(e.size() + 1);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(e.begin(), e.end(), a[i]) - e.begin() + 1;
        b[i] = lower_bound(e.begin(), e.end(), b[i]) - e.begin() + 1;
        R[b[i]].push_back({a[i], p[i]});
    }

    vector<long long> dp(e.size() + 1, 0);
    for (int i = 1; i <= e.size(); i++) {
        dp[i] = dp[i - 1];
        for (auto p : R[i]) { dp[i] = max(dp[i], p.second + dp[p.first - 1]); }
    }
    cout << dp[e.size()] << endl;
}
