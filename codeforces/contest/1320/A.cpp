#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, long long> sum;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum[a - i] += a;
    }
    long long iMax = -1;
    for (auto x : sum) { iMax = max(iMax, x.second); }
    cout << iMax << endl;
    return 0;
}
