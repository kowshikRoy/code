#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int dp[N];
vector<int> d[N];

int solve(int n) {
    if (dp[n] != -1) return dp[n];
    if (n == 0 || n == 1) return n;
    int ret = N + 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) ret = min(ret, 1 + solve(n / i));
    }
    ret = min(ret, 1 + solve(n - 1));
    return dp[n] = ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
