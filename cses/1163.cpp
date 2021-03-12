/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-12
 * Task: 1163
 */

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    set<pair<int, pair<int, int>>> s;
    s.insert(mp(x, mp(0, x)));
    set<int> cor;
    cor.insert(0);
    cor.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto ptr = cor.lower_bound(p);
        int R    = *ptr;
        ptr--;
        int L = *ptr;
        s.erase(mp(R - L, mp(L, R)));
        s.insert(mp(R - p, mp(p, R)));
        s.insert(mp(p - L, mp(L, p)));
        cor.insert(p);

        if (i) cout << " ";
        cout << s.rbegin()->first;
    }
    cout << endl;
}
