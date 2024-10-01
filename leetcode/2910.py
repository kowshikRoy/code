from typing import List
from collections import defaultdict
from math import ceil
class Solution:
    def minGroupsForValidAssignment(self, nums: List[int]) -> int:
        count = defaultdict(int)
        for num in nums:
            count[num] += 1
        min_count = min(count.values())
        ans = len(nums)
        for i in range(1, min_count + 1):
            # check if i works and update ans
            possible, group_count =  True, 0
            for v in count.values():
                n = int(ceil(v / (i + 1)))
                if n * (i + 1 ) - v <= n:
                    possible = True
                    group_count += n
                else:
                    possible = False
                    break

            if possible:
                ans = group_count
        print(ans)
        return ans

