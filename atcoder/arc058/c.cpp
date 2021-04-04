/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-04
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    int bad[10] = {0};
    REP(i, k) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    for (int i = n;; i++) {
        string s   = to_string(i);
        bool isBad = false;
        for (int j = 0; j < s.length(); j++) {
            if (bad[s[j] - '0']) isBad = true;
        }
        if (isBad == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
