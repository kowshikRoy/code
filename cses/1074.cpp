/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1074
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);
    int pivot     = h[n / 2];
    long long sum = 0;
    for (int i = 0; i < n; i++) { sum += abs(pivot - h[i]); }
    cout << sum << endl;
}
