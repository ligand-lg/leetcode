/**
 *
 * T(n) = O(h)
 * S(n) = O(1)
 */

#include "../leetcode.h"

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root->val == p->val || root->val == q->val)
      return root;
    if (root->val > p->val == root->val > q->val)
      return lowestCommonAncestor(root->val > p->val ? root->left : root->right, p, q);
    return root;
  }
};
