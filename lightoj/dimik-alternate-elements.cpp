#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        for(int i = 0; i < n; i += 2) {
            if(i) std::cout << " ";
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
