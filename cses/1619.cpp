/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-11
 * Task: 1619
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, 1});
        vec.push_back({b, -1});
    }
    sort(vec.begin(), vec.end());
    for (auto a : vec) {
        sum += a.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
