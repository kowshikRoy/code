/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: a
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);

    int step = 6e6 + 1;
    while (step--) {
        int a = rand() % n;
        int b = rand() % n;
        int c = rand() % n;
        int d = rand() % n;
        if(a == b || a == c || a == d || b == c || b == d || c == d) continue;
        if (x[a] + x[b] == x[c] + x[d]) {
            puts("YES");
            printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
            return 0;
        }
    }
    puts("NO");
}
