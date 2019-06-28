/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  TreeNode *aux(vector<int>::iterator in_begin,
                vector<int>::iterator in_end,
                vector<int>::iterator post_begin,
                vector<int>::iterator post_end) {
    if (in_begin >= in_end)
      return nullptr;
    auto root = new TreeNode(*(post_end - 1));
    auto index = find(in_begin, in_end, root->val);
    auto diff = index - in_begin;
    root->left = aux(in_begin, index, post_begin, post_begin + diff);
    root->right = aux(index + 1, in_end, post_begin + diff , post_end - 1);
    return root;
  }

 public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return aux(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
  }
};
