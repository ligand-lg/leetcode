/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
  // 0 - 不用root ，1 - 用root
  pair<int, int> postorder(TreeNode *root) {
    if (root == nullptr)
      return make_pair(0, 0);
    auto left_res = postorder(root->left);
    auto right_res = postorder(root->right);
    return make_pair(
        max(left_res.first, left_res.second) + max(right_res.first, right_res.second),
        root->val + left_res.first + right_res.first
    );
  }
 public:
  int rob(TreeNode *root) {
    auto res = postorder(root);
    return max(res.first, res.second);
  }
};

