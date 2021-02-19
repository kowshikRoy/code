#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        int iMax = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > iMax) cnt++;
            iMax = max(iMax, a[i]);
        }
        cout << cnt << endl;
        printf("%s\n", cnt % 2 == 0 ? "ANDY" : "BOB");
    }
}
