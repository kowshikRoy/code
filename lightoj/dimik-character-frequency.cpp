#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading t

    while (t--) {
        std::getline(std::cin, line);
        char ch;
        std::cin >> ch;
        int count = 0;
        for (char c : line) {
            if (c == ch) count++;
        }
        std::cout << "Occurrence of '" << ch << "' in '" << line << "' = " << count << std::endl;

    }
    return 0;
}
