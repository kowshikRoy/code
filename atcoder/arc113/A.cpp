/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-21
 * Task: A 
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    long long ans = 0;
    for(int i = 1; i <= K; i ++) {
        for(int j = 1; j <= K; j ++) {
            if(i * j > K) break;
            for(int k = 1; k <= K; k ++) {
                if(1LL * i * j * k > K) break;
                ans ++;
            }
        }
    }
    cout << ans << endl;
}
