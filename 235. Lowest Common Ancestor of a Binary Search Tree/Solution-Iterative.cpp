/**
 *
 * T(n) = O(h)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    const auto p_val = p->val;
    const auto q_val = q->val;
    while (root->val != p_val && root->val != q_val && (root->val < p_val == root->val < q_val)) {
      root = root->val < p_val ? root->right : root->left;
    }
    return root;
  }
};
