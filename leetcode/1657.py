class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        c1, c2 = Counter(word1), Counter(word2)
        return sorted(c1.values()) == sorted(c2.values()) and set(c1.keys()) == set(c2.keys())
        