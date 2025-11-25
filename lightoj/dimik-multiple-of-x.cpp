#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    for(int cs = 0; cs < t; cs ++){ 
        int n, x;
        std::cin >> x >> n;
        if(x > n) {
            std::cout << "Invalid!" << std::endl;
            continue;
        }
        for (int i = x; i <= n; i += x) {
            std::cout << i << std::endl;
        }
        cout << std::endl;
    }
    return 0;
}
