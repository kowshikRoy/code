#include <bits/stdc++.h>
using namespace std;

inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }
int dp[100005][26];
long long f[100005], g[100005];
long long mod = 1e9 + 7;
const int N   = 1e5 + 5;

int main() {
    string s;
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 26; j++) dp[i][j] = dp[i - 1][j];
        dp[i][s[i - 1] - 'a']++;
    }
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (i * f[i - 1]) % mod;
        g[i] = modinverse(f[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = 0;
        vector<long long> vec;
        int base = 0;
        for (int i = 0; i < 26; i++) {
            int t = dp[b][i] - dp[a - 1][i];
            base += t / 2;
            vec.push_back(t / 2);
            if (t % 2) ans++;
        }
        long long out = f[base];
        for (auto a : vec) { out = (out * g[a]) % mod; }
        if (ans) out = (out * ans) % mod;
        cout << out << endl;
    }
}
