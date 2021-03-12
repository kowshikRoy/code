/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1091
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto ptr = ms.lower_bound(x + 1);
        if (ptr == ms.begin()) {
            cout << -1 << endl;
            continue;
        }
        ptr--;
        bool found = false;
        while (true) {
            if (*ptr <= x) {
                found = true;
                break;
            }
            if (ptr == ms.begin()) break;
            ptr--;
        }
        if (found) {
            cout << *ptr << endl;
            ms.erase(ptr);
        } else
            cout << -1 << endl;
    }
}
