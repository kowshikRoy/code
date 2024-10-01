/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 338 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i ++) dp[i] = (dp[i] / 2) + (i & 1);
        return dp;
    }
};

