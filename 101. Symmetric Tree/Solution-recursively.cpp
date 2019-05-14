//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 *
 */

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  bool check(TreeNode *a, TreeNode *b) {
    if (a == nullptr)
      return b == nullptr;

    if (b == nullptr)
      return a == nullptr;

    return (a->val == b->val) && check(a->left, b->right) && check(a->right, b->left);
  }
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;

    return check(root->left, root->right);
  }
};
