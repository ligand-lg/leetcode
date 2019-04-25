//
// Created by ligand on 2019-04-25.
//
#include "../leetcode.h"

class Solution {
 public:
  vector<vector<int> > Print(TreeNode *pRoot) {
    vector<vector<int>> result;
    queue<TreeNode*> que1;
    queue<TreeNode*> que2;
    que1.push(pRoot);
    while(!(que1.empty() && que2.empty())) {
      vector<int> left_to_right;
      while(!que1.empty()) {
        TreeNode *next = que1.front();
        if (next != nullptr) {
          left_to_right.push_back(next->val);
          que2.push(next->left);
          que2.push(next->right);
        }
        que1.pop();
      }
      if (!left_to_right.empty())
        result.push_back(left_to_right);

      vector<int> right_to_left;
      while(!que2.empty()) {
        TreeNode *next = que2.front();
        if (next != nullptr) {
          right_to_left.insert(right_to_left.begin(), next->val);
          que1.push(next->left);
          que1.push(next->right);
        }
        que2.pop();
      }
      if (!right_to_left.empty())
        result.push_back(right_to_left);
    }
    return result;
  }
};
