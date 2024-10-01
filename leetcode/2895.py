from typing import List
class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        processorTime.sort()
        tasks.sort(reverse=True)
        ans = 0
        for i in range(0, len(processorTime)):
            ans = max(ans, processorTime[i] + tasks[i*4])
        return ans