/**
 *
 * T(n) = O(n * log(n) )
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  TreeNode *aux(vector<int>::iterator start, vector<int>::iterator end) {
    if (start >= end)
      return nullptr;
    auto mid = start + (end - start) / 2;
    auto root = new TreeNode(*mid);
    root->left = aux(start, mid);
    root->right = aux(mid + 1, end);
    return root;
  }
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    vector<int> data;
    for (; head != nullptr; head = head->next)
      data.push_back(head->val);
    return aux(data.begin(), data.end());
  }
};
