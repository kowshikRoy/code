import string
class Solution:
    def is_adjacent(self,a, b) -> bool:
        return abs(ord(a) - ord(b)) <= 1
    def removeAlmostEqualCharacters(self, word: str) -> int:
        word = list(word)
        ans = 0
        for i in range(len(word)-1):
            a,b = word[i], word[i+1]
            if self.is_adjacent(a,b):
                # change b to a character that is not adjacent to a and c
                for x in string.ascii_lowercase:
                    if not(self.is_adjacent(a,x) or (i+2 < len(word) and self.is_adjacent(word[i+2], x))):
                        word[i+1] = x
                        ans += 1
                        break
        return ans