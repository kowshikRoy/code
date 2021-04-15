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
 * Date: LG21-04-05
 * Task: e
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, LL;
    cin >> n;

    vector<int> x(n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    cin >> LL;
    cin >> q;

    L[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = L[i - 1];
        while (j < i && x[i] - x[j] > LL) j++;
        L[i] = j;
    }

    R[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        int j = R[i + 1];
        while (j > i && x[j] - x[i] > LL) j--;
        R[i] = j;
    }

    dbg(L);
    dbg(R);
    const int LG = 20;
    vector<vector<int>> Left(n + 1, vector<int>(LG, 0));
    vector<vector<int>> Right(n + 1, vector<int>(LG, 0));

    for (int i = 1; i <= n; i++) Left[i][0] = L[i], Right[i][0] = R[i];
    for (int k = 1; k < LG; k++) {
        for (int i = 1; i <= n; i++) {
            Left[i][k]  = Left[Left[i][k - 1]][k - 1];
            Right[i][k] = Right[Right[i][k - 1]][k - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (a < b) {
            for (int i = LG - 1; i >= 0; i--) {
                int k = Right[a][i];
                if (k >= b) continue;
                else
                    ans += (1 << i), a = k;
            }
        } else {
            for (int i = LG - 1; i >= 0; i--) {
                int k = Left[a][i];
                if (k <= b) continue;
                else
                    ans += (1 << i), a = k;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
