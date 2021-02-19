#include <cstdio>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define MP make_pair
int n, k;
int x[1005], y[1005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) flag = false;
            }
            if (flag) ans = 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
