#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int pivot = n - 1;
        while (pivot > 0 && a[pivot - 1] >= a[pivot]) pivot--;
        while (pivot > 0 && a[pivot - 1] <= a[pivot]) pivot--;
        cout << pivot << endl;
    }

    return 0;
}
