class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
        prev = -1
        ret = []
        for i, g in enumerate(groups):
            if g != prev:
                ret.append(words[i])
                prev = g
        return ret
        