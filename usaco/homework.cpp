#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {  // the argument is the filename without the extension
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 5;
long long sum[N], p[N], m[N];
int main() {
    setIO("homework");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> p[i]; }
    sum[n] = p[n];
    m[n]   = p[n];
    for (int i = n - 1; i >= 1; i--) {
        sum[i] = sum[i + 1] + p[i];
        m[i]   = min(m[i + 1], p[i]);
    }

    long long A = 0, B = 1;
    vector<int> K;

    for (int i = 1; i <= n - 2; i++) {
        if (A * (n - i - 1) < (sum[i + 1] - m[i + 1]) * B) {
            A = sum[i + 1] - m[i + 1];
            B = n - i - 1;
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        if (A * (n - i - 1) == (sum[i + 1] - m[i + 1]) * B) cout << i << endl;
    }
}
