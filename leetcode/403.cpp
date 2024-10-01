/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-20
 * Task: 403
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& nums) {
        int n = (int)nums.size();

        auto can_jump = [&](int npos) -> int {
            int it = lower_bound(nums.begin(), nums.end(), npos) - nums.begin();
            return it != n && nums[it] == npos ? it : -1;
        };

        function<bool(int, int)> rec = [&](int pos, int k) -> bool {
            if (pos == n - 1) return true;
            int& ans = dp[pos][k];
            if (ans != -1) return ans;
            ans = false;
            for (int i = -1; i <= 1; i++) {
                int t = k + i;
                if (t <= 0) continue;
                int nxt = can_jump(nums[pos] + t);
                if (nxt != -1) ans |= rec(nxt, t);
            }
            return ans;
        };
        return rec(0, 0);
    }
};
