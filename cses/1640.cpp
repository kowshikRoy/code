/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1640
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        vec.push_back({y, i + 1});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0, j = n - 1; i < j;) {
        int sum = vec[i].first + vec[j].first;
        if (sum == x) {
            cout << vec[i].second << " " << vec[j].second << endl;
            return 0;
        } else if (sum < x)
            i++;
        else
            j--;
    }
    cout << "IMPOSSIBLE" << endl;
}
