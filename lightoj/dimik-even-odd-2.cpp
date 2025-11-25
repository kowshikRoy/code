#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t -- ) {
        string s;
        cin >> s;
        int n = s.back() - '0';
        if (n % 2 == 0) {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
    return 0;

}