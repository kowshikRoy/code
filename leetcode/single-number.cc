#include "single-number.h"

#include <iostream>
#include <vector>

int Solution::singleNumber(std::vector<int>& nums) {
  int res = 0;
  for (auto x : nums) {
    res ^= x;
  }
  return res;
}