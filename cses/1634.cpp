/**
 * Author: Repon Kumar Roy
 * Date: 2021-02-22
 * Task: 1634 
 */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
const int N = 1e6+6;
int dp[N], c[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i ++) cin >> c[i];
    for(int i = 0; i <= x; i ++) dp[i] = INF;
    dp[0] = 0;
    
    for(int i = 0; i < n; i ++) {
        int v = c[i];
        for(int j = 0; j <= x; j ++) {
            if(j >= v) dp[j] = min(dp[j], 1 + dp[j-v]);
        }
    }
    printf("%d\n", dp[x] == INF ? -1 : dp[x]);

}
