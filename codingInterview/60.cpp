//
// Created by ligand on 2019-04-25.
//

#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int> > Print(TreeNode *pRoot) {
    queue<TreeNode *> que1;
    queue<TreeNode *> que2;
    vector<vector<int>> result;

    que1.push(pRoot);
    while (!que1.empty()) {
      vector<int> r1;
      while (!que1.empty()) {
        TreeNode *next = que1.front();
        if (next != nullptr) {
          r1.push_back(next->val);
          que2.push(next->left);
          que2.push(next->right);
        }
        que1.pop();
      }
      if (!r1.empty())
        result.push_back(r1);

      vector<int> r2;
      while (!que2.empty()) {
        TreeNode *next = que2.front();
        if (next != nullptr) {
          r2.push_back(next->val);
          que1.push(next->left);
          que1.push(next->right);
        }
        que2.pop();
      }
      if (!r2.empty())
        result.push_back(r2);
    }
    return result;
  }
};
