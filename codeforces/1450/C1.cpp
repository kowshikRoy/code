#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

char g[304][304];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> g[i];

        int cnt = 0, change = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != 'X') continue;
                cnt++;
                if (i > 1 && g[i - 1][j] == 'X' && g[i - 2][j] == 'X') {
                    g[i][j] = 'O';
                    change++;
                    continue;
                }
                if (j > 1 && g[i][j - 1] == 'X' && g[i][j - 2] == 'X') {
                    g[i][j] = 'O';
                    change++;
                    continue;
                }
                int row = 0, col = 0;
                if (j > 0 && j + 1 < n && g[i][j - 1] == 'X' &&
                    g[i][j + 1] == 'X')
                    row = 1;
                if (j + 2 < n && g[i][j + 1] == 'X' && g[i][j + 2] == 'X')
                    row = 1;

                if (i > 0 && i + 1 < n && g[i - 1][j] == 'X' &&
                    g[i + 1][j] == 'X')
                    col = 1;
                if (i + 2 < n && g[i + 1][j] == 'X' && g[i + 2][j] == 'X')
                    col = 1;

                if (row && col) {
                    g[i][j] = 'O';
                    change++;
                    continue;
                }
            }
        }
        for (int i = 0; i < n; i++) cout << g[i] << endl;
        cout << cnt << endl;
        cout << change << endl;
        assert(change <= cnt / 3);
    }

    return 0;
}
