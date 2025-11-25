#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string line;
        cin >> line;
        for (char c : line) {
            cout << (int)(c - 'A' + 1);
        }
        cout << endl;
    }
    return 0;
}
