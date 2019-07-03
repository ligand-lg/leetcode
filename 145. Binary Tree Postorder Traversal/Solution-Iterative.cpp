/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> res;
    stack<TreeNode *> tmp;
    auto node = root;
    tmp.push(node);
    while (!tmp.empty()) {
      node = tmp.top();
      tmp.pop();
      res.push_back(node->val);
      if (node->left != nullptr)
        tmp.push(node->left);
      if (node->right != nullptr)
        tmp.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

