#include <iostream>
#include <vector>
using namespace std;

#define EPS 1e-9
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

#define dbg(...)                                                       \
    cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", \
        dbg_out(__VA_ARGS__)

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) { return power(n, 998244353 - 2); }

int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        int w, g, l;
        cin >> w >> g >> l;

        vector<long long> e(2 * l + 1, 0);  // Sufficient size
        e[l] = 0;  // Base case: Expected time from G to G is 0. We shift
                   // indices by l to avoid negative indices.

        for (int i = l + 1; i <= l + w - g; ++i) {  // Iterate upwards from G
            e[i] = (2 * e[i - 1] + 2) % 998244353;
            if (i > l && w + l - i < g) { e[i] = (e[i - 1] + 1) % 998244353; }
        }

        cout << e[w - g + l] << endl;
    }

    return 0;
}