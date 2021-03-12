/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1073
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> live;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(live.begin(), live.end(), h[i] + 1) - live.begin();
        if (k == live.size()) live.push_back(h[i]);
        else
            live[k] = h[i];
    }
    cout << live.size() << endl;
}
