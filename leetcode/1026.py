# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return self.dfs_traverse(root, root.val, root.val)

    def dfs_traverse(
        self, root: Optional[TreeNode], min_value: int, max_value: int
    ) -> int:
        if not root:
            return 0

        left = self.dfs_traverse(
            root.left, min(min_value, root.val), max(max_value, root.val)
        )
        right = self.dfs_traverse(
            root.right, min(min_value, root.val), max(max_value, root.val)
        )
        return max(left, right, abs(min_value - root.val), abs(max_value - root.val))
