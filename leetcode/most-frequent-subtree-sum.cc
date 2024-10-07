#include <functional>
#include <unordered_map>
#include <vector>
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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> fr;
    function<int(TreeNode *)> dfs = [&](TreeNode *cur) {
      if (!cur) return 0;
      int sum = dfs(cur->left) + dfs(cur->right) + cur->val;
      fr[sum]++;
      return sum;
    };
    dfs(root);
    vector<int> ans;
    int maxFr = 0;
    for (auto [k, v] : fr) {
      if (v > maxFr) {
        ans.clear();
        ans.push_back(k);
        maxFr = v;
      } else if (v == maxFr)
        ans.push_back(k);
    }
    return ans;
  }
};

#include <gtest/gtest.h>

TEST(MostFrequentSubtreeSumTest, Test1) {
  Solution solution;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-3);
  vector<int> expected = {2, -3, 4};
  vector<int> actual = solution.findFrequentTreeSum(root);
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  ASSERT_EQ(actual, expected);
}

TEST(MostFrequentSubtreeSumTest, Test2) {
  Solution solution;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-5);
  vector<int> expected = {2};
  vector<int> actual = solution.findFrequentTreeSum(root);
  ASSERT_EQ(actual, expected);
}