#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, c;
    cin >> n >> c;
    long y = n / c;
    while (y * c <= n) y++;
    cout << (y * c) << endl;

    return 0;
}
