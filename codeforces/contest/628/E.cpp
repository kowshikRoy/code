#include <bits/stdc++.h>
using namespace std;
const int N = 3003;
int n, m;
int L[N][N], R[N][N];
char g[N][N];
vector<pair<int, int>> arr[N << 1];
int ptr[N][N], dp[N][N];
int B[N];

void upd(int x, int v) {
    while (x < N) B[x] += v, x += x & -x;
}

int query(int x) {
    int sum = 0;
    while (x > 0) sum += B[x], x -= x & -x;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);

    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'z') cur++;
            else
                cur = 0;
            L[i][j] = cur;
        }
        cur = 0;
        for (int j = m; j >= 1; j--) {
            if (g[i][j] == 'z') cur++;
            else
                cur = 0;
            R[i][j] = cur;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { arr[i + j].push_back({i, j}); }
    }

    long long ans = 0;
    for (int i = 2; i <= n + m; i++) {
        memset(B, 0, sizeof B);
        vector<int> pid[n + 1];
        vector<int> ptr(n + m + 1, -1);

        vector<pair<int, int>> &now = arr[i];
        int zero                    = -1;
        for (int j = 0; j < now.size(); j++) {
            auto p = now[j];
            int x = p.first, y = p.second;
            if (g[x][y] == '.') {
                zero = x;
            } else {
                int id = max(zero, x - R[x][y]);
                if (id > 0) pid[id].push_back(j), ptr[j] = id;
            }
        }

        for (int j = 0; j < now.size(); j++) {
            auto p = now[j];
            int x = p.first, y = p.second;
            if (g[x][y] == 'z') {
                upd(y - L[x][y] + 1, 1);
                int v  = query(y);
                int xx = ptr[j];
                if (xx != -1) v -= dp[xx][y];
                ans += v;
            }
            for (auto y : pid[x]) {
                dp[x][now[y].second] = query(now[y].second);
            }
        }
    }
    cout << ans << endl;
}
