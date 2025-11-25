#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

int main() {
    int t;
    std::cin >> t;
   
    while (t--) {
        int n; 
        std::cin >> n;
        std::vector<std::string> words(n);
        for (int i = 0; i < n; i++) {
            std::cin >> words[i];
        }
        std::sort(words.begin(), words.end());
        for(int i = 0; i < n; i ++) std::cout << words[i] << std::endl;
    }
    return 0;
}
