/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-17
 * Task: a 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        set<int> s;
        vector<int> v;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
            if(s.count(a[i])) v.push_back(a[i]);
            else s.insert(a[i]);
        }
        for(auto x: s) cout << x << " ";
        for(auto x: v) cout << x << " ";

        cout << endl;
    }

}
