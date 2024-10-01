/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-24
 * Task: 46
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vis(nums.size(), 0);
        vector<int> cur;
        int n = (int)nums.size();

        function<void()> go = [&]() -> void {
            if (cur.size() == n) {
                ret.push_back(cur);
                return;
            }
            for (int i = 0; i < n; i++)
                if (vis[i] == 0) {
                    cur.push_back(nums[i]);
                    vis[i] = 1;
                    go();
                    cur.pop_back();
                    vis[i] = 0;
                }
        };

        go();
        return ret;
    }
};
