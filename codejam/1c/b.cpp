#include <bits/stdc++.h>
using namespace std;

int q[10004];
string s[10005], t[10005];
int main() {
    int tt, cs = 0;
    cin >> tt;
    while (tt--) {
        int u;
        cin >> u;
        bool flag = 0;
        set<char> st;
        for (int i = 0; i < 10000; i++) {
            cin >> q[i] >> s[i];
            t[i] = to_string(q[i]);
            if (q[i] != -1) { flag = 1; }
            for (char c : s[i]) st.insert(c);
        }

        printf("Case #%d: ", ++cs);
        vector<char> vec;
        for (auto c : st) vec.push_back(c);
        st.clear();
        for (int i = 0; i < 10000; i++) { st.insert(s[i][0]); }
        int zero = -1, cnt = 0;
        for (auto c : vec) {
            if (st.count(c) == 0) {
                zero = c;
                cnt++;
            }
        }
        if (cnt != 1) zero = -1;
        map<char, int> fix, rfix;
        if (zero != -1) fix[zero] = 0, rfix[0] = zero;
        if (flag) {
            for (int loop = 0; loop < 100; loop++) {
                map<char, int> V;
                for (auto c : vec) {
                    if (fix.count(c) == 0) { V[c] = 9; }
                }

                for (int i = 0; i < 10000; i++) {
                    if (t[i].length() == s[i].length()) {
                        for (int j = 0; j < t[i].length(); j++) {
                            if (s[i][j] >= '0' && s[i][j] <= '9') {
                                if (t[i][j] > s[i][j]) break;
                            } else if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                                V[s[i][j]] = min(V[s[i][j]], t[i][j] - '0');
                                break;
                            }
                        }
                    }
                }

                for (int i = 0; i < 10; i++) {
                    if (rfix.count(i) == 0) {
                        int iM = 100, pivot = -1;
                        for (auto x : V) {
                            if (x.second < iM) {
                                iM    = x.second;
                                pivot = x.first;
                            }
                        }
                        if (iM == i) {
                            fix[pivot] = i;
                            rfix[i]    = pivot;
                        }
                        V.erase(pivot);
                    }
                }

                for (int i = 0; i < 10000; i++) {
                    for (int j = 0; j < s[i].length(); j++) {
                        if (fix.count(s[i][j])) s[i][j] = fix[s[i][j]];
                    }
                }
                if (fix.size() == 10) break;
            }
            for (int i = 0; i < 10; i++) {
                if (rfix.count(i) == 0) {
                    for (auto c : vec) {
                        if (fix.count(c) == 0) {
                            rfix[i] = c;
                            fix[c]  = i;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 10; i++) printf("%c", rfix[i]);
            cout << endl;
        } else {
            if (zero >= 0) { cout << zero; }
            for (auto c : vec)
                if (c != zero) cout << c;
            cout << endl;
        }
    }
}
