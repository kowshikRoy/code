#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        string a, b;
        bool eq = 1;
        for (int i = 0; i < n; i++) {
            if (x[i] == '0') a.push_back('0'), b.push_back('0');
            if (x[i] == '1') {
                if (eq) a.push_back('1'), b.push_back('0');
                else
                    a.push_back('0'), b.push_back('1');
                eq = 0;
            }
            if (x[i] == '2') {
                if (eq) a.push_back('1'), b.push_back('1');
                else
                    a.push_back('0'), b.push_back('2'), eq = 0;
            }
        }
        cout << a << endl;
        cout << b << endl;
    }

    return 0;
}
