from typing import List
from math import ceil
import collections
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        ans = 0
        for v in count.values():
            if v == 1:
                return -1
            ans += int(ceil(v / 3))
        return ans

        