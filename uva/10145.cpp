/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-02
 * Task: 10145
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        map<int, set<int>> M;
        map<int, int> Exlock;
        set<int> blocked;
        while (1) {
            char mode;
            int trid, item;
            cin >> mode;
            if (mode == '#') break;
            cin >> trid >> item;
            if (blocked.count(trid)) {
                cout << "IGNORED" << endl;
                continue;
            }
            if (Exlock.find(item) != Exlock.end()) {
                if (Exlock[item] == trid) {
                    cout << "GRANTED" << endl;
                } else {
                    cout << "DENIED" << endl;
                    blocked.insert(trid);
                }
                continue;
            }
            if (mode == 'X') {
                bool flag = true;
                for (auto x : M[item]) {
                    if (x != trid) { flag = false; }
                }
                if (flag) {
                    cout << "GRANTED" << endl;
                    M[item].insert(trid);
                    Exlock[item] = trid;
                } else {
                    cout << "DENIED" << endl;
                    blocked.insert(trid);
                }
            } else {
                cout << "GRANTED" << endl;
                M[item].insert(trid);
            }
        }
        if (t) cout << endl;
    }
}
