#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10005];
int main() {
    while (cin >> n >> k) {
        if (!n && !k) break;
        int pos = 0, neg = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > 0) pos++;
            else if (a[i] < 0)
                neg++;
            else
                zero++;
        }
        sort(a, a + n);
        bool isPositivePossible = false;
        int ans                 = 0;
        for (int i = 0; i <= k; i += 2) {
            if (i > 0 && a[i - 1] >= 0) break;
            if (pos >= k - i) isPositivePossible = true;
        }
        if (!isPositivePossible && zero) {
            ans = 0;
            for (int i = 0; i < k; i++) ans += a[n - 1 - i];
            cout << ans << endl;
            continue;
        }
        if (isPositivePossible) {
            int L = 0, R = n - 1;
            if (k & 1) ans = a[R--], k--;
            while (k) {
                assert(R > 0);
                if (a[L] * a[L + 1] > a[R] * a[R - 1]) {
                    ans += a[L] + a[L + 1];
                    L += 2;
                } else
                    ans += a[R] + a[R - 1], R -= 2;
                k -= 2;
            }
            cout << ans << endl;
            continue;
        }

        int L = -1, R = n;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) L = i;
            else if (a[i] > 0)
                R = min(R, i);
        }

        while (k) {
            if (L < 0) ans += a[R++];
            else if (R >= n)
                ans += a[L--];
            else {
                if (a[R] <= abs(a[L])) ans += a[R++];
                else
                    ans += a[L--];
            }
            k--;
        }
        cout << ans << endl;
    }
}
