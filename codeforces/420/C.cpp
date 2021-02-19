#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int B[N];
int cnt[N];
void update(int x, int v) {
    if (x <= 0) return;
    while (x < N) B[x] += v, x += x & -x;
}

int query(int x) {
    if (x <= 0) return 0;
    int ret = 0;
    while (x) ret += B[x], x -= x & -x;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;

    map<int, vector<int>> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        cnt[x]++;
        cnt[y]++;
        m[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) { update(cnt[i], 1); }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        update(cnt[i], -1);
        for (auto y : m[i]) {
            update(cnt[y], -1);
            cnt[y]--;
            update(cnt[y], 1);
        }
        int need = p - cnt[i];
        if (need > 0) {
            ans += query(N - 1) - query(need - 1);
        } else
            ans += (n - i);
        for (auto y : m[i]) {
            update(cnt[y], -1);
            cnt[y]++;
            update(cnt[y], 1);
        }
    }
    cout << ans << endl;
    return 0;
}
