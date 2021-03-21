#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[2 * n];
    for (int i = 0; i < 2 * n; i++) { cin >> a[i]; }
    sort(a, a + 2 * n);
    int sum1 = accumulate(a, a + n, 0);
    int sum2 = accumulate(a + n, a + 2 * n, 0);
    if (sum1 == sum2) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < 2 * n; i++) cout << a[i] << " ";
    }

    return 0;
}
