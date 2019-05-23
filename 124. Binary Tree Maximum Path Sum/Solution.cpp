//
// Created by fry on 2019-05-23
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  int dfs(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int left_r = max(dfs(root->left), 0);
    int right_r = max(dfs(root->right), 0);

    res = max(res, left_r + right_r + root->val);

    return max(left_r, right_r) + (root->val);
  }

  int res;
 public:
  int maxPathSum(TreeNode *root) {
    res = root->val;
    dfs(root);
    return res;
  }
};
