/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  int rob_dp(TreeNode *root, map<TreeNode *, int> &dp) {
    if (root == nullptr)
      return 0;
    if (dp.find(root) != dp.end())
      return dp[root];
    int val = root->val;
    if (root->left != nullptr)
      val += rob_dp(root->left->left, dp) + rob_dp(root->left->right, dp);
    if (root->right != nullptr)
      val += rob_dp(root->right->left, dp) + rob_dp(root->right->right, dp);
    int res = max(val, rob_dp(root->left, dp) + rob_dp(root->right, dp));
    dp[root] = res;
    return res;
  }
 public:
  int rob(TreeNode *root) {
    map<TreeNode *, int> dp;
    return rob_dp(root, dp);
  }
};
