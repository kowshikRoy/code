/**
 * Author: Repon Kumar Roy
 * Date: 2021-09-04
 * Task: 363 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>>& g, int k) {
        int n = (int)g.size(), m = (int)g[0].size(), ans = INT_MIN;
        if(n > m) {
            vector<vector<int>> ng(m, vector<int>(n));
            for(int i = 0; i < n; i ++){ 
                for(int j = 0; j < m; j ++) ng[j][i] = g[i][j];
            }
            
            return this->f(ng, k);
        }
        for(int r1 = 0; r1 < n; r1 ++) {
            vector<int> T(m,0);
            for(int r2 = r1; r2 < n; r2 ++) {
                for(int j = 0; j < m; j ++) T[j] += g[r2][j];
                set<int> s;
                s.insert(0);
                int sum = 0;
                for(int j = 0; j < m; j ++) {
                    sum += T[j];
                    auto ptr = s.lower_bound(sum - k);
                    if(ptr != s.end() && sum - *ptr <= k) ans = max(ans, sum - *ptr);
                    s.insert(sum);
                }
                
            }
        }
        return ans;
    }
};


