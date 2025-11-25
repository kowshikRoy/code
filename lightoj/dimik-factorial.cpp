#include <iostream>
#include <cstdio>

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        printf("%lld\n", factorial(n));
    }
    return 0;
}
