/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 437
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pathSum(TreeNode *root, int targetSum) {
    int ans = 0;
    unordered_map<int, int> H;
    H[0] = 1;
    function<void(TreeNode *, int)> preorder = [&](TreeNode *root,
                                                   int curSum) -> void {
      if (!root) return;
      int sum = curSum + root->val;
      ans += H[sum - targetSum];
      H[sum]++;
      preorder(root->left, sum);
      preorder(root->right, sum);
      H[sum]--;
    };
    preorder(root, 0);
    return ans;
  }
};
