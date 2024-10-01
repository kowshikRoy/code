/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-11
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


const int M = 1e9+7;
struct mint {
    int value;
    mint() : value(0) {}
    template <class T> mint(T x) : value(x % M) { if (value < 0) value += M; }
    mint & operator-=(mint oth) { value -= oth.value; if (value < 0)  value += M; return *this; }
    mint & operator+=(mint oth) { value += oth.value; if (value >= M) value -= M; return *this; }
    mint & operator*=(mint oth) { value = (long long) value * oth.value % M; return *this; }
    mint & operator--() { if (--value == -1) value = M - 1; return *this; }
    mint & operator++() { if (++value == M) value = 0; return *this; }
    mint operator--(int) { mint temp = *this; --*this; return temp; }
    mint operator++(int) { mint temp = *this; ++*this; return temp; }
    mint operator-() const { return mint() - *this; }
    mint operator+() const { return *this; }
    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }
    friend mint operator-(mint a, mint b) { return a -= b; }
    friend mint operator+(mint a, mint b) { return a += b; }
    friend mint operator*(mint a, mint b) { return a *= b; }
    friend bool operator==(mint a, mint b) { return a.value == b.value; }
    friend bool operator!=(mint a, mint b) { return a.value != b.value; }
    friend ostream & operator<<(ostream &out, mint a) { out << a.value; return out; }
};
const int N = 2e5+5;
mint dp[10][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 10; i++) dp[i][0] = 1;
    for (int m = 1; m < N; m++) {
        for (int i = 0; i < 10; i++) {
            if (i < 9) dp[i][m] = dp[i + 1][m - 1];
            else
                dp[i][m] = dp[0][m - 1] + dp[1][m - 1];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        mint ans = 0;
        while (n) ans += dp[n % 10][m], n /= 10;
        cout << ans << endl;
    }
    return 0;
}
