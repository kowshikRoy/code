#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, res = 0;
        cin >> n;
        printf("%d\n", n / 5 + n / 25 + n / 125);
    }

}