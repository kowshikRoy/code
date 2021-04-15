/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-13
 * Task: 11539
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int inf = 1 << 28;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<vector<int>> T;
        T.push_back(vector<int>(26, -1));
        vector<int> V;

        auto insert = [&](string w, int v) -> void {
            int root = 0;
            for (auto c : w) {
                int v = c - 'a';
                if (T[root][v] == -1) {
                    T[root][v] = T.size();
                    T.push_back(vector<int>(26, -1));
                }
                root = T[root][v];
            }
            if (V.size() < root + 1) V.resize(root + 1, -inf);
            V[root] = max(V[root], v);
        };

        REP(i, n) {
            string w;
            int v;
            cin >> w >> v;
            insert(w, v);
        }

        string s;
        cin >> s;
        int L = (int)s.size();
        vector<int> dp(L + 1);
        dp[L] = 0;
        for (int i = L - 1; i >= 0; i--) {
            dp[i] = -p + dp[i + 1];
            string now;
            int root = 0;
            for (int j = i; j < L; j++) {
                int c = s[j] - 'a';
                if (T[root][c] == -1) break;
                root = T[root][c];
                if (V[root] != -inf) dp[i] = max(dp[i], V[root] + dp[j + 1]);
            }
        }

        cout << "Case " << ++cs << ": " << dp[0] << endl;
    }

    return 0;
}
