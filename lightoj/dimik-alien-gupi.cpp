#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double n;
        cin >> n;
        int days = 0;
        while (n > 1) {
            n /= 2;
            days++;
        }
        printf("%d days\n", days);
    }
    return 0;
}
