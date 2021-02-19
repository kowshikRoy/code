#include <bits/stdc++.h>
using namespace std;

bitset<500> bit[500] int main() {
    int n, q, k, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            bit[i][j] = g[i][j];
        }
    }
    cin >> q;
    while (q--) {
        int k, x;
        cin >> k >> x;
        x--;
        vector<bool> vis(n, 0);
        for (int i = 0; i < min(n, k); i++) {
