#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 70;
map<int, int> pos;
int prime[20];
int idx = 0;
map<int, int> Mask;
int cnt[100];
const int mod = 1e9 + 7;

void findMask() {
    for (int i = 1; i <= LIMIT; i++) {
        int v = 0;
        int t = i;
        for (int j = 0; j < idx; j++) {
            int cnt = 0;
            while (t % prime[j] == 0) {
                cnt++;
                cnt %= 2;
                t /= prime[j];
            }
            if (cnt) v |= (1 << j);
        }
        Mask[i] = v;
    }
}

inline long long bigmod(long long p, long long e, long long M) {
    long long ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> vis(LIMIT + 1, 0);
    for (int i = 2; i <= LIMIT; i++) {
        if (vis[i]) continue;
        prime[idx] = i;
        pos[i] = idx++;
        for (int j = i + i; j <= LIMIT; j += i) { vis[j] = 1; }
    }
    findMask();
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<long long> pre(1 << idx, 0), now(1 << idx, 0);
    long long p2[n + 1];
    p2[0] = 1;
    for (int i = 1; i <= n; i++) p2[i] = (2 * p2[i - 1]) % mod;
    pre[0] = 1;
    for (int i = 70; i > 0; i--) {
        for (int j = 0; j < 1 << idx; j++) {
            if (cnt[i] == 0) now[j] = pre[j];
            else
                now[j] = (pre[j ^ Mask[i]] * p2[cnt[i] - 1] % mod +
                          pre[j] * p2[cnt[i] - 1] % mod) %
                         mod;
        }
        pre = now;
    }
    cout << now[0] - 1 << endl;
    return 0;
}
