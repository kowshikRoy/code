/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: aac1p1
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double s, r;
    cin >> s >> r;
    cout << (s * s > 3.14 * r * r ? "SQUARE" : "CIRCLE") << endl;
    return 0;
}
