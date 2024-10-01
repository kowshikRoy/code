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
 * Date: 2021-04-03
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int asum = 0, bsum = 0;

    char A[n + 1], B[n + 1];
    A[n] = B[n] = 0;
    vector<int> pos;

    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            if(asum > 0 && bsum > 0) {
                asum --;
                bsum --;
                A[i] = ')';
                B[i] = ')';
                pos.push_back(i);
            }
            else {
                asum ++;
                bsum ++;
                A[i] = '(';
                B[i] = '(';
            }
        }
        else {
            if(asum > 0 && asum >= bsum) {
                asum --;
                bsum ++;
                A[i] = ')';
                B[i] = '(';
            }
            else if(bsum > 0 && asum < bsum) {
                bsum --;
                asum ++;
                A[i] = '(';
                B[i] = ')';
            }
            else if(pos.size()){
                int t = pos.back(); pos.pop_back();
                A[t] = '(';
                B[t] = '(';
                asum += 2;
                bsum += 2;
                i = i - 1;

            }
            else {
                cout << "NO" << endl;
                return ;
            }

        }
        dbg(pos);
    }

    if (asum == 0 && bsum == 0) {
        cout << "YES" << endl;
        cout << A << endl;
        cout << B << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') assert(A[i] == B[i]);
            else
                assert(A[i] != B[i]);
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
