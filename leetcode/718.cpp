/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-20
 * Task: 718
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        int dp[n][m];
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j])
                    dp[i][j] =
                        1 + (i + 1 < n && j + 1 < m ? dp[i + 1][j + 1] : 0);
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
