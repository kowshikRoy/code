#include <bits/stdc++.h>
using namespace std;

bitset<(1LL << 31) + 1> bit;
int main() {
    unsigned int q, s, a, b;
    cin >> q >> s >> a >> b;
    unsigned long long sum = 0;
    while (q--) {
        unsigned int t = s >> 1;
        if (s & 1) {
            if (bit[t] == 0) {
                sum += t;
                bit[t] = 1;
            }
        } else {
            if (bit[t] == 1) {
                sum -= t;
                bit[s >> 1] = 0;
            }
        }
        s = a * s + b;
    }
    cout << sum << endl;
}
