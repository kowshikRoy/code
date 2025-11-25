#include <iostream>
#include <numeric>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << "LCM = " << a * b / std::gcd(a, b)<< std::endl;
    }
    return 0;
}
