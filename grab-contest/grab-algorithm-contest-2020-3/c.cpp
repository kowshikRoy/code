#include <bits/stdc++.h>
using namespace std;
int cnt[230];
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        memset(cnt, 0, sizeof cnt);
        bool haha = 1;
        for (int i = 0; i < s.size(); i++) {
            int flag = 0;
            if (s[i] == '_') continue;
            if (i - 1 > 0 && s[i - 1] == s[i]) flag = 1;
            if (i + 1 < s.size() && s[i] == s[i + 1]) flag = 1;
            if (flag == 0) { haha = 0; }
        }
        if (haha) {
            cout << "YES" << endl;
            continue;
        }
        bool flag = 0;
        for (char c : s) {
            if (c == '_') flag = 1;
            else
                cnt[c]++;
        }
        int possible = 1;
        for (int c : cnt) {
            if (c == 1) {
                possible = 0;
                break;
            }
        }
        if (!possible) {
            cout << "NO" << endl;
            continue;
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}
