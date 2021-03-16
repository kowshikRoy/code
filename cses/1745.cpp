/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1745
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i], sum += x[i];

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= x[i]; j--) {
            if (dp[j - x[i]]) dp[j] = true;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sum; i++)
        if (dp[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
