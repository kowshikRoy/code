/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-10
 * Task: MAXFUN 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a,a+n);
        cout << (a[n-1]-a[0]) * 2LL << endl;
    }
}
