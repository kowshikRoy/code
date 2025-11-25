#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1e5;

int main() {
    vector<int> v(N + 1, 0), prime(N + 1, 0);
    for(int i = 2; i <= N; i ++) {
        for(int j = i * 2; j <= N; j += i) {
            v[j] = 1;
        }
    }
    for(int i = 2; i <= N; i ++) {
        prime[i] = prime[i-1];
        if(v[i] == 0) {
            prime[i] ++;
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        printf("%d\n", prime[b] - prime[a - 1]);
    }
    return 0;
}
