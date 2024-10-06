/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-10
 * Task: 1
 */

#include <bits/stdc++.h>

#include "debug.cpp"
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> H;
    for (int i = 0; i < (int)nums.size(); i++) {
      if (H.count(target - nums[i])) return {H[target - nums[i]], i};
      H[nums[i]] = i;
    }
    return {-1, -1};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  dbg(Solution().twoSum(nums, target));
  return 0;
}
