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
 * Date: 2021-05-01
 * Task: roaring-year
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s = to_string(n);
        string ans;

        auto cmp = [](string a, string b) {
            if (a == b) return 0;
            if (a.size() < b.size() || (a.size() == b.size() && a < b))
                return -1;
            return 1;
        };

        auto get = [&](ll n) -> string {
            string o;
            for (ll i = n;; i++) {
                o += to_string(i);
                if (cmp(o, s) > 0) return o;
            }
        };

        for (int i = 0; i < 22; i++) ans.push_back('9');


        for (int len = 1; len < s.length(); len++) {
            ll p    = stoll(s.substr(0, len));
            string t = get(p);
            if (cmp(t, ans) < 0) { ans = t; }
            t = get(p+1);
            if (cmp(t, ans) < 0) { ans = t; }
        }
        string tmp = s;
        s.insert(s.begin(), '1');
        for(int i = 1; i < s.size(); i ++) s[i] = '0';
        for (int len = 1; len < s.length(); len++) {
            ll p    = stoll(s.substr(0, len));
            string t = get(p);
            if (cmp(t, ans) < 0) { ans = t; }
            t = get(p+1);
            if (cmp(t, ans) < 0) { ans = t; }
        }

        cout<< "Case #" << ++cs << ": " << ans << endl;
    }

    return 0;
}
