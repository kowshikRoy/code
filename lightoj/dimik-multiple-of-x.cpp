#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        int x, n;
        scanf("%d %d", &x, &n);
        if (x > n) {
            printf("Invalid!\n\n");
            continue;
        }
        for (int i = x; i <= n; i += x) {
            printf("%d\n", i);
        }
        printf("\n");
    }

    return 0;
}
