#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int p[N], P[N];
vector<int> vec[N];
int f(int a) {
    if (p[a] == a) return a;
    return p[a] = f(p[a]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> P[i];
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int u = f(x), v = f(y);
        if (u != v) p[u] = v;
    }
    for (int i = 1; i <= n; i++) p[i] = f(i), vec[p[i]].push_back(i);
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        auto &pos = vec[i];
        vector<int> num;
        for (int i : pos) num.push_back(P[i]);
        sort(num.begin(), num.end(), greater<int>());
        for (int i = 0; i < pos.size(); i++) ans[pos[i]] = num[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    return 0;
}
