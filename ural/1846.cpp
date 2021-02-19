#include <bits/stdc++.h>
using namespace std;

#define lc  (2 * n)
#define rc  (2 * n + 1)
#define mid ((b + e) / 2)
int T[400005];
map<int, vector<int>> m;
void update(int n, int b, int e, int pos, int x) {
    if (b > pos || e < pos) return;
    if (b == e) {
        T[n] = x;
        return;
    }
    update(lc, b, mid, pos, x);
    update(rc, mid + 1, e, pos, x);
    T[n] = __gcd(T[lc], T[rc]);
}
int main() {
    int q, n;
    cin >> q;
    n = q;
    int pos = 0;
    while (q--) {
        int x;
        char c;
        cin >> c >> x;
        if (c == '+') {
            update(1, 0, n, pos, x);
            m[x].push_back(pos);
            pos++;

        } else {
            update(1, 0, n, m[x].back(), 0);
            m[x].pop_back();
        }
        if (T[1] == 0) cout << 1 << endl;
        else
            cout << T[1] << endl;
    }
}
