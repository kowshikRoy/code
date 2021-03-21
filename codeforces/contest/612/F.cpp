#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 4;
const int N   = 2005;
int a[N], n, s;

int dp1[N], dp2[N];
int nt[N];

int d(int a, int b) { return min(abs(a - b), n - abs(a - b)); }
int cd(int a, int b) {
    int d = b - a;
    (d < 0) && (d += n);
    return d;
}

int solve1(int);

int solve2(int v) {
    int &ret = dp2[v];
    if (ret != -1) return ret;

    if (nt[v] == INT_MAX) return ret = 0;
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (a[i] == nt[v]) { ret = min(ret, d(i, v) + solve1(i)); }
    }
    return ret;
}

int solve1(int v) {
    int &ret = dp1[v];
    if (ret != -1) return ret;

    ret = INF;
    for (int d = -1; d <= 1; d += 2) {
        int u = -1;
        for (int i = 1; i < n; i++) {
            int vv = (v + i * d + n) % n;
            if (a[vv] == a[v]) {
                u = vv;
                break;
            }
        }
        if (u == -1) return ret = solve2(v);

        int dt = d == 1 ? cd(u, v) : cd(v, u);
        ret    = min(ret, solve2(u) + dt);
    }
    return ret;
}

void restore1(int);
void restore2(int v) {
    int &ans = dp2[v];
    if (ans == -1) throw;
    if (nt[v] == INT_MAX) return;
    for (int i = 0; i < n; i++) {
        if (a[i] == nt[v] && solve1(i) + d(i, v) == ans) {
            int d = i - v;
            (d < 0) && (d += n);
            if (d <= n - d) printf("+%d\n", d);
            else
                printf("-%d\n", n - d);
            return restore1(i);
        }
    }
}

void restore1(int v) {
    int &ans = dp1[v];
    if (ans == -1) throw;
    for (int d = -1; d <= 1; d += 2) {
        int u = -1;
        for (int i = 1; i < n; i++) {
            int vv = (v + i * d + n) % n;
            if (a[vv] == a[v]) {
                u = vv;
                break;
            }
        }
        if (u == -1) return restore2(v);

        int dt = d == 1 ? cd(u, v) : cd(v, u);
        if (solve2(u) + dt == ans) {
            int cdt = 0;
            for (int i = 1; i < n; i++) {
                int vv = (v + i * (-d) + n) % n;
                cdt++;
                if (a[vv] == a[v]) {
                    printf("%c%d\n", d == +1 ? '-' : '+', cdt);
                    cdt = 0;
                }
            }
            return restore2(u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    s--;
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n; i++) nt[i] = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] > a[i]) nt[i] = min(nt[i], a[j]);
        }
    }
    int minV = *min_element(a, a + n);
    int ans  = INF;
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);

    for (int i = 0; i < n; i++) {
        if (a[i] == minV) { ans = min(ans, solve1(i) + d(s, i)); }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] == minV && solve1(i) + d(s, i) == ans) {
            int d = i - s;
            (d < 0) && (d += n);
            if (d <= n - d) printf("+%d\n", d);
            else
                printf("-%d\n", n - d);
            restore1(i);
            break;
        }
    }
    return 0;
}
