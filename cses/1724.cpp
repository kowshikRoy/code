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
 * Date: 2021-04-01
 * Task: 1724
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int mod = 1e9 + 7;
const ll INF  = 1LL << 60;

using Mat = vector<vector<ll>>;
Mat mul(Mat &A, Mat &B) {
    int r = (int)A.size(), c = (int)B[0].size();
    Mat C(r, vector<long long>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            ll v = INF;
            for (int k = 0; k < c; k++) v = min(v, A[i][k] + B[k][j]);
            C[i][j] = v;
        }
    return C;
}

Mat exp(Mat &A, long long e) {
    int r = (int)A.size(), c = (int)A[0].size();
    Mat C(r, vector<long long>(c));
    C = A;

    Mat B = A;
    while (true) {
        if (e & 1) C = mul(C, B);

        e >>= 1;
        if (e == 0) break;
        B = mul(B, B);
    }
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    Mat A(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        A[a][b] = min(A[a][b], c);
    }
    dbg(A);
    auto B = exp(A, k - 1);
    dbg(B);
    ll len = B[0][n - 1];
    if (len == INF) cout << -1 << endl;
    else
        cout << len << endl;
    return 0;
}
