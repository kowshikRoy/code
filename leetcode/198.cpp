/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 198
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int a = 0, b = nums[0], ans = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int now = max(b, nums[i] + a);
            a       = b;
            b       = now;
            ans     = max(ans, b);
        }
        return ans;
    }
};
