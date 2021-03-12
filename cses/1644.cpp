/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1644
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> A(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + A[i];

    multiset<long long> ms;
    long long ans = LLONG_MIN;
    int ptr       = 0;
    for (int i = a; i <= n; i++) {
        ms.insert(p[i - a]);
        ans = max(ans, p[i] - *ms.begin());
        if (i >= b) ms.erase(ms.find(p[i - b]));
    }
    cout << ans << endl;
}
