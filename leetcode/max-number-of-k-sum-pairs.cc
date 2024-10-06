#include "max-number-of-k-sum-pairs.h"

#include <unordered_map>
#include <vector>

int Solution::maxOperations(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> mp;
  int res = 0;
  for (auto x : nums) {
    if (mp.count(k - x) && mp[k - x] > 0) {
      res++;
      mp[k - x]--;
    } else
      mp[x]++;
  }
  return res;
}