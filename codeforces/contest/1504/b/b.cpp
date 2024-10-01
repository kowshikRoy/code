#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << "]" << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
    
/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-03
 * Task: b
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        cnt[i] = (i > 0 ? cnt[i - 1] : 0);
        if (s[i] == '1') cnt[i]++;
    }

    auto valid = [&](int x) {
        int p = cnt[x];
        int q = (x + 1 - cnt[x]);
        return p == q;
    };

    auto invert = [](char c) {
        if (c == '1') return '0';
        else
            return '1';
    };

    int flag = 0;
    for (int i = n - 1; i >= 0; i--) {
        int charNow = flag ? invert(s[i]) : s[i];
        s[i]        = charNow;
        if (t[i] != charNow) {
            if (valid(i)) {
                flag ^= 1;
            } else {
                cout << "NO" << endl;
                return;
            }
            s[i] = invert(s[i]);
        }
        dbg(s);
        dbg(t);
    }

    cout << "YES" << endl;
    dbg(s,t);

    assert(s == t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
