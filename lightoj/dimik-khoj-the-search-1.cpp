#include <iostream>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string text, pattern;
        std::cin >> text >> pattern;
        size_t found = text.find(pattern);
        std::cout << found << "\n";
    }
    return 0;
}
