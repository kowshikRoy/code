#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H; if(sizeof...(T)) cerr << ", "; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-23
 * Task: 2169
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

struct node {
    int x, y, id;
};

ostream& operator<<(ostream &os, const node &rhs) { return os << "(" << rhs.x << "," << rhs.y << "," << rhs.id<<")"; }

void solve() {
    int n;
    cin >> n;
    vector<node> v;
    vector<int> com;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
        com.push_back(x);
        com.push_back(y);
    }
    sort(com.begin(), com.end());
    com.resize(unique(com.begin(), com.end()) - com.begin());

    for (auto& p : v) {
        p.x = lower_bound(com.begin(), com.end(), p.x) - com.begin() + 1;
        p.y = lower_bound(com.begin(), com.end(), p.y) - com.begin() + 1;
    }

    sort(v.begin(), v.end(), [](auto a, auto b) {
        if (a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    });

    vector<int> i_cover(n, 0);
    vector<int> i_get_cover(n, 0);
    vector<int> bit(com.size() + 5);

    auto upd = [&](int x, int v) -> void {
        while (x > 0) bit[x] += v, x -= x & -x;
    };

    auto query = [&](int x) -> int {
        int sum = 0;
        while (x < (int)bit.size()) sum += bit[x], x += x & -x;
        return sum;
    };

    set<int> s;
    for (auto p : v) {
        i_cover[p.id] = query(p.x);
        upd(p.x, 1);
    }
    sort(v.begin(), v.end(), [](auto a, auto b) {
            if(a.x == b.x) return a.y > b.y;
            return a.x < b.x;
    });

    fill(bit.begin(), bit.end(), 0);

    for (auto p : v) {
        i_get_cover[p.id] =  query(p.y);
        upd(p.y, 1);
    }

    REP(i, n) printf("%d%c", i_cover[i], i == n - 1 ? '\n' : ' ');
    REP(i, n) printf("%d%c", i_get_cover[i], i == n - 1 ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
