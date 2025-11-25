#include <iostream>
#include <cmath>

bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        if (is_prime(n)) {
            printf("%lld is a prime\n", n);
        } else {
            printf("%lld is not a prime\n", n);
        }
    }
    return 0;
}
