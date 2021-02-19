#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, b;
    cin >> t >> b;
    while (t--) {
        char c;
        string out;
        for (int i = 1; i <= 10; i++) {
            cout << i << endl;
            cin >> c;
            out.push_back(c);
        }
        cout << out << endl;
        cin >> c;
        if (c == 'N') assert(0);
    }
}
