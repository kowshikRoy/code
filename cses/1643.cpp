#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {
    int n;
    cin >> n;
    long long ans = LLONG_MIN, sum = 0;
    long long m = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum += a;
        if (sum - m > ans) { ans = sum - m; }
        m = min(sum, m);
    }
    cout << ans << endl;
}
