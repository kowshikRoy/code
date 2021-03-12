/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1632
 */

#include <bits/stdc++.h>
using namespace std;

struct Event {
    int pos, type, id, opp;
    bool operator<(const Event &rhs) const {
        if (pos == rhs.pos) return type < rhs.type;
        return pos < rhs.pos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back({x, 1, i, y});
        e.push_back({y, -1, i, x});
    }
    sort(e.begin(), e.end());
    set<pair<int, int>> live;
    int ans = n;
    for (auto x : e) {
        if (x.type == 1) {
            live.insert({x.opp, x.id});
        } else {
            live.erase({x.pos, x.id});
        }
        if (live.size() > k) {
            auto v = *live.rbegin();
            ans--;
            live.erase(v);
        }
    }

    cout << ans << endl;
}
