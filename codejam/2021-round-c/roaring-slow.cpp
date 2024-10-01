/**
 * Author: Repon Kumar Roy
 * Date: 2021-05-01
 * Task: roaring-slow
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        auto is = [](ll n) -> bool {
            string s = to_string(n);
            for (int len = 1; len < s.size(); len++) {
                ll b     = stoll(s.substr(0, len));
                bool flag = true;
                for (int i = len; i < s.size();) {
                    string now = to_string(b + 1);
                    string t   = s.substr(i, now.size());
                    if (now != t) {
                        flag = false;
                        break;
                    }
                    i += now.size();
                    b++;
                }
                if (flag) return true;
            }
            return false;
        };

        for (ll i = n + 1;; i++) {
            if (is(i)) {
                cout << "Case #" << ++cs << ": " << i << endl;
                break;
            }
        }
    }
    return 0;
}
