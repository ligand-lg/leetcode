/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> res;
    stack<TreeNode *> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
      auto node = tmp.top();
      tmp.pop();
      res.push_back(node->val);
      if (node->right != nullptr) {
        tmp.push(node->right);
      }
      if (node->left != nullptr) {
        tmp.push(node->left);
      }
    }
    return res;
  }
};
