/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-31
 * Task: 1713
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

const int N = 1e6 + 6;
int divisor[N];

void seive(int N) {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) divisor[j]++;
    }
}

void solve() {
    int x;
    cin >> x;
    cout << divisor[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    seive(N);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
