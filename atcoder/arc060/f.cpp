#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
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
 * Date: 2021-04-06
 * Task: f
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int M = 998244353;
struct mint {
    int value;
    mint() : value(0) {}
    template <class T> mint(T x) : value(x % M) {
        if (value < 0) value += M;
    }
    mint &operator-=(mint oth) {
        value -= oth.value;
        if (value < 0) value += M;
        return *this;
    }
    mint &operator+=(mint oth) {
        value += oth.value;
        if (value >= M) value -= M;
        return *this;
    }
    mint &operator*=(mint oth) {
        value = (long long)value * oth.value % M;
        return *this;
    }
    mint &operator--() {
        if (--value == -1) value = M - 1;
        return *this;
    }
    mint &operator++() {
        if (++value == M) value = 0;
        return *this;
    }
    mint operator--(int) {
        mint temp = *this;
        --*this;
        return temp;
    }
    mint operator++(int) {
        mint temp = *this;
        ++*this;
        return temp;
    }
    mint operator-() const { return mint() - *this; }
    mint operator+() const { return *this; }
    mint pow(long long e = M - 2) const {
        mint res = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) { res *= b; }
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
    friend ostream &operator<<(ostream &out, mint a) {
        out << a.value;
        return out;
    }
};

const int Base = 29;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    set<int> se;
    for (auto c : s) se.insert(c);
    if (se.size() == 1) {
        cout << s.size() << "\n" << 1 << endl;
        return 0;
    }

    int n = (int)s.size();
    vector<mint> p(n + 1), H(n + 1);
    p[0] = 1;
    REP(i, n) p[i + 1] = p[i] * Base;
    REP(i, n) H[i] = (i ? H[i - 1] : 0) * Base + s[i] - 'a' + 1;

    auto get = [&](int x, int y) {
        assert(x <= y);
        return H[y] - (x > 0 ? H[x - 1] : 0) * p[y - x + 1];
    };

    vector<bool> A(n, 1), B(n, 1);
    for (int k = 1; k <= n / 2; k++) {
        auto t = get(0, k - 1);
        for (int j = k; j + k - 1 < n; j += k) {
            auto v = get(j, j + k - 1);
            if (v != t) break;
            A[j + k - 1] = false;
        }
        t = get(n - k, n - 1);
        for (int j = n - k - 1; j - k + 1 >= 0; j -= k) {
            auto v = get(j - k + 1, j);
            if (v != t) break;
            B[j - k + 1] = false;
        }
    }

    if (A[n - 1]) {
        cout << 1 << "\n" << 1 << endl;
        return 0;
    }
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] && B[i + 1]) ans++;
    }
    cout << 2 << "\n" << ans << endl;
    return 0;
}
