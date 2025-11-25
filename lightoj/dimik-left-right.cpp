#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                s[i] = s[i - 1];
            } else if (s[i] == 'R') {
                s[i] = s[i + 1];
            }
        }
        cout << s << endl;
    }
    return 0;
}
