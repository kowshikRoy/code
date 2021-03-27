/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-25
 * Task: ishtiaque-and-the-rabbit
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    int q;
    scanf("%lld", &q);
    while (q--) {
        ll k;
        scanf("%lld", &k);
        int ans = 0;
        for(int i = 1; i<= n; i ++) {
            if(k % i == 0) ans ++;
        }
        printf("%d", ans);
    }
}

void gen() {
    vector<ll> v;
    v.push_back(1);
    for(int i = 
}

int main() {
    gen();
    solve();
    return 0;
}
