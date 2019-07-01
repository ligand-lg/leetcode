/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
  void preorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
      return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    preorder(root, res);
    return res;
  }
};
