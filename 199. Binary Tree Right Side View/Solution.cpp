/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr)
      return {};
    queue<TreeNode *> tmp;
    vector<int> res;
    auto pre = root;
    tmp.push(root);
    tmp.push(nullptr);
    while (!tmp.empty()) {
      auto top = tmp.front();
      tmp.pop();
      if (top == nullptr) {
        res.push_back(pre->val);
        if (!tmp.empty())
          tmp.push(nullptr);
      } else {
        pre = top;
        if (top->left != nullptr)
          tmp.push(top->left);
        if (top->right != nullptr)
          tmp.push(top->right);
      }
    }
    return res;
  }
};
