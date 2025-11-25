#include <iostream>
#include <string>
#include <cmath>
#include <numeric>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int original_n = n;
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit * digit;
            n /= 10;
        }
        
        if (sum == original_n) {
            std::cout << original_n << " is an armstrong number!\n";
        } else {
            std::cout << original_n << " is not an armstrong number!\n";
        }
    }
    return 0;
}
