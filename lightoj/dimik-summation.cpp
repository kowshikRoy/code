#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        string s;
        cin >> s;
        printf("Sum = %d\n", (s.front() - '0') + (s.back() - '0'));
    }
    return 0;
}
