/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1076
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];

    set<pair<int, int>> topHigh;
    set<pair<int, int>> topLow;
    topHigh.insert({INT_MIN, -1});
    topLow.insert({INT_MAX, n});
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i]    = x;
        auto p1 = topHigh.rbegin()->first;
        auto p2 = topLow.begin()->first;
        if (x < p1) topHigh.insert({x, i});
        else
            topLow.insert({x, i});

        while (topHigh.size() > 1 + topLow.size()) {
            auto x = *topHigh.rbegin();
            topHigh.erase(x);
            topLow.insert(x);
        }

        while (topLow.size() > topHigh.size()) {
            auto x = *topLow.begin();
            topLow.erase(x);
            topHigh.insert(x);
        }
        if (i >= k - 1) {
            cout << topHigh.rbegin()->first << " ";
            auto p = topLow.find({a[i - (k - 1)], i - (k - 1)});
            if (p != topLow.end()) topLow.erase(p);

            p = topHigh.find({a[i - (k - 1)], i - (k - 1)});
            if (p != topHigh.end()) topHigh.erase(p);
        }
    }
}
