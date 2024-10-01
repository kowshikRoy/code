/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    vector<int> h(n);
    function<void(int l, int r, int d)> dfs = [&](int l, int r, int d) -> void {
        if (l > r) return;
        if (l == r) {
            h[l] = d;
            return;
        }
        int pivot = l;
        for (int i = l + 1; i <= r; i++) {
            if (a[i] > a[pivot]) { pivot = i; }
        }
        dfs(l, pivot - 1, d + 1);
        dfs(pivot + 1, r, d + 1);
        h[pivot] = d;
    };
    dfs(0, n - 1, 0);
    for (int i = 0; i < n; i++) printf("%d ", h[i]);
    printf("\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
