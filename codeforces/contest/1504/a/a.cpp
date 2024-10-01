/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-03
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a') flag = true;
    }

    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != 'a') {
                s.insert(s.length() - i, 1, 'a');
                break;
            }
        }
        cout << s << endl;
    } else
        cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
