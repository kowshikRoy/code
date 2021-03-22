/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-23
 * Task: 2168
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

struct node {
    int x, y, id;
};
void solve() {
    int n;
    cin >> n;
    vector<node> v;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
    }
    sort(v.begin(), v.end(), [](auto a, auto b) {
        if (a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    });

    vector<int> i_cover(n, 0);
    vector<int> i_get_cover(n, 0);
    set<int> s;
    for (auto p : v) {
        auto ptr = s.lower_bound(p.x);
        if (ptr != s.end()) { i_cover[p.id] = 1; }
        s.insert(p.x);
    }

    set<pair<int, int>> so;
    for (auto p : v) {
        auto ptr = so.lower_bound(make_pair(p.x, -1));
        if (ptr != so.end()) {
            while (ptr != so.end())
                i_get_cover[ptr->second] = 1, ptr = so.erase(ptr);
        }
        so.insert(make_pair(p.x, p.id));
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
