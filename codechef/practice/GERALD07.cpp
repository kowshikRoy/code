#include <bits/stdc++.h>
using namespace std;
#define in(x)        input(x)
#define in2(x, y)    in(x), in(y)
#define in3(x, y, z) in(x), in2(y, z)
template <class T> inline void input(T &x) {
    register char c = getchar_unlocked();
    x               = 0;
    int neg         = 0;
    for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked())
        ;
    if (c == '-') {
        neg = 1;
        c   = getchar_unlocked();
    }
    for (; c > 47 && c < 58; c = getchar_unlocked()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if (neg) x = -x;
}

const int N     = 200005;
const int block = 400;
int n, m, ques;
struct Query {
    int blockId;
    int l, r, id;
    int ans;
    bool operator<(const Query &q) const { return r < q.r; }
};

vector<Query> pp[500];
int u[N], v[N];
int begBlock(int blockId) { return blockId * block; }
int endBlock(int blockId) { return min(m - 1, (blockId + 1) * block); }

int fr(vector<int> &p, int a) {
    if (p[a] == a) return a;
    return p[a] = fr(p, p[a]);
}

int fn(vector<int> &p, int a) {
    if (p[a] == a) return a;
    return p[a] = fn(p, p[a]);
}
int main() {
    int t;
    in(t);
    while (t--) {
        in3(n, m, ques);
        for (int i = 1; i <= m; i++) { in2(u[i], v[i]); }

        for (int i = 0; i < ques; i++) {
            Query q;
            q.id = i;
            in2(q.l, q.r);
            pp[q.l / block].push_back(q);
        }
        for (int i = 0; i <= m / block; i++) {
            sort(pp[i].begin(), pp[i].end());
            vector<int> p(n + 1), H(n + 1);
            for (int i = 1; i <= n; i++) p[i] = i, H[i] = i;
            int R = begBlock(i + 1);
            for (auto q : pp[i]) {
                if (q.l / block == q.r / block) {
                    int ans = n;
                    for (int i = q.l; i <= q.r; i++) {
                        int u = fr(p, e[i].u), v = fr(p, e[i].v);
                        if (u != v) { ans--; }
                    }
                } else {
                    while (R < q.r) {
                        int u = fn(H, e[R].u), v = fn(H, e[R].v);
                        if (u != v) Hans--;
                        R++;
                    }

                    int off = endBlock(i);
                    while (off >= q.l) {
                        int u = fr(H, u[off]), v = fr(H, v[off]);
                        if (u != v) { Hans--; }
                        off--;
                    }
                }
            }
        }
    }
