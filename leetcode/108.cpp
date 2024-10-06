/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-27
 * Task: 108
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }
  TreeNode* buildTree(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return new TreeNode(nums[l]);
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, l, mid - 1);
    root->right = buildTree(nums, mid + 1, r);
    return root;
  }
};
