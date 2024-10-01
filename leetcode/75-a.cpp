/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 75-a
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n  = (int)nums.size();
        int p1 = 0, p2 = n - 1;
        int cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[p1++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[p2--]);
            } else
                cur++;
        }
    }
};
