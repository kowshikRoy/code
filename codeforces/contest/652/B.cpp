#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int ptr = 1;
    for (int i = 1; i <= n; i += 2) { b[i] = a[ptr++]; }
    for (int i = 2; i <= n; i += 2) b[i] = a[ptr++];
    for (int i = 1; i <= n; i++) cout << b[i] << " ";

    return 0;
}
