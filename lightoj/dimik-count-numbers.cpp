#include <iostream>
#include <string>
#include <sstream>

int main() {
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading t

    while (t--) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int count = 0;
        int num;
        while (ss >> num) {
            count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}
