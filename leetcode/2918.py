from typing import List
class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1 = sum(nums1)
        sum2 = sum(nums2)
        zeroes1 = sum(1 for x in nums1 if x == 0)
        zeroes2 = sum(1 for x in nums2 if x == 0)
        if zeroes1 and zeroes2:
            return max(sum1 + zeroes1, sum2 + zeroes2)
        elif zeroes2:
            return sum1 if sum1 >= sum2 + zeroes2 else -1
        elif zeroes1:
            return sum2 if sum2 >= sum1 + zeroes1 else -1
        else:
            return sum1 if sum1 == sum2 else -1