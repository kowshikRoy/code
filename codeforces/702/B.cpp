#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        for (int i = 0; i < 32; i++) {
            long long r = 1LL << i;
            ans += cnt[r - x];
        }
        cnt[x]++;
    }
    cout << ans << endl;

    return 0;
}
