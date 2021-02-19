#include <bits/stdc++.h>
using namespace std;

int p[1000006];
int a[50005];

int n, m;
struct Query {
    int l, r, id;
    bool operator<(const Query &rhs) const { return r < rhs.r; }
};

vector<Query> q[505];
int BLOCK = 505;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= 1000000; i++) p[i] = p[i - 1] ^ i;

    for (int i = 0; i < m; i++) {
        Query tmp;
        tmp.id = i;
        scanf("%d %d", &tmp.l, &tmp.r);
        q[tmp.l / BLOCK].push_back(tmp);
    }

    for (int i = 0; i <= n / BLOCK; i++) {
        sort(q[i].begin(), q[i].end());
        int Pivot = max_element(q[i].begin(), q[i].end(), [](Query a, Query b) {
                        return a.l < b.l;
                    })->l;

        for (auto x : q[i]) { int L = x.l, R = x.r; }
    }

    return 0;
}
