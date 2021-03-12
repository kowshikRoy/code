/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1629
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        vec.push_back(a[i]);
        vec.push_back(b[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    for (int i = 0; i < n; i++)
        b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin() + 1;

    int D = vec.size();
    vector<vector<int>> R(D + 1);
    vector<int> dp(D + 1);

    for (int i = 0; i < n; i++) { R[b[i]].push_back(a[i]); }
    for (int i = 1; i <= D; i++) {
        dp[i] = dp[i - 1];
        for (int a : R[i]) { dp[i] = max(dp[i], 1 + dp[a]); }
    }
    cout << dp[D] << endl;
}
