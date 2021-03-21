/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-18
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
        int n,k1,k2 ,w , b;
        cin >> n >> k1 >> k2;
        cin >> w >> b;
        int w1 = (k1 + k2)/2;
        int b1 = (2 * n - k1 - k2)/2;
        if(b1 >= b && w1 >= w) puts("YES");
        else puts("NO");
    }
}
