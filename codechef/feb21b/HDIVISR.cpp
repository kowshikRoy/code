/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-14
 * Task: HDIVISR 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= 10; i ++) {
        if(n % i == 0) {
            ans = i;
        }
    }
    cout << ans << endl;
}
