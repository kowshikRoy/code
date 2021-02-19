#include <bits/stdc++.h>
using namespace std;

string s;

bool ispal(int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++, j--;
    }
    return 1;
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        int i = 0, j = s.size() - 1;
        if (ispal(i, j)) {
            cout << -1 << endl;
            continue;
        }
        while (i < j) {
            if (s[i] == s[j - 1]) i++, j--;
            else
                break;
        }
        if (ispal(i + 1, j)) cout << i << endl;
        else if (ispal(i, j - 1))
            cout << j << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
