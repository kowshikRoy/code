/**
 * Author: Repon Kumar Roy
 * Date: 2021-03-19
 * Task: A 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 2; i < n; i ++) {
        if(n % i == 0) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
