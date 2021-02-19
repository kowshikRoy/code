#include <bits/stdc++.h>
using namespace std;

int cp[] = {6, 10, 14, 15, 21};

int cur[3];
int ans[4];
int n;
bool dfs(int t, int sum) {
    if (t == 3) {
        int v = n - sum;
        if (v == cur[0] || v == cur[1] || v == cur[2] || v < 1) return false;
        ans[0] = cur[0], ans[1] = cur[1], ans[2] = cur[2], ans[3] = v;
        return true;
    }

    bool ret = false;
    for (int i = 0; i < 5; i++) {
        int v = cp[i];
        bool flag = true;
        for (int j = 0; j < t; j++) {
            if (v == cur[j]) { flag = false; }
        }
        if (!flag) continue;
        cur[t] = v;
        ret = dfs(t + 1, sum + v);
        cur[t] = -1;
        if (ret) break;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 6 + 10 + 14;

        bool f = dfs(0, 0);
        if (f) {
            printf("YES\n%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
        } else
            printf("NO\n");
    }
    return 0;
}
