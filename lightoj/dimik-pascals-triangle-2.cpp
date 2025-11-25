#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i <= n; ++i) {
            long long val = 1;
            for (int j = 0; j <= i; ++j) {
                std::cout << val << (j == i ? "" : " ");
                val = val * (i - j) / (j + 1);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
