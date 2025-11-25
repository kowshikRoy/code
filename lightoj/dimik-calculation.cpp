#include <iostream>
#include <cstdio>

long long PowMod(long long a, long long b, long long m) {
    if (b == 0) {
        return 1 % m;
    }
    long long half = PowMod(a, b / 2, m);
    long long result = (half * half) % m;
    if (b % 2 == 1) {
        result = (result * a) % m;
    }
    return result;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int p, q, c;
        std::cin >> p >> q >> c;
        printf("Result = %d\n", PowMod(p, q, c));
    }
    return 0;
}
