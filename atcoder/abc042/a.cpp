#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == 5 && a[1] == 5 && a[2] == 7) cout << "YES\n";
    else
        cout << "NO\n";
}
