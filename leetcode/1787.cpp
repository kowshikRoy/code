/**
 * Author: Repon Kumar Roy
 * Date: 2021-08-21
 * Task: 1787
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<vector<int>> sets(k);
        for (int i = 0; i < n; i++) { sets[i % k].push_back(nums[i]); }

        auto calc = [&](vector<int>& v) -> int {
            int f[1024] = {0};
            for (auto x : v) f[x]++;
            int ans = v.size();
            for (auto x : v) { ans = min(ans, v.size() - f[x]); }
            return ans;
        };
        int ans = 0;
        for (auto& v : sets) { ans += calc(v); }
        return ans;
    }
};
