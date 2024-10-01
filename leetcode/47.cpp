/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-24
 * Task: 47
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        vector<int> cur;
        int n = (int)nums.size();
        vector<bool> vis(n);

        function<void()> go = [&]() -> void {
            if ((int)cur.size() == n) {
                ret.push_back(cur);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    cur.push_back(nums[i]);
                    go();
                    vis[i] = 0;
                    cur.pop_back();
                    int j = i;
                    while (j + 1 < n && nums[j + 1] == nums[i]) j++;
                    i = j;
                }
            }
        };
        go();
        return ret;
    }
};
