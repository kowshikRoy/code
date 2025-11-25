#include <iostream>
#include <numeric>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n, sum = 0;
        std::cin >> n;
        for (int i = 0; i < n - 1; i++) {
            long long a;
            std::cin >> a;
            sum += a;
        }
        std::cout << (n * (n + 1)) / 2 - sum << std::endl;
    }
    return 0;
}
