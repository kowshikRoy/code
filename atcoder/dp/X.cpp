/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: X
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1004, M = 2e4 + 4;

struct block {
    int w, s, v;
    bool operator<(const block &b) const { return w + s < b.w + b.s; }
} blocks[N];
long long dp[M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> blocks[i].w >> blocks[i].s >> blocks[i].v;
    sort(blocks, blocks + n);
    // dp[i][w] => max value with total weight w, and taking [0..i]

    for (int i = 0; i < n; i++) {
        for (int j = min(blocks[i].s, M); j >= 0; j--) {
            dp[j + blocks[i].w] = max(dp[j + blocks[i].w], dp[j] + blocks[i].v);
        }
    }

    long long ans = 0;
    for (int i = 0; i < M; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}
