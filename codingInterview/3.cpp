#include "leetcode.h"

class Solution {
  void helper(vector<int>& r, ListNode* head) {
    if (head == nullptr) return;
    helper(r, head->next);
    r.push_back(head->val);
  }
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> result;
      helper(result, head);
      return result;
    }
};