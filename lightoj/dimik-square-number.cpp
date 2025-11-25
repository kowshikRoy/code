#include <iostream>
#include <cmath>
#include <cstdio>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long root = sqrt(n);
        if (root * root == n) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
