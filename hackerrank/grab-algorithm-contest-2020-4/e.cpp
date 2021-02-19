#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

char str[N];
int a[N];
long long dp[1 << 10];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; str[j]; j++) {
            char c = str[j];
            a[i] |= (1 << (c - '0'));
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int need = ((1 << 10) - 1) ^ a[i];
        ans += dp[need];
        for (int j = a[i];; j = a[i] & (j - 1)) {
            dp[j]++;
            if (j == 0) break;
        }
    }
    cout << ans << endl;
}
