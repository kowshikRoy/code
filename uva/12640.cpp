/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 12640
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (getline(cin, str)) {
        istringstream iss(str);
        int ans = 0, a, sum = 0;
        while (iss >> a) {
            sum += a;
            sum = max(0, sum);
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }

    return 0;
}
