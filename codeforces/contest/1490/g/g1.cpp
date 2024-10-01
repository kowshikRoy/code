/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-29
 * Task: g1 
 */

#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    ll s = 0;
    for(int i = 0; i < n; i ++) cin >> a[i], s += a[i];

    for(int i = 0; i < m; i ++) {
        int x;
        cin>>x;
        ll pre = 0;
        bool f = false;
        int cnt = 0;
        for(int j = 0; j < n; j ++) {
            pre += a[j];
            if(pre >= x) {
                cout << j << " ";
                f = true;
                break;
            }
            cnt ++;
        }
        if(f == false) {
            if(s > 0) {
                int j = 0;
                for(; ;) {
                    pre += a[j];
                    if(pre >= x) {
                        cout<<cnt << " ";
                        break;
                    }
                    j = (j + 1) % n;
                    cnt ++;
                }
            }
            else cout << -1 << " ";
        }
    }
    cout<<endl;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}

