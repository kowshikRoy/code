/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-05
 * Task: acc7p2
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n;

    vector<int> v(n);
    vector<int> a(n);
    REP(i, n) v[i] = i + 1;

    while (1) {
        random_shuffle(v.begin(), v.end());
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
        cout << flush;
        cin >> k;

        if (k == 0) break;
    }
    return 0;
}
