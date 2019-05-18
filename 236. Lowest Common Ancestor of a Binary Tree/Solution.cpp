//
// Created by fry on 2019-05-17
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  bool findAncestor(vector<TreeNode *> &res, TreeNode *root, int val) {
    if (root == nullptr)
      return false;

    if (root->val == val || findAncestor(res, root->left, val) || findAncestor(res, root->right, val)) {
      res.push_back(root);
      return true;
    }

    return false;
  }

 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == nullptr || q == nullptr)
      return nullptr;

    vector<TreeNode *> p_a, q_a;
    findAncestor(p_a, root, p->val);
    findAncestor(q_a, root, q->val);

    TreeNode *res = root;
    for (int i = p_a.size() - 1, j = q_a.size() - 1; i >= 0 && j >= 0 && p_a[i] == q_a[j]; i--, j--)
      res = p_a[i];
    return res;
  }
};
