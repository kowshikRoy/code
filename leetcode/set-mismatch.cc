#include "set-mismatch.h"

#include <unordered_map>
#include <vector>
std::vector<int> Solution::findErrorNums(std::vector<int>& nums) {
  int mp[10004] = {0};
  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]]++;
  }
  int a = -1, b = -1;
  for (int i = 1; i <= nums.size(); i++) {
    if (mp[i] == 0) b = i;
    if (mp[i] == 2) a = i;
  }
  return {a, b};
}
