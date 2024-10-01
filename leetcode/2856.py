import collections
from typing import List
class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        count = collections.defaultdict(int)
        for num in nums:
            count[num] += 1
        tup = [(k,v) for (k,v) in count.items()]
        tup.sort(key=lambda x: x[0])
        freqs = [x[1] for x in tup]
        while len(freqs) > 0:
            freq = freqs.pop()
            while len(freqs) > 0 and freq > 0:
                to_match = min(freqs[-1], freq)
                freqs[-1] -= to_match
                freq -= to_match
                if freqs[-1] == 0:
                    freqs.pop()
        
        return freqs[0]
