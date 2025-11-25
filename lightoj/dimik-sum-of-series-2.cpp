#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        double sum = 0, mul = 1;
        for(int i = 1; i <= n; i ++) {
            mul *= i;
            sum += i / mul;
        }
        cout << fixed << setprecision(4) << sum << "\n";
    }
    return 0;
}
