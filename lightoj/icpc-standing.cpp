#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int cs;
    cin >> cs;
    for (int i = 0; i < cs; i++) {
        int p, s, r;
        if (p != s) printf("Case %d: Yes\n", i + 1);
        else
            printf("Case %d: %s\n", i + 1, r == 1 ? "Yes" : "No");
    }
}
