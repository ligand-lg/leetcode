/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  void aux(TreeNode *root, int sum, vector<int> *tmp) {
    if (root == nullptr)
      return;
    tmp->push_back(root->val);
    if (root->left == nullptr && root->right == nullptr && root->val == sum) {
      res.push_back(*tmp);
      tmp->pop_back();
      return;
    }
    aux(root->left, sum - root->val, tmp);
    aux(root->right, sum - root->val, tmp);
    tmp->pop_back();
  }
  vector<vector<int>> res;
 public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    res = vector<vector<int>>();
    vector<int> tmp;
    aux(root, sum, &tmp);
    return this->res;
  }
};
