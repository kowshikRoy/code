/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-26
 * Task: two-friends
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, cs = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        printf("Case %d: ", ++cs);
        if (n <= 2) puts("Tie");
        else if (n & 1)
            puts("CodeNewtons");
        else
            puts("CodeMask");
    }
    return 0;
}
