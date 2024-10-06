/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 111
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
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int r = INT_MAX;
    if (root->left) r = min(r, 1 + minDepth(root->left));
    if (root->right) r = min(r, 1 + minDepth(root->right));
    return r;
  }
};
