/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 337
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int rob(TreeNode* root) {
    auto k = dfs(root);
    return max(k.first, k.second);
  }

  pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0};
    auto p1 = dfs(root->left);
    auto p2 = dfs(root->right);
    // taking root
    auto x = root->val + p1.second + p2.second;
    auto y = max(p1.first, p1.second) + max(p2.first, p2.second);
    return {x, y};
  }
};
