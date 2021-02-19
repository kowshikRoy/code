#include <bits/stdc++.h>
using namespace std;

inline bool leap(int n) {
    if (n % 400 == 0) return 1;
    if (n % 100 == 0) return 0;
    if (n % 4 == 0) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int y;
    cin >> y;
    int ini = y;
    int rm = 0;
    for (;;) {
        rm = (rm + 365 + leap(y)) % 7;
        y++;
        if (rm == 0 && leap(ini) == leap(y)) {
            cout << y << endl;
            return 0;
        }
    }
    return 0;
}
