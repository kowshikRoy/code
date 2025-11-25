#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long x, k, sum = 0, mul = 1;
        cin >> x >> k;
        for(int i = 0; i <= k; i ++) {
            sum += mul;
            mul *= x;
        }
        cout << "Result = " << sum << "\n";
    }
    return 0;
}
