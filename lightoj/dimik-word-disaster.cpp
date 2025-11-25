#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

int main() {
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line); // Consume the newline character after reading t

    while (t--) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> words;
        while (ss >> word) {
            std::reverse(word.begin(), word.end());
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); ++i) {
            std::cout << words[i] << (i == words.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}
