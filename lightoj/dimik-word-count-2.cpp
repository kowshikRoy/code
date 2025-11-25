#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // Required for std::remove_if and std::ispunct

int main() {
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading t

    while (t--) {
        std::getline(std::cin, line);
        line.erase(std::remove_if(line.begin(), line.end(), ::ispunct), line.end());
        
        std::stringstream ss(line);
        int count = 0;
        std::string word;
        while (ss >> word) {
            count++;
        }
        std::cout << "Count = " << count << std::endl;
    }
    return 0;
}
