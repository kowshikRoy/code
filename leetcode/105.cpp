/**
 * Author: Repon Kumar Roy
 * Date: 2021-06-20
 * Task: 105
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = (int)preorder.size();
        unordered_map<int, int> Pos;
        for (int i = 0; i < n; i++) Pos[inorder[i]] = i;

        function<TreeNode*(int&, int, int)> build = [&](int& cur, int l,
                                                       int r) -> TreeNode* {
            if (l > r) return nullptr;
            int v          = preorder[cur++];
            TreeNode* root = new TreeNode(v);
            int mid        = Pos[v];
            root->left     = build(cur, l, mid - 1);
            root->right    = build(cur, mid + 1, r);
            return root;
        };
        int cur = 0;
        return build(cur, 0, n - 1);
    }
};
