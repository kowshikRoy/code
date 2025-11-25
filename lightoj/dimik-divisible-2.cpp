#include <iostream>
#include <cstdio>
#include <numeric>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long m = a / gcd(a,b) * b;
        for (long long i = m; i <= c; i += m) {
            printf("%lld\n", i);
        }
        printf("\n");
    }
    return 0;
}
