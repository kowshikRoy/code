/*
ID: newcode2
PROG: friday
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

int daysIn(int month, int year) {
    switch (month) {
        case 9:
        case 4:
        case 6:
        case 11: return 30;
        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 29;
            else
                return 28;
        default: return 31;
    }
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n;
    cin >> n;

    int days[7] = {0};
    int day = 2;

    for (int y = 1900; y < 1900 + n; y++) {
        for (int m = 1; m <= 12; m++) {
            days[(day + 12) % 7]++;
            day += daysIn(m, y);
        }
    }

    for (int i = 0; i < 7; i++) { printf("%s%d", i ? " " : "", days[i]); }

    cout << endl;
}
