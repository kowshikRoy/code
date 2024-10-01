class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        count = s.count('1') - 1
        return "1"*count + "0"*(len(s)-count-1) + "1"