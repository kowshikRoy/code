#include <iostream>
#include <string>
#include <cctype> // For tolower

int main() {
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading t

    while (t--) {
        std::getline(std::cin, line);
        int vowel_count = 0;
        for (char c : line) {
            char lower_c = std::tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                vowel_count++;
            }
        }
        std::cout << "Number of vowels = " << vowel_count << std::endl;
    }
    return 0;
}
