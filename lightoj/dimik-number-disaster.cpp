#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        std::string s;
        std::cin >> s;
        if (s.length() > 1 && s.back() == '0') s.pop_back();
        std::reverse(s.begin(), s.end());
        std::cout << s << std::endl;
    }
    return 0;
}
