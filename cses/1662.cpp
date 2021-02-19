#include <bits/stdc++.h>
using namespace std;
long long pf[200005];

int main() {
    int n;
    cin >> n;
    long long sum = 0, ans = 0;
    pf[0] = 1;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        sum = ((sum + a) % n + n) % n;
        ans += pf[sum];
        pf[sum]++;
    }
    cout << ans << endl;
}
