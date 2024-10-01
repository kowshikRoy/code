class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        prev, ans = matrix[0], min(matrix[0])
        for r in range(1, row):
            now = [float("inf")] * col
            for c in range(0, col):
                for j in [-1, 0, 1]:
                    if c + j >= 0 and c + j < col:
                        now[c] = min(now[c], prev[c + j] + matrix[r][c])
            prev = now
            ans = min(prev)
        return ans
