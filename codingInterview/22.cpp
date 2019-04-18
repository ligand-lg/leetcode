#include "../leetcode.h"

class Solution {
 public:
  vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> helper;
    vector<int> result;
    TreeNode* next;
    for (helper.push(root); !helper.empty(); helper.pop()) {
      next = helper.front();
      if (next != nullptr) {
        result.push_back(next->val);
        helper.push(next->left);
        helper.push(next->right);
      }
    }
    return result;
  }
};