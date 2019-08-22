#include "../leetcode.h"

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      vector<int> res;
      queue<TreeNode *> que;
      que.push(root);
      TreeNode *tmp;
      while(!que.empty()) {
        tmp = que.front();
        que.pop();
        if (tmp != nullptr) {
          res.push_back(tmp->val);
          que.push(tmp->left);
          que.push(tmp->right);
        }
      }
      return res;
    }
};