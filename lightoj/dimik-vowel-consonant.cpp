#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); // Consume the newline character

    while (t--) {
        std::string line;
        std::getline(std::cin, line);
        std::string vowels, consonants;
        for (char c : line) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels += c;
            } else if (std::isalpha(c)) {
                consonants += c;
            }
        }
        if (!vowels.empty()) std::cout << vowels << std::endl;
        if(!consonants.empty()) std::cout << consonants << std::endl;
    }
    return 0;
}
