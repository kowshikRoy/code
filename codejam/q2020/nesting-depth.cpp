#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        string s;
        string ans;
        cin >> s;
        int bal = 0;
        for (char c : s) {
            int d = c - '0';
            while (bal < d) ans.push_back('('), bal++;
            while (bal > d) ans.push_back(')'), bal--;
            ans.push_back(c);
        }
        while (bal > 0) ans.push_back(')'), bal--;
        printf("Case #%d: %s\n", ++cs, ans.c_str());
    }
}
