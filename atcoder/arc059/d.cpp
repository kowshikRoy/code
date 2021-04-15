/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-04
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
        if (i + 2 < n && s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout<< -1 << " " << -1 << endl;
    return 0;
}
