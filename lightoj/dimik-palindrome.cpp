#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        if (s == reversed_s) {
            std::cout << "Yes! It is palindrome!\n";
        } else {
            std::cout << "Sorry! It is not palindrome!\n";
        }
    }
    return 0;
}
