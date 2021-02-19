#include <bits/stdc++.h>
using namespace std;

struct event {
    int t, kind, id, nxt;
};
int main() {
    int t, cs = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<event> e;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            e.push_back({x, 1, i, y});
            e.push_back({y, -1, i, -1});
        }
        sort(e.begin(), e.end(), [](const event a, const event b) {
            if (a.t == b.t) return a.kind < b.kind;
            else
                return a.t < b.t;
        });

        int b1 = -1, b2 = -1, flag = 1, cnt = 0;
        char out[n + 1];
        out[n] = 0;
        for (auto ev : e) {
            if (ev.kind == 1) {
                if (ev.t >= b1) {
                    b1 = ev.nxt;
                    out[ev.id] = 'C';
                } else if (ev.t >= b2) {
                    b2 = ev.nxt;
                    out[ev.id] = 'J';
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) printf("Case #%d: %s\n", ++cs, out);
        else
            printf("Case #%d: IMPOSSIBLE\n", ++cs);
    }
}
