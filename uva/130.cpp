#include <bits/stdc++.h>

using namespace std;
int n, k;

int CountAlive(vector<int> &v) {
    int cnt = 0;
    for (auto x : v) cnt += (x != -1);
    return cnt;
}
int FindKthIdx(vector<int> &v, int p) {
    int n = CountAlive(v);
    int t = k;
    if (p >= v.size()) p = 0;

    while (1) {
        if (v[p] == -1) {
            p++;
            if (p == (int)v.size()) p = 0;
            continue;
        }
        if (t == 1) return p;
        t--;
        p++;
        if (p == (int)v.size()) p = 0;
    }
    return -1;
}
int main() {
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = i;
        int pos = 0;
        while (CountAlive(v) != 1) {
            int x = FindKthIdx(v, pos);
            v[x]  = -1;
            int y = FindKthIdx(v, x + 1);
            v[x]  = v[y];
            v[y]  = -1;

            pos = x + 1;
        }
        int ans = 0;
        for (auto x : v)
            if (x != -1) ans = x;
        if (ans == 0) cout << 1 << endl;
        else
            cout << n + 1 - ans << endl;
    }
}
