#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    set<int> st;
    int beg[n + 1], vis[n + 1], p[n + 1], ans[n + 1];
    char t[n + 1];
    for (int i = 1; i <= n; i++) beg[i] = 1, vis[i] = 0;
    for (int i = 0; i < m; i++) {
        char type;
        int id;
        cin >> type >> id;
        p[i] = id;
        t[i] = type;
        if (type == '+') {
            if (vis[id] == 0) { beg[id] = 0; }
        } else {
            if (vis[id] == 0) { beg[id] = 1; }
        }
        vis[id] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (beg[i]) st.insert(i);
    for (int i = 1; i <= n; i++) ans[i] = 1;
    for (int i = 0; i < m; i++) {
        if (t[i] == '+') {
            assert(st.count(p[i]) == 0);
            if (st.size() > 0) ans[p[i]] = 0;
            st.insert(p[i]);
        } else {
            assert(st.count(p[i]) == 1);
            st.erase(p[i]);
            if (st.size() > 0) ans[p[i]] = 0;
        }

        for (int i : st) cout << i << " ";
        cout << endl;
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
        if (ans[i]) num++;
    cout << num << endl;
    for (int i = 1; i <= n; i++)
        if (ans[i]) cout << i << " ";
    cout << endl;

    return 0;
}
