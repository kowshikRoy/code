#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[k];
    vector<int> vis(n, 0);
    for (int i = 0; i < k; i++) cin >> a[i];
    int ptr = 0;
    int tot = n;

    auto fin = [&](int ptr) {
        while (1) {
            if (ptr == n) ptr = 0;
            if (!vis[ptr]) return ptr;
            else
                ptr++;
        }
    };
    for (int i = 0; i < k; i++) {
        int step = a[i] % tot;
        while (step--) {
            ptr      = fin(ptr + 1);
            int last = -1;
        }
        vis[ptr] = 1;
        cout << ptr + 1 << " ";
        ptr = fin(ptr + 1);
        tot--;
    }
    return 0;
}
