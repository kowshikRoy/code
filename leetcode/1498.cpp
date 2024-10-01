/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-23
 * Task: 1498 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for(int r = n - 1, l = 0; r >= l; r -- ) {
            while(l <= r && nums[r] + nums[l] <= target) {
                l ++;
            }
            // nums[r] + nums[l] > target, so l is not valid

            
        }

    }
};  

