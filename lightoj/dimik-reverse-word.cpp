#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
