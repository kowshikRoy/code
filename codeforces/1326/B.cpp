#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int B[n + 1], A[n + 1], x[n + 1];
    x[1] = 0;
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 1; i <= n; i++) {
        A[i]     = B[i] + x[i];
        x[i + 1] = max(A[i], x[i]);
    }
    for (int i = 1; i <= n; i++) cout << A[i] << " ";

    return 0;
}
