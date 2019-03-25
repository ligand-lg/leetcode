/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "leetcode.h"

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left_depth = maxDepth(root->left);
    int righ_depth = maxDepth(root->right);
    return (left_depth > righ_depth ? left_depth : righ_depth) + 1;
  }
};