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
 * Date: 2021-04-29
 * Task: c
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> u(n), s(n);
        vector<int> cnt(n + 1);
        vector<vector<int>> member(n + 1);
        vector<vector<long long>> pf(n + 1);
        vector<ll> psum(n + 1);
        REP(i, n) cin >> u[i], cnt[u[i]]++;
        REP(i, n) cin >> s[i], member[u[i]].push_back(s[i]);
        for (int i = 1; i <= n; i++) sort(member[i].begin(), member[i].end());
        for (int i = 1; i <= n; i++) {
            auto &m = member[i];
            if (m.size() == 0) continue;
            ll sum = 0;
            for (auto x : member[i]) {
                sum += x;
                pf[i].push_back(sum);
            }
            psum[i] = sum;
        }
        vector<int> top;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0) { top.push_back(i); }
        }
        sort(top.begin(), top.end(),
             [&](int a, int b) { return cnt[a] < cnt[b]; });

        auto calc = [&](int uni, int k) -> ll {
            auto &m = member[uni];
            int o   = m.size() % k;
            ll ret  = psum[uni];
            dbg(uni, k, m, o, ret);
            if (o > 0) ret -= pf[uni][o - 1];
            return ret;
        };

        int pivot = 0;
        for (int k = 1; k <= n; k++) {
            while (pivot < top.size() && cnt[top[pivot]] < k) pivot++;
            ll ans = 0;
            for (int i = pivot; i < top.size(); i++) { ans += calc(top[i], k); }
            cout << ans << " ";
        }
        cout<<endl;
    }
    return 0;
}
