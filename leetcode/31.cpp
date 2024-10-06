/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-24
 * Task: 31
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) return;
    int n = (int)nums.size();
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        pivot = i;
        break;
      }
    }
    if (pivot == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // find the position where I can swap
    int k = n - 1;
    while (nums[k] <= nums[pivot]) k--;

    swap(nums[pivot], nums[k]);
    reverse(nums.begin() + pivot + 1, nums.end());
  }
};
