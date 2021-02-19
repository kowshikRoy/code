#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int p[N], a[N];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] ^ a[i];

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (p[b] ^ p[a - 1]) << endl;
    }
}
