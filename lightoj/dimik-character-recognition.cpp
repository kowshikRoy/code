#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        if (isdigit(c)) {
            cout << "Numerical Digit" << endl;
        } else if (isupper(c)) {
            cout << "Uppercase Character" << endl;
        } else if (islower(c)) {
            cout << "Lowercase Character" << endl;
        } else {
            cout << "Special Characters" << endl;
        }
    }
    return 0;
}
