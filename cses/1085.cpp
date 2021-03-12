/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1085
 */

#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[200005], sum = 0, iMin = 0;

bool can(long long h) {
    long long pre = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (pre + a[i] > h) {
            cnt++;
            pre = a[i];
        } else
            pre += a[i];
    }
    if (pre) cnt++;
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i], iMin = max(iMin, a[i]);

    long long low = iMin, high = sum, ans, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (can(mid)) {
            ans  = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }
    cout << ans << endl;
}
