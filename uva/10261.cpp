#include <bits/stdc++.h>
using namespace std;
enum { PORT, STARBOARD };

vector<int> dock;
int dp[204][10005];
int put[204][10005];

int solve(int idx, int l, int r) {
    if (idx == dock.size()) return 0;
    int &ret = dp[idx][l];
    if (ret != -1) return ret;
    int ret1 = 0, ret2 = 0;
    if (l >= dock[idx]) ret1 = 1 + solve(idx + 1, l - dock[idx], r);
    if (r >= dock[idx]) ret2 = 1 + solve(idx + 1, l, r - dock[idx]);
    if (ret1 >= ret2) {
        ret         = ret1;
        put[idx][l] = PORT;
    } else {
        ret         = ret2;
        put[idx][l] = STARBOARD;
    }
    return ret;
}
void print(int idx, int l, int r) {
    if (idx == dock.size() || dp[idx][l] == 0) return;
    if (put[idx][l] == PORT) {
        cout << "port" << endl;
        print(idx + 1, l - dock[idx], r);
    } else {
        cout << "starboard" << endl;
        print(idx + 1, l, r - dock[idx]);
    }
}
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        n *= 100;
        int sum = 0, x = 0;
        while (cin >> x) {
            if (x == 0) break;
            if (sum + x <= 2 * n) dock.push_back(x), sum += x;
            else
                sum = 2 * n + 1;
        }

        memset(dp, -1, sizeof dp);
        cout << solve(0, n, n) << endl;
        print(0, n, n);
        dock.clear();
        if (t) printf("\n");
    }
}
