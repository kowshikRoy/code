"""
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
"""
class Solution:
    def is_palindrome(self, n: str):
        return n == reversed(n)
    def greater_palindrome(self, n: str):
        l = len(n)
        if l % 2 == 0: #even
            # try reversing the bottom half and see if it's greater
            nn = n[:l//2] + (n[:l//2])[::-1]
            if nn > n:
                return nn 
            one_added = str(int(n[:l//2])+1)
            
            if len(one_added) > l//2:
                ## 100-> 10001
                return str(one_added[0:len(one_added)-1]) + '0' + reversed(one_added[0: len(one_added)-1])
            nn = one_added[:l//2] + (one_added[:l//2])[::-1]
            return nn
        
    def nearestPalindromic(self, n: str) -> str:
        return self.greater_palindrome(n)
    
sol = Solution()
while True:
    num = input("Enter a number : ")
    print(f"Nearest Palindrome of {num} is {sol.nearestPalindromic(num)}")
    