/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 75
 */

#include <bits/stdc++.h>

#include "debug.cpp"
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n          = (int)nums.size();
        auto partition = [](vector<int>& nums, int pivot) {
            int cur = 0;
            for (int i = 0; i < (int)nums.size(); i++) {
                if (nums[i] <= pivot) {
                    swap(nums[cur], nums[i]);
                    cur++;
                }
            }
        };

        partition(nums, 0);
        partition(nums, 1);
    }
};
int main() {
    vector<int> v = {0, 1, 2, 0, 1, 2, 0};
    Solution().sortColors(v);
    dbg(v);
}
