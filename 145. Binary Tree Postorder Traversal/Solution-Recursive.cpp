/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  void postorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr)
      return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    postorder(root, res);
    return res;
  }
};
