#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        string s;
        cin >> s;
        map<char, int> m, p;
        for (auto c : s) m[c]++;
        for (auto c : s) {
            if (p[c]) continue;
            cout << c << " = " << m[c] << "\n";
            p[c] = true;
        }

        if (cs < t) cout << endl;
    }
    return 0;
}
