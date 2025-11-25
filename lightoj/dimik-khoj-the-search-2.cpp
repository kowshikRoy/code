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
        int cnt = 0;
        while(found != std::string::npos) {
            cnt ++;
            found = text.find(pattern, found + 1);
        }
        std::cout << cnt << "\n";
    }
    return 0;
}
