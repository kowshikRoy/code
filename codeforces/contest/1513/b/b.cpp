/**
 * Author: Repon Kumar Roy
 * Date: 2021-04-12
 * Task: b 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 2e5+5;
    const int mod = 1e9 +7;

    vector<ll> f(N);
    f[0] = 1;
    for(int i = 1; i < N; i ++) f[i] = (i * f[i - 1]) % mod;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        map<int,int> cnt;
        ll ans = (1LL << 32) - 1;
        for(int i = 0; i < n; i ++) {
            int x;
            cin>>x;
            ans &= x;
            cnt[x] ++;
        }

        if(cnt.count(ans)) {
            ll t = cnt[ans];
            cout<< ((t * (t - 1)) % mod * f[n - 2]) % mod << endl;
        }
        else 
        cout<< 0 << endl;
    }

    return 0;
}

