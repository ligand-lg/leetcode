/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr)
      return false;
    if (root->left == nullptr && root->right == nullptr)
      return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

