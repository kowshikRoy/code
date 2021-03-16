/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: 1145
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<int> L;
    for (int i = 0; i < n; i++) {
        auto k = lower_bound(L.begin(), L.end(), x[i]) - L.begin();
        if (k == L.size()) L.push_back(x[i]);
        else
            L[k] = x[i];
    }

    cout << L.size() << endl;
}
