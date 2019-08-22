#include "../leetcode.h"

class Solution {
  vector<vector<int>> help(TreeNode *root, int exp) {
    vector<vector<int>> res;
    if (root == nullptr) {
      // 空节点
      return res;
    }else if (root->left == nullptr && root->right == nullptr) {
      // 叶子节点
      if (root->val == exp)
        res.push_back(vector<int>{root->val});
    }else {
      // 非叶子节点
      res = help(root->left, exp - root->val);
      for (const auto &item : help(root->right, exp - root->val)){
        res.push_back(item);
      }
      for (auto &item : res) {
        item.insert(item.begin(), root->val);
      }
    }
    return res;
  }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      auto res = help(root, expectNumber);
      sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b) {
        return a.size() > b.size();
      });
      return res;
    }
};
