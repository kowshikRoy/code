#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
    os << '{';
    string sep;
    for (const T& x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-03
 * Task: e
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int M = 998244353;
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

int n, k;
const int N = 501;
bool vis[N][N][2], vis2[N][N];
mint dp[N][N][2];
mint dp2[N][N];

int T;

mint solve(int i, int r, int f) {
    dbg(i, r, f);
    if (i == n) return f;
    if (vis[i][r][f]) return dp[i][r][f];

    vis[i][r][f] = true;
    if (r == T) return dp[i][r][f] = solve(i + 1, 1, f);
    else {
        mint ret = 0;
        ret += solve(i + 1, r + 1, f || ((r + 1) == T));  // continue
        ret += solve(i + 1, 1, f || (T == 1));
        return dp[i][r][f] = ret;
    }
}

mint dfs(int idx, int len) {
    if (len * T >= k) return 0;
    if (idx == n) return 1;

    if (vis2[idx][len]) return dp2[idx][len];
    vis2[idx][len] = true;

    mint ret = dfs(idx + 1, len + 1);
    ret += dfs(idx + 1, 1);
    return dp2[idx][len] = ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    mint ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        memset(vis2, 0, sizeof vis2);
        T      = i;
        mint w = solve(0, 0, false);
        dbg(w);
        ans += w * dfs(1, 1);
    }
    cout << ans << endl;

    return 0;
}
