#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "*";
            }
            cout << "\n";
        }
        if (cs != t) {
            cout << "\n";
        }
    }
    return 0;
}
