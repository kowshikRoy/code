#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if(n == 0) {
            printf("1\n");
            continue;
        }
        for(int i = n; i >= 2; i --) {
            printf("2^%d + ", i);
        }
        printf("2 + 1\n");
    }
    return 0;
}
