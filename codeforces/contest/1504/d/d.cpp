/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-03
 * Task: d
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a;

    cin >> n;

    vector<vector<int>> y(n, vector<int>(n, 0));
    vector<array<int, 2>> Apos, Bpos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) & 1) {
                Apos.push_back({i, j});
            } else
                Bpos.push_back({i, j});
        }
    }

    vector<vector<int>> Arr(n, vector<int>(n));
    auto print = [&](int c, array<int, 2> p) {
        Arr[p[0]][p[1]] = c;
        cout << c << " " << p[0] + 1 << " " << p[1] + 1 << endl;
        cout << flush;
    };

    auto color = [&](int a, int b) {
        for (int i = 1; i <= 3; i++) {
            if (i != a && i != b) return i;
        }
        return -1;
    };

    int cnt = 0, A = 0, B = 0;

    for (int i = 0; i < n * n; i++) {
        cin >> a;
        if (A == 0) {
            // initialization
            for (int i = 1; i <= 3; i++) {
                if (i != a) {
                    A = i;
                    break;
                }
            }

            for (int i = 1; i <= 3; i++) {
                if (i != a && i != A) {
                    B = i;
                    break;
                }
            }
        }

        if (a != A) {
            if (Apos.size()) {
                print(A, Apos.back());
                Apos.pop_back();
            } else {
                print(color(a, A), Bpos.back());
                Bpos.pop_back();
            }

        } else if (a != B) {
            if (Bpos.size()) {
                print(B, Bpos.back());
                Bpos.pop_back();
            } else {
                print(color(a, B), Apos.back());
                Apos.pop_back();
            }
        }
    }

    return 0;
}
