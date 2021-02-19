#include <bits/stdc++.h>
using namespace std;

int a[100005], L[100005], R[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    L[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) L[i] = L[i - 1] + 1;
        else
            L[i] = 1;
    }

    R[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) R[i] = R[i + 1] + 1;
        else
            R[i] = 1;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) ans += max(L[i], R[i]);
    cout << ans << endl;
}
